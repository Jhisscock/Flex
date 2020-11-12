%{

/*
 * ==========================================================================
 * 
 * checkpoint6.y ----- Bison parser for the slic language. Added support for 
 					   abstract syntax tree and assignment operation in 
					   algorithm section.
 * Programmer --- Jacob Hisscock
 * Date --- 11/12/2020
 * 
 * ==========================================================================
 */
 
#include <stdio.h>
#include "symtable.h"
#include "syntree.h"

int yyerror();
extern int yylex();
int dtype = -1;
extern int adCount;

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

alg_stmt : ID ASSIGN INTVALUE SEMICOLON
				{
					createSTree($1, 1, (float)$3, 0);
				}
		 | ID ASSIGN REALVALUE SEMICOLON
				{
					createSTree($1, 1, $3, 0);
				}
		 | ID LBRACKET INTVALUE RBRACKET ASSIGN INTVALUE SEMICOLON
				{
					createSTree($1, 1, (float)$6, $3);
				}
		 | ID LBRACKET INTVALUE RBRACKET ASSIGN REALVALUE SEMICOLON
				{
					createSTree($1, 1, $6, $3);
				}
		 ;

end_sec : END MAIN_DEC SEMICOLON 
		;

%%

int yyerror() {
   printf("Called yyerror()\n");
   return  0;
}
