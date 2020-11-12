/*
 * ==========================================================================
 * 
 * checkpoint6.y ----- Syntax tree and function declaration.
 * Programmer --- Jacob Hisscock
 * Date --- 11/12/2020
 * 
 * ==========================================================================
 */

#include <stdio.h>

#ifndef SYNTREE_H
#define SYNTREE_H

//Define code numbers for operations
#define DT_OTHER  0
#define DT_ASSIGN  1

//Define syntax tree. Includes: variable name, operation, value, and the next node in the syntax tree.
struct syntree { 
    char *id;
    int op;
    float value;
    int posistion;
    struct syntree* next; 
}; 

struct syntree *createSTree(char *identifier, int operation, float v, int pos);
struct syntree *displayTree(void);
int expEval();
struct symtable *lookup(struct syntree *node);


#endif