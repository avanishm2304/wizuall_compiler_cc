#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symtab.h"

SymbolTable* create_symbol_table() {
    SymbolTable *table = (SymbolTable*) malloc(sizeof(SymbolTable));
    if (!table) {
        perror("Failed to allocate symbol table");
        exit(EXIT_FAILURE);
    }
    table->head = NULL;
    return table;
}

void free_symbol_table(SymbolTable *table) {
    if (!table) return;
    Symbol *current = table->head;
    Symbol *next;
    while (current != NULL) {
        next = current->next;
        free(current->name);
        free(current->py_name);
        free(current);
        current = next;
    }
    free(table);
}

const char* symtab_insert(SymbolTable *table, const char *name) {
    Symbol *current = table->head;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            // Variable already exists, return its Python name
            return current->py_name;
        }
        current = current->next;
    }

    // Variable does not exist, create a new entry
    Symbol *new_symbol = (Symbol*) malloc(sizeof(Symbol));
    if (!new_symbol) {
        perror("Failed to allocate symbol entry");
        exit(EXIT_FAILURE); // Or handle error differently
    }
    new_symbol->name = strdup(name);
    // For simplicity, use the same name in Python for now
    // Could add prefix/mangling if needed: e.g., sprintf(buffer, "wz_%s", name);
    new_symbol->py_name = strdup(name);
    new_symbol->next = table->head;
    table->head = new_symbol;

    if (!new_symbol->name || !new_symbol->py_name) {
        perror("Failed to duplicate symbol name strings");
        // Partial allocation cleanup might be needed here
        exit(EXIT_FAILURE);
    }

    return new_symbol->py_name;
}


const char* symtab_lookup(SymbolTable *table, const char *name) {
    Symbol *current = table->head;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            return current->py_name; // Found
        }
        current = current->next;
    }
    return NULL; // Not found
}