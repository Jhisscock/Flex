/*
 * ==========================================================================
 * 
 * checkpoint8.y ----- Syntax tree and function declaration.
 * Programmer --- Jacob Hisscock
 * Date --- 12/8/2020
 * 
 * ==========================================================================
 */

#include <stdio.h>

#ifndef SYNTREE_H
#define SYNTREE_H

//Define syntax tree. Includes: variable name, operation, value, and the next node in the syntax tree.
struct syntree { 
    char *id;
    int posistion;
    int conditional;
    int andor;
    struct expression* exp;
    struct syntree* next; 
};

struct expression{
    int op;
    float value;
    struct mathlist* link;
};

struct mathlist{
    int op;
    float value;
    int isVar;
    struct mathlist* lop;
    struct mathlist* rop;
};

struct evalstack{
    int op;
    float value;
    int isVar;
    struct evalstack* next;
};

struct evaldata{
    int op;
    float value;
    int isVar;
};

struct syntree *createSTree(char *identifier, struct expression *ex, int pos, int cond, int ar);
struct syntree *displayTree(void);
int expEval();
struct symtable *lookup(struct syntree *node);

void displayML(struct mathlist* root);
void EvalML(struct mathlist* root);
void GenerateOperations(float value, int op, int isVar, int datatype, FILE* fp);

void PushEval(int operator, float v, int var);
struct evaldata* PopEval();
void DisplayEval();


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
9 = +;
10 = -;
11 = /;
12 = *;
13 = end while;

Conditional definitions:
1 = string
2 = newline
3 = id
4 = else
5 = while
*/


