#include <stdio.h>
#include <stdlib.h>
#include "codegen.h"  
#include "wizuall.tab.h" // For yylex, yyparse
#include "symtab.h"    // For symbol table mgmt
 // For final_code access

// Make symbol table global for access by parser actions
extern SymbolTable *symbol_table;
// Make final generated code global for access after parsing
extern CodeFragment final_code;

// Flex uses yyin for input
extern FILE *yyin;
// Bison uses yynerrs to count syntax errors
extern int yynerrs;

int main(int argc, char *argv[]) {
    if (argc < 2 || argc > 3) {
        fprintf(stderr, "Usage: %s <input.wiz> [output.py]\n", argv[0]);
        return 1;
    }

    const char *input_filename = argv[1];
    const char *output_filename = (argc == 3) ? argv[2] : NULL;

    // --- Input File ---
    yyin = fopen(input_filename, "r");
    if (!yyin) {
        perror("Error opening input file");
        return 1;
    }

    // --- Initialization ---
    symbol_table = create_symbol_table();
    final_code = create_code_fragment(""); // Initialize empty code

    // --- Parsing and Code Generation ---
    printf("Compiling %s...\n", input_filename);
    int parse_result = yyparse(); // This calls yylex and runs parser actions

    fclose(yyin); // Close input file

    // --- Check for Errors ---
    if (parse_result != 0 || yynerrs > 0) {
        fprintf(stderr, "Compilation failed with %d syntax error(s).\n", yynerrs);
        free_symbol_table(symbol_table);
        free_code_fragment(final_code);
        return 1; // Indicate failure
    }

    // --- Output ---
    FILE *outfile = stdout; // Default to stdout
    if (output_filename) {
        outfile = fopen(output_filename, "w");
        if (!outfile) {
            perror("Error opening output file");
            // Don't exit, just fallback to stdout? Or maybe should exit.
             fprintf(stderr, "Writing output to standard output instead.\n");
             outfile = stdout;
        } else {
             printf("Writing Python code to %s\n", output_filename);
        }
    } else {
         printf("Writing Python code to standard output.\n");
    }


    if (final_code.code) {
        fprintf(outfile, "%s", final_code.code);
    } else {
        fprintf(stderr, "Warning: No code generated.\n");
    }


    if (outfile != stdout) {
        fclose(outfile);
    }

    // --- Cleanup ---
    free_symbol_table(symbol_table);
    free_code_fragment(final_code);

    printf("Compilation successful.\n");
    return 0; // Indicate success
}