#define _GNU_SOURCE // For asprintf
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <ctype.h> // For isspace
#include "codegen.h"

// --- Helpers ---

// Simple string concatenation helper (caller must free result)
char *lstrip(char *s) {
    while(isspace((unsigned char)*s)) s++;
    return s; // Returns pointer to first non-space char
}
char* concat(const char *s1, const char *s2) {
    char *result = malloc(strlen(s1) + strlen(s2) + 1);
    if (!result) { perror("malloc failed in concat"); exit(EXIT_FAILURE); }
    strcpy(result, s1);
    strcat(result, s2);
    return result;
}

// More robust concatenation using asprintf (safer)
char* format_string(const char *format, ...) {
    va_list args;
    char *buffer;
    va_start(args, format);
    if (vasprintf(&buffer, format, args) == -1) {
        perror("vasprintf failed");
        va_end(args);
        exit(EXIT_FAILURE);
    }
    va_end(args);
    return buffer;
}

// Indentation helper
char* indent_code(const char* code) {
    if (!code) return strdup("");
    size_t original_len = strlen(code);
    size_t new_len = original_len;
    int indent_count = 0;

    // Count newlines to estimate extra space needed for tabs
    for (size_t i = 0; i < original_len; ++i) {
        if (code[i] == '\n') {
            indent_count++;
        }
    }
    // Add potential indent for first line if not empty
    if (original_len > 0 && code[0] != '\n') {
         indent_count++;
    }


    // Allocate potentially more space: original + (tabs * indent_level) + null terminator
    // Using a fixed indent of 4 spaces
    new_len += indent_count * 4;
    char *indented = malloc(new_len + 1);
    if (!indented) { perror("malloc failed for indent"); exit(EXIT_FAILURE); }

    char *dest = indented;
    const char *src = code;
    int line_start = 1; // Start with indent unless code is empty

    while (*src) {
        if (line_start) {
            strcpy(dest, "    "); // Add 4 spaces
            dest += 4;
            line_start = 0;
        }
        *dest = *src;
        if (*src == '\n' && *(src + 1) != '\0') { // If newline and not the end
            line_start = 1;
        }
        dest++;
        src++;
    }
    *dest = '\0'; // Null terminate

    return indented;
}


CodeFragment create_code_fragment(const char *code) {
    CodeFragment frag;
    frag.code = strdup(code ? code : ""); // Ensure we always have a valid string
    if (!frag.code) { perror("strdup failed in create_code_fragment"); exit(EXIT_FAILURE); }
    return frag;
}

void free_code_fragment(CodeFragment frag) {
    if (frag.code) {
        free(frag.code);
        frag.code = NULL; // Prevent double free
    }
}

// --- Code Generation Functions ---

CodeFragment gen_initial_imports() {
    return create_code_fragment(
        "import numpy as np\n"
        "import pandas as pd\n"
        "import matplotlib.pyplot as plt\n"
        "# Clustering requires scikit-learn: pip install scikit-learn\n"
        "try:\n"
        "    from sklearn.cluster import KMeans\n"
        "except ImportError:\n"
        "    print('Warning: scikit-learn not found. Clustering features will not work.')\n"
        "    KMeans = None\n\n"
        "# Helper for WizuALL conditionals (non-zero scalar, non-empty/any non-zero vector)\n"
        "def wz_truthy(val):\n"
        "    if isinstance(val, (np.ndarray, list, tuple)):\n"
        "        return len(val) > 0 and np.any(val)\n"
        "    else:\n"
        "        return val != 0\n\n"
    );
}

CodeFragment gen_assignment(const char *py_var_name, CodeFragment expr_code) {
    char* code = format_string("%s = %s\n", py_var_name, expr_code.code);
    CodeFragment frag = create_code_fragment(code);
    free(code);
    return frag;
}
CodeFragment gen_load_csv(const char *filename_str) {
    // Simpler Pandas approach: Read CSV, select numeric columns, convert to NumPy array.
    // Add quotes back around the filename for the Python string literal.
    char* code = format_string(
        "pd.read_csv(\"%s\", header=0).select_dtypes(include=np.number).to_numpy()",
        filename_str);

    CodeFragment frag = create_code_fragment(code);
    free(code); // Free the string created by format_string
    return frag;
}

