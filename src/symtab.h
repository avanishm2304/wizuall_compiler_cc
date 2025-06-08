#ifndef SYMTAB_H
#define SYMTAB_H

// Basic Symbol Table Entry
typedef struct Symbol {
    char *name;         // WizuALL variable name
    char *py_name;      // Corresponding Python variable name (could be same as name)
    // Add type info if needed later (e.g., SCALAR, VECTOR)
    struct Symbol *next;
} Symbol;

// Simple Symbol Table (Global Scope)
typedef struct {
    Symbol *head;
} SymbolTable;

// Function Prototypes
SymbolTable* create_symbol_table();
void free_symbol_table(SymbolTable *table);

// Inserts or updates a symbol. Returns the Python name.
// Generates a unique Python name if needed (e.g., prefixing).
const char* symtab_insert(SymbolTable *table, const char *name);

// Looks up a symbol. Returns the Python name or NULL if not found.
const char* symtab_lookup(SymbolTable *table, const char *name);

#endif // SYMTAB_H