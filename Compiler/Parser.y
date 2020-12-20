%{

/*
 * ==========================================================================
 * 
 * checkpoint8.y ----- Bison parser for the slic language. Added support for 
 					   if/else statements and print statements in algorithm
						section
 * Programmer --- Jacob Hisscock
 * Date --- 12/8/2020
 * 
 * ==========================================================================
 */
 
#include <stdio.h>
#include "symtable.h"
#include "syntree.h"
#include <string.h>

int yyerror();
extern int yylex();
struct symtable* table;
struct syntree* tree;
extern struct symtable* lookupNode(char *identifier);
extern int addressCount;
int lines = 0;
int dt = 0;

%}

%union {
   char *sval;
   int ival;
   float rval;
   struct symtable* tablenode;
   struct syntree* treenode;
   struct expression* expnode;
}

%token <sval> INTEGERV
%token <sval> REALV
%token        MAIN_DEC
%token		  SEMICOLON
%token		  DATA
%token		  COLON
%token		  COMMA
%token		  END
%token        ALGORITHM
%token        LBRACKET
%token        RBRACKET
%token <ival> INTVALUE
%token <rval> REALVALUE
%token <sval> ID
%token 		  ASSIGN
%token		  IF
%token		  ELSE
%token		  PRINT
%token        NTE
%token        GTE
%token        LTE
%token        GT
%token        LT
%token        EQUAL
%token		  LPAREN
%token 		  RPAREN
%token <sval> EXC
%token <sval> STRING
%token		  AND
%token		  OR
%token		  PLUS
%token		  MINUS
%token        MULTIPLY
%token        DIVIDE
%token		  WHILE
%token		  EXIT
%token		  READ
%token		  TO
%token		  DOWNWARDS
%token 		  UPWARDS
%token 		  COUNTING
%token        ENDMAIN

%type <tablenode> init_sec
%type <treenode> outer_stmts
%type <expnode> print_stmt
%type <expnode> exp;
%type <expnode> term;
%type <expnode> factor;
%type <expnode> unit;
%type <expnode> cond_stmt;
%type <expnode> and_or;
%type <expnode> count_stmt;

%%
prog : MAIN_DEC SEMICOLON data_sec alg_sec ENDMAIN SEMICOLON
	  ;

data_sec : DATA COLON init_sec
               {
                  table = $3;
               }
         ;

