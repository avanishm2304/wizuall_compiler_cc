%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h> // For strcmp, strdup

#include "symtab.h"    // Symbol table functions
#include "codegen.h"   // Code generation functions

// External declarations from Flex
extern int yylex();
extern char *yytext;
extern int yylineno;
extern FILE *yyin;

// Error handling function
void yyerror(const char *s);

// Global symbol table
SymbolTable *symbol_table;

// Root of the generated code
CodeFragment final_code;

// Bison error count
extern int yynerrs;

%}

/* Bison Value Types */
%union {
    double dval;        /* For numeric literals */
    char *sval;         /* For identifiers, native code, function names */
    CodeFragment code; /* For generated code fragments */
}

/* Token Definitions (Type inferred for literals like '+', ';') */
%token <sval> T_IDENTIFIER T_NATIVE_CODE
%token <dval> T_NUMBER
%token <sval> T_STRING_LITERAL
%token T_IF T_ELSE T_WHILE
%token T_PLOT_HISTOGRAM T_PLOT_SCATTER T_PLOT_XY
%token <sval> T_CALC_STAT // contains "calculate_average", etc.
%token T_SLICE_VECTOR T_REVERSE_VECTOR T_FIND_CLUSTERS
%token T_ASSIGN T_PLUS T_MINUS T_MULTIPLY T_DIVIDE
%token T_LOAD_CSV
%token T_GET_COLUMN
%token T_LPAREN T_RPAREN T_LBRACE T_RBRACE T_LBRACKET T_RBRACKET
%token T_COMMA T_SEMICOLON
%token T_LT T_GT T_LTE T_GTE T_EQ T_NEQ // <-- Added Comparison tokens

/* Non-terminal Types */
%type <code> Program StatementList Statement Block
%type <code> AssignmentStmt IfStmt WhileStmt ExternalCallStmt VisualizationStmt AuxiliaryBlock CsvLoadExpr
%type <code> Expression Term Factor VectorLiteral ArgumentList OptionalArgumentList ComparisonExpr // Added ComparisonExpr
%type <code> CalculateStatsStmt VectorOpStmt ClusterStmt
%type <code> PlotHistogramStmt PlotScatterStmt PlotXYStmt // Added previously

/* Operator Precedence and Associativity */
// Lower precedence = binds less tightly
%left T_LPAREN T_RPAREN T_LBRACKET T_RBRACKET // Grouping/call/access - not really operators, but sets precedence context
%right UMINUS                        // Unary minus (highest operational precedence)
%left T_MULTIPLY T_DIVIDE            // Multiplicative operators
%left T_PLUS T_MINUS                 // Additive operators
%left T_EQ T_NEQ T_LT T_LTE T_GT T_GTE // Comparison operators
%right T_ASSIGN                      // Lowest precedence                  // Unary minus (highest precedence)

/* Grammar Rules */
%%

Program: StatementList
    {
        // Prepend imports to the final code
        CodeFragment imports = gen_initial_imports();
        final_code = gen_statement_list(imports, $1);
        // Code in final_code.code is now ready
        // No need to free imports or $1 here as gen_statement_list handles memory
    }
    ;

StatementList: /* empty */
    { $$ = create_code_fragment(""); }
    | Statement StatementList
    { $$ = gen_statement_list($1, $2); } // Combine statements
    ;

Statement: AssignmentStmt T_SEMICOLON { $$ = $1; }
    | IfStmt                      { $$ = $1; }
    | WhileStmt                   { $$ = $1; }
    | ExternalCallStmt T_SEMICOLON { $$ = $1; }
    | VisualizationStmt T_SEMICOLON { $$ = $1; }
    | Block                       { $$ = $1; }
    | AuxiliaryBlock              { $$ = $1; }
    | error T_SEMICOLON           { yyerrok; $$ = create_code_fragment(""); /* Error recovery */ }
    | T_SEMICOLON                 { $$ = create_code_fragment(""); /* Allow empty statements */ }
    ;


Block: T_LBRACE StatementList T_RBRACE
    { $$ = gen_block($2); } // gen_block might just return $2 if no extra formatting needed
    ;

AuxiliaryBlock: T_NATIVE_CODE
    { $$ = gen_native_code($1); free($1); } // Pass native code through
    ;

AssignmentStmt: T_IDENTIFIER T_ASSIGN Expression
    {
        const char *py_name = symtab_insert(symbol_table, $1); // Get/create Python var name
        $$ = gen_assignment(py_name, $3);
        free($1); // Free WizuALL identifier name string
        free_code_fragment($3); // Free expression code fragment
    }
    | T_IDENTIFIER T_ASSIGN CsvLoadExpr %prec T_ASSIGN // Match precedence
    {
        const char *py_name = symtab_insert(symbol_table, $1);
        // $3 is the CodeFragment from CsvLoadExpr, containing the call to pandas/numpy
        $$ = gen_assignment(py_name, $3);
        free($1); // Free the identifier string
        free_code_fragment($3); // Free the CodeFragment returned by CsvLoadExpr action
    }
    ;

