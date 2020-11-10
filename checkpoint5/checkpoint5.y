%{

/*
 * ==========================================================================
 * 
 * checkpoint5.y ----- Bison parser for the slic language minus the algorithm
 * 						section. Added support for symbol table.
 * Programmer --- Jacob Hisscock
 * Date --- 11/5/2020
 * 
 * ==========================================================================
 */
 
#include <stdio.h>
#include "symtable.h"

int yyerror();
extern int yylex();
int dtype = -1;
int ad = 0;
int tp = -1;
int sz = 0;

%}

%union {
   char *sval;
   int ival;
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
%token <sval> ID

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

dec_item_list : dec_item
			  | dec_item_list COMMA dec_item
			  ;

dec_item : identifier
				{
					tp = TP_NONE;
					sz = 0;
				}
		 | identifier LBRACKET INTVALUE RBRACKET
		 		{
					 tp = TP_ARRAY;
					 sz = $3;
				}
		 ;

identifier : ID
				{
					createNode($1, dtype, ad, tp, sz);
					ad++;
				}
		   ;

alg_sec : ALGORITHM COLON 
		;

end_sec : END MAIN_DEC SEMICOLON 
		;

%%

int yyerror() {
   printf("Called yyerror()\n");
   return  0;
}