init_sec : INTEGERV COLON ID COMMA init_sec
               {
                  dt = DT_INT;
                  $$ = malloc(sizeof(struct symtable));
                  $$->id = $3;
                  $$->datatype = dt;
                  $$->address = addressCount;
                  $$->type = TP_SCALAR;
                  $$->size = 1;
                  $$->value = 0.0/0.0;
                  $$->next = $5;
                  $5->datatype = dt;
                  addressCount += 1;
               }
         | REALV COLON ID COMMA init_sec
               {
                  dt = DT_REAL;
                  $$ = malloc(sizeof(struct symtable));
                  $$->id = $3;
                  $$->datatype = dt;
                  $$->address = addressCount;
                  $$->type = TP_SCALAR;
                  $$->size = 1;
                  $$->value = 0.0/0.0;
                  $$->next = $5;
                  $5->datatype = dt;
                  addressCount += 1;
               }
         | INTEGERV COLON ID LBRACKET INTVALUE RBRACKET COMMA init_sec
               {
                  dt = DT_INT;
                  $$ = malloc(sizeof(struct symtable));
                  $$->id = $3;
                  $$->datatype = dt;
                  $$->address = addressCount;
                  $$->type = TP_ARRAY;
                  $$->size = $5;
                  $$->value = 0.0/0.0;
                  $$->next = $8;
                  $8->datatype = dt;
                  addressCount += $5;
               }
         | REALV COLON ID LBRACKET INTVALUE RBRACKET COMMA init_sec
               {
                  dt = DT_REAL;
                  $$ = malloc(sizeof(struct symtable));
                  $$->id = $3;
                  $$->datatype = dt;
                  $$->address = addressCount;
                  $$->type = TP_ARRAY;
                  $$->size = $5;
                  $$->value = 0.0/0.0;
                  $$->next = $8;
                  $8->datatype = dt;
                  addressCount += $5;
               }
         | ID SEMICOLON init_sec
               {
                  $$ = malloc(sizeof(struct symtable));
                  $$->id = $1;
                  $$->datatype = dt;
                  $$->address = addressCount;
                  $$->type = TP_SCALAR;
                  $$->size = 1;
                  $$->value = 0.0/0.0;
                  $$->next = $3;
                  addressCount += 1;
               }
         | ID LBRACKET INTVALUE RBRACKET COMMA init_sec
               {
                  $$ = malloc(sizeof(struct symtable));
                  $$->id = $1;
                  $$->datatype = dt;
                  $$->address = addressCount;
                  $$->type = TP_ARRAY;
                  $$->size = $3;
                  $$->value = 0.0/0.0;
                  $$->next = $6;
                  addressCount += $3;
               }

         | ID SEMICOLON
               {
                  $$ = malloc(sizeof(struct symtable));
                  $$->id = $1;
                  $$->datatype = dt;
                  $$->address = addressCount;
                  $$->type = TP_SCALAR;
                  $$->size = 1;
                  $$->value = 0.0/0.0;
                  addressCount += 1;
               }
         | ID COMMA init_sec
               {
                  $$ = malloc(sizeof(struct symtable));
                  $$->id = $1;
                  $$->datatype = dt;
                  $$->address = addressCount;
                  $$->type = TP_SCALAR;
                  $$->size = 1;
                  $$->next = $3;
                  $3->datatype = dt;
                  $$->value = 0.0/0.0;
                  addressCount += 1;
               }

         | ID LBRACKET INTVALUE RBRACKET SEMICOLON init_sec
               {
                  $$ = malloc(sizeof(struct symtable));
                  $$->id = $1;
                  $$->datatype = dt;
                  $$->address = addressCount;
                  $$->type = TP_ARRAY;
                  $$->size = $3;
                  $$->next = $6;
                  $$->value = 0.0/0.0;
                  addressCount += $3;
               }
         | ID LBRACKET INTVALUE RBRACKET SEMICOLON
               {
                  $$ = malloc(sizeof(struct symtable));
                  $$->id = $1;
                  $$->datatype = dt;
                  $$->address = addressCount;
                  $$->type = TP_ARRAY;
                  $$->size = $3;
                  $$->value = 0.0/0.0;
                  addressCount += $3;
               }
         
         |INTEGERV COLON ID SEMICOLON init_sec
               {
                  dt = DT_INT;
                  $$ = malloc(sizeof(struct symtable));
                  $$->id = $3;
                  $$->datatype = dt;
                  $$->address = addressCount;
                  $$->type = TP_SCALAR;
                  $$->size = 1;
                  $$->value = 0.0/0.0;
                  $$->next = $5;
                  addressCount += 1;
               }
         | REALV COLON ID SEMICOLON init_sec
               {
                  dt = DT_REAL;
                  $$ = malloc(sizeof(struct symtable));
                  $$->id = $3;
                  $$->datatype = dt;
                  $$->address = addressCount;
                  $$->type = TP_SCALAR;
                  $$->size = 1;
                  $$->value = 0.0/0.0;
                  $$->next = $5;
                  addressCount += 1;
               }
         | INTEGERV COLON ID LBRACKET INTVALUE RBRACKET SEMICOLON init_sec
               {
                  dt = DT_INT;
                  $$ = malloc(sizeof(struct symtable));
                  $$->id = $3;
                  $$->datatype = dt;
                  $$->address = addressCount;
                  $$->type = TP_ARRAY;
                  $$->size = $5;
                  $$->value = 0.0/0.0;
                  $$->next = $8;
                  addressCount += $5;
               }
         | REALV COLON ID LBRACKET INTVALUE RBRACKET SEMICOLON init_sec
               {
                  dt = DT_REAL;
                  $$ = malloc(sizeof(struct symtable));
                  $$->id = $3;
                  $$->datatype = dt;
                  $$->address = addressCount;
                  $$->type = TP_ARRAY;
                  $$->size = $5;
                  $$->value = 0.0/0.0;
                  $$->next = $8;
                  addressCount += $5;
               }
         |INTEGERV COLON ID SEMICOLON
               {
                  dt = DT_INT;
                  $$ = malloc(sizeof(struct symtable));
                  $$->id = $3;
                  $$->datatype = dt;
                  $$->address = addressCount;
                  $$->type = TP_SCALAR;
                  $$->size = 1;
                  $$->value = 0.0/0.0;
                  addressCount += 1;
               }
         | REALV COLON ID SEMICOLON
               {
                  dt = DT_REAL;
                  $$ = malloc(sizeof(struct symtable));
                  $$->id = $3;
                  $$->datatype = dt;
                  $$->address = addressCount;
                  $$->type = TP_SCALAR;
                  $$->size = 1;
                  $$->value = 0.0/0.0;
                  addressCount += 1;
               }
         | INTEGERV COLON ID LBRACKET INTVALUE RBRACKET SEMICOLON
               {
                  dt = DT_INT;
                  $$ = malloc(sizeof(struct symtable));
                  $$->id = $3;
                  $$->datatype = dt;
                  $$->address = addressCount;
                  $$->type = TP_ARRAY;
                  $$->size = $5;
                  $$->value = 0.0/0.0;
                  addressCount += $5;
               }
         | REALV COLON ID LBRACKET INTVALUE RBRACKET SEMICOLON
               {
                  dt = DT_REAL;
                  $$ = malloc(sizeof(struct symtable));
                  $$->id = $3;
                  $$->datatype = dt;
                  $$->address = addressCount;
                  $$->type = TP_ARRAY;
                  $$->size = $5;
                  $$->value = 0.0/0.0;
                  addressCount += $5;
               }
         ;

