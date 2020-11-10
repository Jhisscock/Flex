%{

/*
 * ========================================================================
 * 
 * checkpoint4.y ----- Bison parser for the slic language minus the algoithm
 * 						section.
 * Programmer --- Jacob Hisscock
 * 
 * ========================================================================
 */
 
#include <stdio.h>

int yyerror();
extern int yylex();

%}

%union {
   char *sval;
   int *ival;
}

%token		  INTEGER
%token        MAIN_DEC
%token		  SEMICOLON
%token		  DATA
%token		  COLON
%token		  COMMA
%token		  REAL
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

data_type : INTEGER
		  | REAL
		  ;

dec_item_list : dec_item
			  | dec_item_list COMMA dec_item
			  ;

dec_item : identifier
		 | identifier LBRACKET INTVALUE RBRACKET
		 ;

identifier : ID
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