IfStmt: T_IF T_LPAREN Expression T_RPAREN Statement
    {
        $$ = gen_if($3, $5);
        free_code_fragment($3);
        free_code_fragment($5);
    }
    | T_IF T_LPAREN Expression T_RPAREN Statement T_ELSE Statement
    {
        $$ = gen_if_else($3, $5, $7);
        free_code_fragment($3);
        free_code_fragment($5);
        free_code_fragment($7);
    }
    ;

WhileStmt: T_WHILE T_LPAREN Expression T_RPAREN Statement
    {
        $$ = gen_while($3, $5);
        free_code_fragment($3);
        free_code_fragment($5);
    }
    ;

ExternalCallStmt: T_IDENTIFIER T_LPAREN OptionalArgumentList T_RPAREN
    {
        // Check if identifier exists. If so, assume it's a Python function (maybe from aux block)
        // Otherwise, assume it's a direct Python call (like built-ins print())
        const char *py_name = symtab_lookup(symbol_table, $1);
        $$ = gen_external_call(py_name ? py_name : $1, $3); // Use looked-up name or original name
        free($1);
        free_code_fragment($3); // Free combined argument list code
    }
    ;

VisualizationStmt: PlotHistogramStmt
    | PlotScatterStmt
    | PlotXYStmt
    | CalculateStatsStmt
    | VectorOpStmt
    | ClusterStmt
    ;
CsvLoadExpr: T_LOAD_CSV T_LPAREN T_STRING_LITERAL T_RPAREN
    { $$ = gen_load_csv($3); free($3); /* Free the filename string */ }
    ;

PlotHistogramStmt: T_PLOT_HISTOGRAM T_LPAREN Expression T_COMMA Expression T_RPAREN
    { $$ = gen_plot_histogram($3, $5); free_code_fragment($3); free_code_fragment($5); }
    ;

PlotScatterStmt: T_PLOT_SCATTER T_LPAREN Expression T_COMMA Expression T_RPAREN
    { $$ = gen_plot_scatter($3, $5); free_code_fragment($3); free_code_fragment($5); }
    ;

PlotXYStmt: T_PLOT_XY T_LPAREN Expression T_COMMA Expression T_RPAREN
    { $$ = gen_plot_xy($3, $5); free_code_fragment($3); free_code_fragment($5); }
    ;

CalculateStatsStmt: T_IDENTIFIER T_ASSIGN T_CALC_STAT T_LPAREN Expression T_RPAREN
    {
        const char *py_name = symtab_insert(symbol_table, $1);
        CodeFragment stat_call = gen_calculate_stat($3, $5); // $3 is the stat function name ("calculate_average", etc.)
        $$ = gen_assignment(py_name, stat_call);
        free($1); // WizuALL ID
        free($3); // Stat func name string from lexer
        free_code_fragment($5); // Expression code
        free_code_fragment(stat_call);
    }
    ;

VectorOpStmt: T_IDENTIFIER T_ASSIGN T_SLICE_VECTOR T_LPAREN Expression T_COMMA Expression T_COMMA Expression T_RPAREN
    {
        const char *py_name = symtab_insert(symbol_table, $1);
        CodeFragment slice_call = gen_slice_vector($5, $7, $9);
        $$ = gen_assignment(py_name, slice_call);
        free($1);
        free_code_fragment($5); free_code_fragment($7); free_code_fragment($9);
        free_code_fragment(slice_call);
    }
    | T_IDENTIFIER T_ASSIGN T_REVERSE_VECTOR T_LPAREN Expression T_RPAREN
    {
        const char *py_name = symtab_insert(symbol_table, $1);
        CodeFragment reverse_call = gen_reverse_vector($5);
        $$ = gen_assignment(py_name, reverse_call);
        free($1);
        free_code_fragment($5);
        free_code_fragment(reverse_call);
    }
    ;

ClusterStmt: T_IDENTIFIER T_ASSIGN T_FIND_CLUSTERS T_LPAREN Expression T_COMMA Expression T_RPAREN
    {
        const char *py_name = symtab_insert(symbol_table, $1);
        CodeFragment cluster_call = gen_find_clusters($5, $7);
        $$ = gen_assignment(py_name, cluster_call);
        free($1);
        free_code_fragment($5);
        free_code_fragment($7);
        free_code_fragment(cluster_call);
    }
    ;

// --- Expression Hierarchy ---

// Top level expression can be a comparison
Expression: ComparisonExpr     { $$ = $1; }
    // Later: Could add logical operators here (e.g., Expression T_AND Expression)
    ;