alg_sec : ALGORITHM COLON outer_stmts
               {
                  tree = $3;
               }
        | ALGORITHM COLON
        ;

outer_stmts : IF and_or SEMICOLON outer_stmts
                  {
                     $$ = malloc(sizeof(struct syntree));
                     $$->link = $2;
                     $$->next = $4;
                     $$->id = "if";
                     $$->statement = ST_IF;
                  }
            | ELSE SEMICOLON outer_stmts
                  {
                     $$ = malloc(sizeof(struct syntree));
                     $$->statement = ST_ELSE;
                     $$->id = "else if";
                     $$->next = $3;
                  }
            | END IF SEMICOLON outer_stmts
                  {
                     $$ = malloc(sizeof(struct syntree));
                     $$->statement = ST_ENDIF;
                     $$->id = "end if";
                     $$->next = $4;
                  }
            | END IF SEMICOLON
                  {
                     $$ = malloc(sizeof(struct syntree));
                     $$->id = "end if";
                     $$->statement = ST_ENDIF;
                  }
            | WHILE and_or SEMICOLON outer_stmts
                  {
                     $$ = malloc(sizeof(struct syntree));
                     $$->link = $2;
                     $$->next = $4;
                     $$->id = "while";
                     $$->statement = ST_WHILE;
                  }
            | END WHILE SEMICOLON outer_stmts
                  {
                     $$ = malloc(sizeof(struct syntree));
                     $$->statement = ST_ENDWHILE;
                     $$->id = "end while";
                     $$->next = $4;
                  }
            | END WHILE SEMICOLON
                  {
                     $$ = malloc(sizeof(struct syntree));
                     $$->id = "end while";
                     $$->statement = ST_ENDWHILE;
                  }
            | COUNTING ID count_stmt outer_stmts
                  {
                     $$ = malloc(sizeof(struct syntree));
                     $$->link = $3;
                     $$->next = $4;
                     $$->id = $2;
                     $$->statement = ST_COUNT;
                  }
            | END COUNTING SEMICOLON outer_stmts
                  {
                     $$ = malloc(sizeof(struct syntree));
                     $$->statement = ST_ENDCOUNT;
                     $$->id = "end count";
                     $$->next = $4;
                  }
            | END COUNTING SEMICOLON
                  {
                     $$ = malloc(sizeof(struct syntree));
                     $$->statement = ST_ENDCOUNT;
                     $$->id = "end count";
                  }
            | PRINT print_stmt SEMICOLON outer_stmts
                  {
                     $$ = malloc(sizeof(struct syntree));
                     $$->statement = ST_PRINT;
                     $$->link = $2;
                     $$->next = $4;
                  }
            | PRINT print_stmt SEMICOLON
                  {
                     $$ = malloc(sizeof(struct syntree));
                     $$->statement = ST_PRINT;
                     $$->link = $2;
                  }
            | ID ASSIGN exp SEMICOLON outer_stmts
                  {
                     $$ = malloc(sizeof(struct syntree));
                     $$->id = $1;
                     $$->statement = ST_ASSIGN;
                     $$->link = $3;
                     $$->next = $5;
                     lines += 2;
                  }
            | ID LBRACKET INTVALUE RBRACKET ASSIGN exp SEMICOLON outer_stmts
                  {
                     $$ = malloc(sizeof(struct syntree));
                     $$->id = $1;
                     $$->statement = ST_ASSIGN;
                     $$->position = $3;
                     $$->link = $6;
                     $$->next = $8;
                     lines += 2;
                  }
            | ID LBRACKET ID RBRACKET ASSIGN exp SEMICOLON outer_stmts
                  {
                     $$ = malloc(sizeof(struct syntree));
                     $$->id = $1;
                     $$->statement = ST_ASSIGN;
                     $$->position = (int)lookupNode($3)->value;
                     $$->link = $6;
                     $$->next = $8;
                     lines += 2;
                  }
            | ID ASSIGN exp SEMICOLON
                  {
                     $$ = malloc(sizeof(struct syntree));
                     $$->id = $1;
                     $$->statement = ST_ASSIGN;
                     $$->link = $3;
                     lines += 2;
                  }
            | ID LBRACKET INTVALUE RBRACKET ASSIGN exp SEMICOLON
                  {
                     $$ = malloc(sizeof(struct syntree));
                     $$->id = $1;
                     $$->statement = ST_ASSIGN;
                     $$->position = $3;
                     $$->link = $6;
                  }
            | ID LBRACKET ID RBRACKET ASSIGN exp SEMICOLON
                  {
                     $$ = malloc(sizeof(struct syntree));
                     $$->id = $1;
                     $$->statement = ST_ASSIGN;
                     $$->position = (int)lookupNode($3)->value;
                     $$->link = $6;
                  }
            | EXIT SEMICOLON outer_stmts
                  {
                     $$ = malloc(sizeof(struct syntree));
                     $$->id = "exit";
                     $$->statement = ST_EXIT;
                     $$->next = $3;
                  }
            | EXIT SEMICOLON
                  {
                     $$ = malloc(sizeof(struct syntree));
                     $$->id = "exit";
                     $$->statement = ST_EXIT;
                  }
            | READ ID SEMICOLON outer_stmts
                  {
                     $$ = malloc(sizeof(struct syntree));
                     $$->id = $2;
                     $$->statement = ST_READ;
                     $$->next = $4;
                  }
            | READ ID SEMICOLON
                  {
                     $$ = malloc(sizeof(struct syntree));
                     $$->id = $2;
                     $$->statement = ST_READ;
                  }
            ;

