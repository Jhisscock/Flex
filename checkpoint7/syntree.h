/*
 * ==========================================================================
 * 
 * checkpoint7.y ----- Syntax tree and function declaration.
 * Programmer --- Jacob Hisscock
 * Date --- 11/19/2020
 * 
 * ==========================================================================
 */

#include <stdio.h>

#ifndef SYNTREE_H
#define SYNTREE_H

//Define syntax tree. Includes: variable name, operation, value, and the next node in the syntax tree.
struct syntree { 
    char *id;
    int op;
    float value;
    int posistion;
    int conditional;
    struct syntree* next; 
}; 

struct syntree *createSTree(char *identifier, int operation, float v, int pos, int cond);
struct syntree *displayTree(void);
int expEval();
struct symtable *lookup(struct syntree *node);


#endif

/*
Operation defintions:
0 = other
1 = assignment
2 = equals
3 = >=
4 = <=
5 = >
6 = <
7 = not equals
8 = print

Print definitions:
1 = string
2 = newline
3 = id
*/


