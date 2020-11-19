%{

/*
 * ==========================================================================
 * 
 * checkpoint7.y ----- Bison parser for the slic language. Added support for 
 					   if/else statements and print statements in algorithm
						section
 * Programmer --- Jacob Hisscock
 * Date --- 11/19/2020
 * 
 * ==========================================================================
 */
 
#include <stdio.h>
#include "symtable.h"
#include "syntree.h"
#include "jumppoint.h"

int yyerror();
extern int yylex();
int dtype = -1;
int stmt = 0;
int lines = 2;
extern int adCount;
int elseCheck = 0;
int condNum = 0;
int orLine = 0;
extern int charCount(char* str);

%}

%union {
   char *sval;
   int ival;
   float rval;
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

%%
prog     : main_sec data_sec alg_sec end_sec
         ;

main_sec : MAIN_DEC SEMICOLON
		 ;

data_sec : DATA COLON
		 | DATA COLON dec_stmt_list
		 ;

dec_stmt_list : dec_stmt
			  | dec_stmt_list dec_stmt 
			  ;

dec_stmt : data_type COLON dec_item_list SEMICOLON
		 ;

data_type : INTEGERV
				{
					dtype = DT_INT;
				}
		  | REALV
		  		{
					dtype = DT_REAL;
				}
		  ;

dec_item_list : identifier
			  | dec_item_list COMMA identifier
			  ;

identifier : ID
				{
					createNode($1, dtype, adCount, TP_SCALAR, 1);
					adCount++;
				}
			|ID LBRACKET INTVALUE RBRACKET
				{
					createNode($1, dtype, adCount, TP_ARRAY, $3);
					adCount += $3;
				}
		   ;

alg_sec : ALGORITHM COLON 
		| ALGORITHM COLON alg_stmt_list
		;

alg_stmt_list : alg_stmt
			  | alg_stmt_list alg_stmt
			  ;

alg_stmt : operation
		 | PRINT print_list SEMICOLON
		 | IF if_stmt_list SEMICOLON alg_stmt_list else_stmt alg_stmt_list end_stmt
		 | IF if_stmt_list SEMICOLON alg_stmt_list end_stmt
		 ;

print_list : print_stmt
		   | print_list print_stmt
		   ;
		   
print_stmt : STRING
				{
					createSTree($1, 8, 0, 0, 1);
					lines += charCount($1) * 2;
				}

		   | STRING COMMA
		   		{
					createSTree($1, 8, 0, 0, 1);
					lines += charCount($1) * 2;
				}

		   | ID
		   		{
					createSTree($1, 8, 0, 0, 3);
					lines += 3;
				}

		   | ID COMMA
		   		{
					createSTree($1, 8, 0, 0, 3);
					lines += 3;
				}

		   | EXC
		   		{
					createSTree(NULL, 8, 0, 0, 2);
					lines++;
				}

		   | EXC COMMA
		   		{
					createSTree(NULL, 8, 0, 0, 2);
					lines++;
				}

		   ;

if_stmt_list : if_stmt
		     | if_stmt_list if_stmt
			 ;

if_stmt : LPAREN operation RPAREN
				{
					condNum++;
				}

		| LPAREN operation RPAREN AND
				{
					condNum++;
				}

		| LPAREN operation RPAREN OR
				{
					condNum++;
				}

		;

else_stmt : ELSE SEMICOLON
		  		{
					for(int i = 0; i < condNum; i++){
						push(lines);
					}
					condNum = 0;
					elseCheck = 1;
				}
		  ;

operation : ID ASSIGN INTVALUE SEMICOLON
				{
					createSTree($1, 1, (float)$3, 0, 0);
					lines += 3;
				}

		  | ID ASSIGN REALVALUE SEMICOLON
				{
					createSTree($1, 1, $3, 0, 0);
					lines += 3;
				}

		  | ID LBRACKET INTVALUE RBRACKET ASSIGN INTVALUE SEMICOLON
				{
					createSTree($1, 1, (float)$6, $3, 0);
					lines += 3;
				}
				
		  | ID LBRACKET INTVALUE RBRACKET ASSIGN REALVALUE SEMICOLON
				{
					createSTree($1, 1, $6, $3, 0);
					lines += 3;
				}

		  | ID EQUAL INTVALUE
		  		{
					createSTree($1, 2, (float)$3, 0, 0);
					lines += 5;
				}

		  | ID LBRACKET INTVALUE RBRACKET EQUAL INTVALUE
		  		{
					createSTree($1, 2, (float)$6, $3, 0);
					lines += 5;
				}
		  | ID EQUAL REALVALUE
		  		{
					createSTree($1, 2, $3, 0, 1);
					lines += 5;
				}

		  | ID LBRACKET INTVALUE RBRACKET EQUAL REALVALUE
		  		{
					createSTree($1, 2, $6, $3, 1);
					lines += 5;
				}

		  | ID GTE INTVALUE
		  		{
					createSTree($1, 3, (float)$3, 0, 0);
					lines += 5;
				}

		  | ID LBRACKET INTVALUE RBRACKET GTE INTVALUE
		  		{
					createSTree($1, 3, (float)$6, $3, 0);
					lines += 5;
				}

		  | ID GTE REALVALUE
		  		{
					createSTree($1, 3, $3, 0, 0);
					lines += 5;
				}

		  | ID LBRACKET INTVALUE RBRACKET GTE REALVALUE
		  		{
					createSTree($1, 3, $6, $3, 0);
					lines += 5;
				}

		  | ID LTE INTVALUE
		  		{
					createSTree($1, 4, (float)$3, 0, 0);
					lines += 5;
				}

		  | ID LBRACKET INTVALUE RBRACKET LTE INTVALUE
		  		{
					createSTree($1, 4, (float)$6, $3, 0);
					lines += 5;
				}

		  | ID LTE REALVALUE
		  		{
					createSTree($1, 4, $3, 0, 0);
					lines += 5;
				}

		  | ID LBRACKET INTVALUE RBRACKET LTE REALVALUE
		  		{
					createSTree($1, 4, $6, $3, 0);
					lines += 5;
				}

		  | ID GT INTVALUE
		  		{
					createSTree($1, 5, (float)$3, 0, 0);
					lines += 5;
				}

		  | ID LBRACKET INTVALUE RBRACKET GT INTVALUE
		  		{
					createSTree($1, 5, (float)$6, $3, 0);
					lines += 5;
				}

		  | ID GT REALVALUE
		  		{
					createSTree($1, 5, $3, 0, 0);
					lines += 5;
				}

		  | ID LBRACKET INTVALUE RBRACKET GT REALVALUE
		  		{
					createSTree($1, 5, $6, $3, 0);
					lines += 5;
				}
		  
		  | ID LT INTVALUE
		  		{
					createSTree($1, 6, (float)$3, 0, 0);
					lines += 5;
				}

		  | ID LBRACKET INTVALUE RBRACKET LT INTVALUE
		  		{
					createSTree($1, 6, (float)$6, $3, 0);
					lines += 5;
				}

		  | ID LT REALVALUE
		  		{
					createSTree($1, 6, $3, 0, 0);
					lines += 5;
				}

		  | ID LBRACKET INTVALUE RBRACKET LT REALVALUE
		  		{
					createSTree($1, 6, $6, $3, 0);
					lines += 5;
				}

		  | ID NTE INTVALUE
		  		{
					createSTree($1, 7, (float)$3, 0, 0);
					lines += 5;
				}

		  | ID LBRACKET INTVALUE RBRACKET NTE INTVALUE
		  		{
					createSTree($1, 7, (float)$6, $3, 0);
					lines += 5;
				}

		  | ID NTE REALVALUE
		  		{
					createSTree($1, 7, $3, 0, 0);
					lines += 5;
				}

		  | ID LBRACKET INTVALUE RBRACKET NTE REALVALUE
		  		{
					createSTree($1, 7, $6, $3, 0);
					lines += 5;
				}
		  ;

end_stmt : END IF SEMICOLON
				{
					if(!elseCheck){
						for(int i = 0; i < condNum; i++){
							push(lines);
						}
					}
					condNum = 0;
					elseCheck = 0;
				}
		 ;

end_sec : END MAIN_DEC SEMICOLON 
		;

%%

int yyerror() {
   printf("Called yyerror()\n");
   return  0;
}