cond_stmt : cond_stmt EQUAL exp
                  {
                     $$ = malloc(sizeof(struct expression));
                     $$->operation = OP_EQUAL;
                     $$->datatype = $1->datatype;
                     $$->l_op = $1;
                     $$->r_op = $3;
                  }
          | cond_stmt NTE exp
                  {
                     $$ = malloc(sizeof(struct expression));
                     $$->operation = OP_NEI;
                     $$->datatype = $1->datatype;
                     $$->l_op = $1;
                     $$->r_op = $3;
                  }
          | cond_stmt GTE exp
                  {
                     $$ = malloc(sizeof(struct expression));
                     $$->operation = OP_GEI;
                     $$->datatype = $1->datatype;
                     $$->l_op = $1;
                     $$->r_op = $3;
                  }
          | cond_stmt GT exp
                  {
                     $$ = malloc(sizeof(struct expression));
                     $$->operation = OP_GTI;
                     $$->datatype = $1->datatype;
                     $$->l_op = $1;
                     $$->r_op = $3;
                  }
          | cond_stmt LTE exp
                  {
                     $$ = malloc(sizeof(struct expression));
                     $$->operation = OP_LEI;
                     $$->datatype = $1->datatype;
                     $$->l_op = $1;
                     $$->r_op = $3;
                  }
          | cond_stmt LT exp
                  {
                     $$ = malloc(sizeof(struct expression));
                     $$->operation = OP_LTI;
                     $$->datatype = $1->datatype;
                     $$->l_op = $1;
                     $$->r_op = $3;
                  }
          | exp
                  {
                     $$ = $1;
                  }
          ;

and_or : LPAREN cond_stmt RPAREN AND and_or
                  {
                     $$ = $2;
                     $$->kind = KI_AND;
                     $$->next = $5; 
                  }
       | LPAREN cond_stmt RPAREN OR and_or
                  {
                     $$ = $2;
                     $$->kind = KI_OR;
                     $$->next = $5; 
                  }
       | LPAREN cond_stmt RPAREN
                  {
                     $$ = $2;
                  }
       | cond_stmt
                  {
                     $$ = $1;
                  }
       ;