CodeFragment gen_binary_op(CodeFragment left, const char *op, CodeFragment right) {
    // Let Python/NumPy handle type compatibility (scalar/vector) via operator overloading
    char* code = format_string("(%s %s %s)", left.code, op, right.code);
     CodeFragment frag = create_code_fragment(code);
    free(code);
    return frag;
}

CodeFragment gen_unary_minus(CodeFragment expr) {
     char* code = format_string("(-%s)", expr.code);
     CodeFragment frag = create_code_fragment(code);
    free(code);
    return frag;
}


CodeFragment gen_number_literal(double value) {
    // Check if it's an integer
    if (value == (double)(long long)value) {
         char* code = format_string("%lld", (long long)value);
         CodeFragment frag = create_code_fragment(code);
        free(code);
        return frag;
    } else {
         char* code = format_string("%g", value);
          CodeFragment frag = create_code_fragment(code);
        free(code);
        return frag;
    }
}
CodeFragment gen_get_column(CodeFragment data_expr, CodeFragment index_expr) {
    // Generates Python code like: data_variable[:, int(column_index)]
    // Ensures the index is treated as an integer for slicing.
    char* code = format_string("%s[:, int(%s)]", data_expr.code, index_expr.code);
    CodeFragment frag = create_code_fragment(code);
    free(code);
    return frag;
}

CodeFragment gen_vector_literal(CodeFragment args) {
    // args.code should be "expr1_code, expr2_code, ..."
    char* code = format_string("np.array([%s])", args.code ? args.code : "");
    CodeFragment frag = create_code_fragment(code);
    free(code);
    return frag;
}

CodeFragment gen_variable_access(const char *py_var_name) {
    return create_code_fragment(py_var_name);
}

CodeFragment gen_if(CodeFragment condition, CodeFragment then_branch) {
    char* indented_then = indent_code(then_branch.code);
    char* code = format_string(
        "if wz_truthy(%s):\n%s",
        condition.code,
        indented_then
    );
    CodeFragment frag = create_code_fragment(code);
    free(indented_then);
    free(code);
    return frag;
}

CodeFragment gen_if_else(CodeFragment condition, CodeFragment then_branch, CodeFragment else_branch) {
     char* indented_then = indent_code(then_branch.code);
     char* indented_else = indent_code(else_branch.code);
     char* code = format_string(
        "if wz_truthy(%s):\n%s\nelse:\n%s",
        condition.code,
        indented_then,
        indented_else
    );
     CodeFragment frag = create_code_fragment(code);
    free(indented_then);
    free(indented_else);
    free(code);
    return frag;
}

CodeFragment gen_while(CodeFragment condition, CodeFragment body) {
    char* indented_body = indent_code(body.code);
     char* code = format_string(
        "while wz_truthy(%s):\n%s",
        condition.code,
        indented_body
    );
    CodeFragment frag = create_code_fragment(code);
    free(indented_body);
    free(code);
    return frag;
}

// Append code fragments, handling potential NULLs and adding newlines
CodeFragment gen_statement_list(CodeFragment existing_list, CodeFragment new_statement) {
    if (!new_statement.code || strlen(new_statement.code) == 0) {
        // Freeing new_statement here might be bad if Bison action needs $1 value later
        // Let Bison manage the freeing of $1, $2 etc. usually.
        return existing_list;
    }
    if (!existing_list.code || strlen(existing_list.code) == 0) {
        // Freeing new_statement here might be bad.
        return new_statement; // Return the first statement as is
    }

    // Simple concatenation
    char* code = concat(existing_list.code, new_statement.code);
    CodeFragment frag = create_code_fragment(code);
    free(code);
    free_code_fragment(existing_list); // Free the previous combined list
    // IMPORTANT: Do NOT free new_statement here. Bison actions ($1, $2...) manage their own memory
    // unless you explicitly transfer ownership / copy.
    return frag;
}


CodeFragment gen_block(CodeFragment statements) {
    // Blocks don't add syntax in Python, they just group statements.
    // The caller (if/while) will handle indentation.
    // If the statements already have appropriate newlines, just return them.
    return statements; // Assume statements fragment is correctly formatted list
}


CodeFragment gen_external_call(const char *func_name, CodeFragment args) {
    // Assume func_name is a valid Python function name
    char* code = format_string("%s(%s)\n", func_name, args.code ? args.code : "");
     CodeFragment frag = create_code_fragment(code);
    free(code);
    return frag;
}


