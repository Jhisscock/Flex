/*
 * ========================================================================
 * 
 * symtable.h ---- Defines structure for symbol table to store variables.
 * 
 * Programmer --- Jacob Hisscock
 * Date --- 12/10/2020
 * 
 * ========================================================================
 */

#include <stdio.h>

#ifndef SYMTABLE_H
#define SYMTABLE_H

//Define code numbers for data types and misc types (array)
#define DT_INT   0
#define DT_REAL  1

//Define type numbers
#define TP_SCALAR   0
#define TP_ARRAY  1

//Define symbol table.
struct symtable { 
    char *id;
    int datatype;
    int address;
    int type;
    int size;
    float value;
    struct symtable* next; 
};

extern struct symtable *table;
void displayTable();
struct symtable* lookupNode(char *identifier);
#endif