count_stmt : DOWNWARDS exp TO exp SEMICOLON
                  {
                     $$ = malloc(sizeof(struct expression));
                     $$->operation = OP_GEI;
                     $$->value = $2->value;
                     $$->l_op = $2;
                     $$->l_op = $4;
                  }
           | UPWARDS exp TO exp SEMICOLON
                  {
                     $$ = malloc(sizeof(struct expression));
                     $$->operation = OP_LEI;
                     $$->value = $2->value;
                     $$->l_op = $2;
                     $$->l_op = $4;
                  }
           ;

print_stmt :EXC COMMA print_stmt
                  {
                     $$ = malloc(sizeof(struct expression));
                     $$->operation = OP_EXC;
                     $$->next = $3;
                     lines++;
                  }
           | EXC
                  {
                     $$ = malloc(sizeof(struct expression));
                     $$->id = "HI";
                     $$->operation = OP_EXC;
                     lines++;
                  }
           | STRING COMMA print_stmt
                  {
                     $$ = malloc(sizeof(struct expression));
                     $$->operation = OP_STR;
                     $$->id = $1;
                     $$->next = $3;
                     for(int i = 1; i < strlen($1) - 1; i++){
                        lines += 2;
                     }
                  }
           | STRING
                  {
                     $$ = malloc(sizeof(struct expression));
                     $$->id = $1;
                     $$->operation = OP_STR;
                     for(int i = 1; i < strlen($1) - 1; i++){
                        lines += 2;
                     }
                  }
           | exp COMMA print_stmt
                  {
                     $$ = $1;
                     $$->next = $3;
                  }
           | exp
                  {
                     $$ = $1;
                  }
           ;

exp : exp PLUS term
         {
            $$ = malloc(sizeof(struct expression));
            $$->operation = OP_ADD;
            $$->l_op = $1;
            $$->r_op = $3;
            lines++;
         }
    | exp MINUS term
         {
            $$ = malloc(sizeof(struct expression));
            $$->operation = OP_SUB;
            $$->l_op = $1;
            $$->r_op = $3;
            lines++;
         }
    | term
         {
            $$ = $1;
         }
    ;

term : term MULTIPLY factor
         {
            $$ = malloc(sizeof(struct expression));
            $$->operation = OP_MUL;
            $$->l_op = $1;
            $$->r_op = $3;
            lines++;
         }
     | term DIVIDE factor
         {
            $$ = malloc(sizeof(struct expression));
            $$->operation = OP_DIV;
            $$->l_op = $1;
            $$->r_op = $3;
            lines++;
         }
     | factor
         {
            $$ = $1;
         }
     ;

factor : MINUS unit
            {
               $$ = malloc(sizeof(struct expression));
               $$->operation = OP_UMI;
               $$->kind = KI_UMI;
               $$->r_op = $2;
               lines++;
            }
       | unit
            {
               $$ = $1;
            }
       ;

unit : LPAREN exp RPAREN
            {
               $$ = $2;
            }
     | INTVALUE
            {
               $$ = malloc(sizeof(struct expression));
               $$->value = $1;
               $$->datatype = 0;
               $$->kind = KI_NUM;
               lines++;
            }
     | REALVALUE
            {
               $$ = malloc(sizeof(struct expression));
               $$->value = $1;
               $$->datatype = 1;
               $$->kind = KI_NUM;
               lines++;
            }
     | ID
            {
               $$ = malloc(sizeof(struct expression));
               $$->id = $1;
               $$->kind = KI_VAR;
               $$->datatype = lookupNode($1)->datatype;
               lines += 2;
            }
     | ID LBRACKET INTVALUE RBRACKET
            {
               $$ = malloc(sizeof(struct expression));
               $$->id = $1;
               $$->position = $3;
               $$->datatype = lookupNode($1)->datatype;
               $$->kind = KI_VAR;
               lines += 2;
            }
      | ID LBRACKET ID RBRACKET
            {
               $$ = malloc(sizeof(struct expression));
               $$->id = $1;
               $$->position = (int)lookupNode($3)->value;
               $$->datatype = lookupNode($1)->datatype;
               $$->kind = KI_VAR;
               lines += 2;
            }
     ;

%%

int yyerror() {
   printf("Called yyerror()\n");
   return  0;
}
