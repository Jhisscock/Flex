/*
 * ========================================================================
 * 
 * symtable.h ---- Defines structure for syntax tree to store a multititude
 *                 of different operations, statements, and expressions.
 * 
 * Programmer --- Jacob Hisscock
 * Date --- 12/10/2020
 * 
 * ========================================================================
 */
#include <stdio.h>

#ifndef SYNTREE_H
#define SYNTREE_H

//Define operation numbers
#define OP_ADD 1
#define OP_SUB 2
#define OP_MUL 3
#define OP_DIV 4
#define OP_UMI 5
#define OP_EXC 6
#define OP_STR 7
#define OP_EQUAL 8
#define OP_NEI 9
#define OP_GEI 10
#define OP_GTI 11
#define OP_LEI 12
#define OP_LTI 13
#define OP_UPWARDS 14
#define OP_DOWNWARDS 15

//Define statement numbers
#define ST_ASSIGN 0
#define ST_PRINT 1
#define ST_IF 2
#define ST_ELSE 3
#define ST_ENDIF 4
#define ST_WHILE 5
#define ST_ENDWHILE 6
#define ST_EXIT 7
#define ST_COUNT 8
#define ST_ENDCOUNT 9
#define ST_READ 10

//Define kind numbers
#define KI_UMI 0
#define KI_NUM 1
#define KI_VAR 2
#define KI_AND 3
#define KI_OR 4
#define KI_NOTAO 5


//Define symbol table
struct syntree { 
    char* id;
    int statement;
    int position;
    struct expression* link;
    struct syntree* next;
};

//Define expression table
struct expression{
    float value;
    int operation;
    int kind;
    char* id;
    int position;
    int datatype;
    struct expression* l_op;
    struct expression* r_op;
    struct expression* next;
};

extern struct syntree *tree;
void displayTree();
void displayExpression(struct expression* root);
void GenExpression(struct expression* root, int datatype);
float evalExpression(struct expression* root);
#endif