// Comparison Expressions (result is typically boolean, generated as Python code)
ComparisonExpr: Term                  { $$ = $1; } // A simple term can be a condition (non-zero check)
    | ComparisonExpr T_LT Term    { $$ = gen_binary_op($1, "<",  $3); free_code_fragment($1); free_code_fragment($3); }
    | ComparisonExpr T_GT Term    { $$ = gen_binary_op($1, ">",  $3); free_code_fragment($1); free_code_fragment($3); }
    | ComparisonExpr T_LTE Term   { $$ = gen_binary_op($1, "<=", $3); free_code_fragment($1); free_code_fragment($3); }
    | ComparisonExpr T_GTE Term   { $$ = gen_binary_op($1, ">=", $3); free_code_fragment($1); free_code_fragment($3); }
    | ComparisonExpr T_EQ Term    { $$ = gen_binary_op($1, "==", $3); free_code_fragment($1); free_code_fragment($3); }
    | ComparisonExpr T_NEQ Term   { $$ = gen_binary_op($1, "!=", $3); free_code_fragment($1); free_code_fragment($3); }
    ;

// Arithmetic Terms (Additive and Multiplicative)
Term: Factor               { $$ = $1; }
    | Term T_PLUS Factor    { $$ = gen_binary_op($1, "+", $3); free_code_fragment($1); free_code_fragment($3); }
    | Term T_MINUS Factor   { $$ = gen_binary_op($1, "-", $3); free_code_fragment($1); free_code_fragment($3); }
    | Term T_MULTIPLY Factor{ $$ = gen_binary_op($1, "*", $3); free_code_fragment($1); free_code_fragment($3); }
    | Term T_DIVIDE Factor  { $$ = gen_binary_op($1, "/", $3); free_code_fragment($1); free_code_fragment($3); }
    ;

// Basic Factors (Operands)
Factor: T_IDENTIFIER
    {
        const char *py_name = symtab_lookup(symbol_table, $1);
        if (!py_name) {
            // Use fprintf for errors, yyerror might try to print yytext which isn't relevant here
            fprintf(stderr, "Error line %d: Undeclared variable '%s'\n", yylineno, $1);
            yynerrs++; // Increment error count manually
            free($1);
            $$ = create_code_fragment("None"); // Return dummy code on error
        } else {
            $$ = gen_variable_access(py_name);
            free($1); // Free WizuALL identifier string
        }
    }
    | T_NUMBER               { $$ = gen_number_literal($1); }
    | VectorLiteral          { $$ = $1; }
    | ExternalCallStmt       { $$ = $1; } /* Functions returning values */
    | T_LPAREN Expression T_RPAREN { $$ = $2; } /* Grouping */
    | T_MINUS Factor %prec UMINUS { $$ = gen_unary_minus($2); free_code_fragment($2); } /* Unary minus */
    | Factor T_LBRACKET Expression T_RBRACKET
    {
        // Generate Python code like vector_code[int(index_code)]
        // Ensure index is treated as integer if necessary by Python slice rules
        char* code_str = format_string("%s[int(%s)]", $1.code, $3.code);
        $$ = create_code_fragment(code_str);
        free(code_str);
        free_code_fragment($1); // Free the vector variable code
        free_code_fragment($3); // Free the index expression code
    }
    | T_GET_COLUMN T_LPAREN Expression T_COMMA Expression T_RPAREN
    {
        // Expression $3 is the data source (e.g., variable name fragment)
        // Expression $5 is the column index fragment
        $$ = gen_get_column($3, $5);
        free_code_fragment($3); // Free fragment used for data arg
        free_code_fragment($5); // Free fragment used for index arg
    }
    ;


VectorLiteral: T_LBRACKET OptionalArgumentList T_RBRACKET
    { $$ = gen_vector_literal($2); free_code_fragment($2); } // Generate np.array([...])
    ;

OptionalArgumentList: /* empty */ { $$ = create_code_fragment(""); }
    | ArgumentList              { $$ = $1; }
    ;

ArgumentList: Expression                  { $$ = $1; } // Single argument
    | ArgumentList T_COMMA Expression { // Changed order for left-recursion & easier combining
        // Combine C strings: $1.code + ", " + $3.code
        char *combined = malloc(strlen($1.code) + strlen($3.code) + 3); // Code1 + ", " + Code3 + \0
        if (!combined) { yyerror("Memory allocation failed for args"); YYABORT; }
        sprintf(combined, "%s, %s", $1.code, $3.code);
        $$ = create_code_fragment(combined);
        free(combined);
        free_code_fragment($1); // Free the code for the list part
        free_code_fragment($3); // Free the code for the new expression part
     }
    ;

%%

/* Error Handling Function */
void yyerror(const char *s) {
    // yytext contains the token that caused the syntax error
    fprintf(stderr, "Syntax Error: %s at line %d near '%s'\n", s, yylineno, yytext);
}