// In src/codegen.c

// Restore the simpler version of gen_native_code
CodeFragment gen_native_code(const char* native_text) {
    // Pass native code through, ensuring it ends with a newline for safety
    // when combined with subsequent WizuALL statements.
    if (native_text && strlen(native_text) > 0 && native_text[strlen(native_text)-1] != '\n') {
        char* code = format_string("%s\n", native_text);
        CodeFragment frag = create_code_fragment(code);
        free(code); // Free the formatted string
        // NOTE: We don't free the original native_text, Bison/Lex manages that token value
        return frag;
    } else {
       // Handles null or already newline-terminated string
       // Create a copy if native_text is not null, otherwise empty string
       return create_code_fragment(native_text ? native_text : "");
    }
}

// --- Visualization and Built-ins ---

CodeFragment gen_plot_histogram(CodeFragment vec, CodeFragment bins) {
    char* code = format_string("plt.figure()\nplt.hist(%s, bins=int(%s))\nplt.title('Histogram')\nplt.xlabel('Value')\nplt.ylabel('Frequency')\nplt.show()\n",
                             vec.code, bins.code);
    CodeFragment frag = create_code_fragment(code);
    free(code);
    return frag;
}

CodeFragment gen_plot_scatter(CodeFragment vec_x, CodeFragment vec_y) {
     char* code = format_string("plt.figure()\nplt.scatter(%s, %s)\nplt.title('Scatter Plot')\nplt.xlabel('X')\nplt.ylabel('Y')\nplt.grid(True)\nplt.show()\n",
                              vec_x.code, vec_y.code);
    CodeFragment frag = create_code_fragment(code);
    free(code);
    return frag;
}

CodeFragment gen_plot_xy(CodeFragment vec_x, CodeFragment vec_y) {
      char* code = format_string("plt.figure()\nplt.plot(%s, %s)\nplt.title('XY Plot')\nplt.xlabel('X')\nplt.ylabel('Y')\nplt.grid(True)\nplt.show()\n",
                              vec_x.code, vec_y.code);
    CodeFragment frag = create_code_fragment(code);
    free(code);
    return frag;
}

CodeFragment gen_calculate_stat(const char *stat_func, CodeFragment vec) {
    const char *np_func = "";
    if (strcmp(stat_func, "calculate_average") == 0) np_func = "np.mean";
    else if (strcmp(stat_func, "calculate_max") == 0) np_func = "np.max";
    else if (strcmp(stat_func, "calculate_min") == 0) np_func = "np.min";
    else if (strcmp(stat_func, "calculate_sum") == 0) np_func = "np.sum";
    else {
        fprintf(stderr, "Error: Unknown statistic function '%s'\n", stat_func);
        // Return something valid but maybe identifiable as an error, like 'None'
         return create_code_fragment("None");
    }

    char* code = format_string("%s(%s)", np_func, vec.code);
     CodeFragment frag = create_code_fragment(code);
    free(code);
    return frag;
}


CodeFragment gen_slice_vector(CodeFragment vec, CodeFragment start, CodeFragment end) {
    // Python slicing is end-exclusive, WizuALL doc implies end-inclusive (start to end-1) -> seems pythonic already
    // Need to ensure start/end are integers
     char* code = format_string("%s[int(%s):int(%s)]", vec.code, start.code, end.code);
     CodeFragment frag = create_code_fragment(code);
    free(code);
    return frag;
}


CodeFragment gen_reverse_vector(CodeFragment vec) {
    char* code = format_string("np.flip(%s)", vec.code);
    CodeFragment frag = create_code_fragment(code);
    free(code);
    return frag;
}


CodeFragment gen_find_clusters(CodeFragment data, CodeFragment k) {
    // Assumes data is suitable for KMeans (e.g., numpy array NxD)
    // Reshape if it's a flat vector treated as N x 1
    char* code = format_string(
        "(KMeans(n_clusters=int(%s), n_init=10, random_state=0).fit(np.array(%s).reshape(-1, 1) if np.array(%s).ndim == 1 else np.array(%s)).labels_ if KMeans else None)",
        k.code, data.code, data.code, data.code); // Repeat data.code because C macros aren't used
     CodeFragment frag = create_code_fragment(code);
    free(code);
    return frag;
}