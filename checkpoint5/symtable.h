/*
 * ==========================================================================
 * 
 * checkpoint5.y ----- Symbol table and function declaration.
 * Programmer --- Jacob Hisscock
 * Date --- 11/5/2020
 * 
 * ==========================================================================
 */

#include <stdio.h>

#ifndef SYMTABLE_H
#define SYMTABLE_H

//Define code numbers for data types and misc types (array)
#define DT_INT   0
#define DT_REAL  1
#define TP_NONE   0
#define TP_ARRAY  1

//Define symbol table. Includes: variable name, data type, address, type, size, and pointer to the next object in the symtable.
struct symtable { 
    char *id;
    int datatype;
    int address;
    char *type;
    int size;
    struct symtable* next; 
}; 

//Define two functions to be used in main to create a node in the symbol table and a function to display the symbol table.
struct symtable *createNode(char *identifier, int dt, int ad, int type, int sz);
struct symtable *display(void);


#endif