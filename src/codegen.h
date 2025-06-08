#ifndef CODEGEN_H
#define CODEGEN_H

// Structure to hold generated code string and potentially type info
typedef struct CodeFragment {
    char *code;
    // Add type if needed for checking: enum { SCALAR, VECTOR, UNKNOWN } type;
} CodeFragment;

// Helper to create a CodeFragment
CodeFragment create_code_fragment(const char *code);

// Helper to free a CodeFragment's allocated memory
void free_code_fragment(CodeFragment frag);
char* format_string(const char *format, ...);

// Code Generation Function Prototypes
CodeFragment gen_initial_imports();
CodeFragment gen_assignment(const char *py_var_name, CodeFragment expr_code);
CodeFragment gen_binary_op(CodeFragment left, const char *op, CodeFragment right);
CodeFragment gen_unary_minus(CodeFragment expr);
CodeFragment gen_number_literal(double value);
CodeFragment gen_vector_literal(CodeFragment args); // args is comma-separated list of expressions
CodeFragment gen_variable_access(const char *py_var_name);
CodeFragment gen_if(CodeFragment condition, CodeFragment then_branch);
CodeFragment gen_if_else(CodeFragment condition, CodeFragment then_branch, CodeFragment else_branch);
CodeFragment gen_while(CodeFragment condition, CodeFragment body);
CodeFragment gen_statement_list(CodeFragment existing_list, CodeFragment new_statement);
CodeFragment gen_block(CodeFragment statements);
CodeFragment gen_external_call(const char *func_name, CodeFragment args); // For non-builtin functions
CodeFragment gen_native_code(const char* native_text);

// Visualization and Built-ins
CodeFragment gen_plot_histogram(CodeFragment vec, CodeFragment bins);
CodeFragment gen_plot_scatter(CodeFragment vec_x, CodeFragment vec_y);
CodeFragment gen_plot_xy(CodeFragment vec_x, CodeFragment vec_y);
CodeFragment gen_calculate_stat(const char *stat_func, CodeFragment vec); // "mean", "max", "min", "sum"
CodeFragment gen_slice_vector(CodeFragment vec, CodeFragment start, CodeFragment end);
CodeFragment gen_reverse_vector(CodeFragment vec);
CodeFragment gen_find_clusters(CodeFragment data, CodeFragment k);
CodeFragment gen_get_column(CodeFragment data_expr, CodeFragment index_expr);
CodeFragment gen_load_csv(const char *filename_str);

#endif // CODEGEN_H