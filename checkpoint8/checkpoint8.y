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
#include "jumppoint.h"

int yyerror();
extern int yylex();
extern int adCount;
extern int charCount(char* str);
extern struct mathlist* rootMath;
extern struct symtable *lookup(struct syntree *treeNode);
int dtype = -1;
int stmt = 0;
int lines = 2;
char* idVal = NULL;
int elseCheck = 0;
int condNum = 0;
int orLine = 0;
int andor = -1;
int whilecount = 0;
int elsehit = 0;
int whileArray[128];

%}

%union {
   char *sval;
   int ival;
   float rval;
   struct expression *ex;
   struct mathlist *ml;
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

%type <ex> exp
%type <ex> count_stmt
%type <ml> factor
%type <ml> term
%type <ml> math

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
			|ID LBRACKET exp RBRACKET
				{
					createNode($1, dtype, adCount, TP_ARRAY, (int)$3->value);
					adCount += (int)$3->value;
				}
		   ;

alg_sec : ALGORITHM COLON 
		| ALGORITHM COLON alg_stmt_list
		;

alg_stmt_list : alg_stmt
			  | alg_stmt_list alg_stmt
			  ;

alg_stmt : PRINT print_list SEMICOLON
		 | WHILE while_stmt_list SEMICOLON alg_stmt_list end_stmt
		 | IF if_stmt_list SEMICOLON alg_stmt_list else_stmt alg_stmt_list end_stmt
		 | IF if_stmt_list SEMICOLON alg_stmt_list end_stmt
		 | COUNTING count_stmt alg_stmt_list end_stmt
		 | operation
		 ;

print_list : print_stmt
		   | print_list print_stmt
		   ;
		   
print_stmt : STRING
				{
					struct expression *pr = malloc(sizeof(struct expression));
					pr->value = 0;
					pr->op = 8;
					createSTree($1, pr, 0, 1, andor);
					lines += charCount($1) * 2;
				}

		   | STRING COMMA
		   		{
					struct expression *pr = malloc(sizeof(struct expression));
					pr->value = 0;
					pr->op = 8;
					createSTree($1, pr, 0, 1, andor);
					lines += charCount($1) * 2;
				}

		   | ID
		   		{
					struct expression *pr = malloc(sizeof(struct expression));
					pr->value = 0;
					pr->op = 8;
					createSTree($1, pr, 0, 3, andor);
					lines += 3;
				}

		   | ID COMMA
		   		{
					struct expression *pr = malloc(sizeof(struct expression));
					pr->value = 0;
					pr->op = 8;
					createSTree($1, pr, 0, 3, andor);
					lines += 3;
				}
			| ID LBRACKET INTVALUE RBRACKET
		   		{
					struct expression *pr = malloc(sizeof(struct expression));
					pr->value = 0;
					pr->op = 8;
					createSTree($1, pr, $3, 3, andor);
					lines += 3;
				}

		   | ID LBRACKET INTVALUE RBRACKET COMMA
		   		{
					struct expression *pr = malloc(sizeof(struct expression));
					pr->value = 0;
					pr->op = 8;
					createSTree($1, pr, $3, 3, andor);
					lines += 3;
				}

		   | EXC
		   		{
					struct expression *pr = malloc(sizeof(struct expression));
					pr->value = 0;
					pr->op = 8;
					createSTree(NULL, pr, 0, 2, andor);
					lines++;
				}

		   | EXC COMMA
		   		{
					struct expression *pr = malloc(sizeof(struct expression));
					pr->value = 0;
					pr->op = 8;
					createSTree(NULL, pr, 0, 2, andor);
					lines++;
				}

		   ;

else_stmt : ELSE SEMICOLON
		  		{
					if(elseCheck == 0){
						push(lines + 1);
						lines++;
						elseCheck = 1;
					}
				}
		  ;

if_stmt_list : if_stmt
		     | if_stmt if_stmt_list 
			 ;

if_stmt : LPAREN operation RPAREN OR
				{
					andor = 1;
					condNum++;
					push(lines + 5);
				}
		|LPAREN operation RPAREN
				{
					andor = -1;
					condNum++;
				}

		| LPAREN operation RPAREN AND
				{
					andor = 0;
					condNum++;
				}
		;

while_stmt_list : while_stmt
		     	| while_stmt while_stmt_list 
			 	;

while_stmt : LPAREN operation RPAREN OR
				{
					andor = 1;
					condNum++;
					push(lines + 5);
					whileArray[whilecount] = lines - 6;
					whilecount++;
				}
			|LPAREN operation RPAREN
				{
					andor = -1;
					condNum++;
					whileArray[whilecount] = lines - 6;
					whilecount++;
				}

			| LPAREN operation RPAREN AND
				{
					andor = 0;
					condNum++;
					whileArray[whilecount] = lines - 6;
					whilecount++;
				}
			| operation
				{
					andor = -1;
					condNum++;
					whileArray[whilecount] = lines - 6;
					whilecount++;
				}
			;

count_stmt : ID DOWNWARDS INTVALUE TO INTVALUE SEMICOLON
					{
						$$ = (struct expression*)malloc(sizeof(struct expression));
						$$->value = (float)$3;
						$$->op = 1;
						createSTree($1, $$, 0, 0, 0);
						lines += 3;
						struct expression* tmp= (struct expression*)malloc(sizeof(struct expression));
						tmp->value = (float)$5;
						tmp->op = 3;
						createSTree($1, tmp, 0, 0, 0);
						lines += 4;
					}
		   | ID UPWARDS INTVALUE TO INTVALUE SEMICOLON
		   			{
						struct expression* tmp = (struct expression*)malloc(sizeof(struct expression));
						tmp->value = (float)$3;
						tmp->op = 1;
						createSTree($1, tmp, 0, $5, 0);
					}
		   ;

operation : ID exp SEMICOLON
				{
					if(elseCheck == 1){
						createSTree($1, $2, 0, 4, andor);
						elseCheck = 0;
					}else{
						createSTree($1, $2, 0, 0, andor);
					}
					rootMath = NULL;
				}
		  |ID LBRACKET INTVALUE RBRACKET exp SEMICOLON
				{
					if(elseCheck == 1){
						createSTree($1, $5, $3, 4, andor);
						elseCheck = 0;
					}else{
						createSTree($1, $5, $3, 0, andor);
					}
					rootMath = NULL;
				}
		  |ID exp
		  		{
					if(elseCheck == 1){
						createSTree($1, $2, 0, 4, andor);
						elseCheck = 0;
					}else{
						createSTree($1, $2, 0, 0, andor);
					}
					rootMath = NULL;
				}

		  |ID LBRACKET INTVALUE RBRACKET exp
		  		{
					if(elseCheck == 1){
						createSTree($1, $5, $3, 4, andor);
						elseCheck = 0;
					}else{
						createSTree($1, $5, $3, 0, andor);
					}
					rootMath = NULL;
				}
		  |exp
		  ;

exp : NTE math
			{
				$$ = malloc(sizeof(struct expression));
				$$->value = $2->value;
				$$->op = 7;
				$$->link = $2;
				lines += 5;
			}
	|LT math
			{
				$$ = malloc(sizeof(struct expression));
				$$->value = $2->value;
				$$->op = 6;
				$$->link = $2;
				lines += 5;
			}
	|GT math
			{
				$$ = malloc(sizeof(struct expression));
				$$->value = $2->value;
				$$->op = 5;
				$$->link = $2;
				lines += 5;
			}
	|LTE math
			{
				$$ = malloc(sizeof(struct expression));
				$$->value = $2->value;
				$$->op = 4;
				$$->link = $2;
				lines += 5;
			}
	|GTE math
			{
				$$ = malloc(sizeof(struct expression));
				$$->value = $2->value;
				$$->op = 3;
				$$->link = $2;
				lines += 5;
			}
	|EQUAL math
			{
				$$ = malloc(sizeof(struct expression));
				$$->value = $2->value;
				$$->op = 2;
				$$->link = $2;
				lines += 5;
			}
	|ASSIGN math
			{
				$$ = malloc(sizeof(struct expression));
				$$->value = $2->value;
				$$->op = 1;
				$$->link = $2;
				lines += 3;
			}
	
	|factor
			{
				$$ = malloc(sizeof(struct expression));
				$$->value = $1->value;
				$$->op = 1;
			}
	;

math :math PLUS term
			{
				$$ = malloc(sizeof(struct mathlist));
				$$->op = 9;
				$$->lop = $1;
				$$->rop = $3;
				lines += 2;
			}
	|math MINUS term
			{
				$$ = malloc(sizeof(struct mathlist));
				$$->op = 10;
				$$->rop = $1;
				$$->lop = $3;
				lines += 2;
			}
	|term
	 		{
				$$ = $1;
		 	}
	 ;

term : term DIVIDE factor
			{
				$$ = malloc(sizeof(struct mathlist));
				$$->op = 11;
				$$->rop = $1;
				$$->lop = $3;
				lines += 2;
			}
	 |term MULTIPLY factor
			{
				$$ = malloc(sizeof(struct mathlist));
				$$->op = 12;
				$$->lop = $1;
				$$->rop = $3;
				lines += 2;
			}
	 |factor
	 		{
				$$ = $1;
			}
	 ;

factor : INTVALUE
			{
				$$ = malloc(sizeof(struct mathlist));
				$$->value = (float)$1;
				$$->isVar = 0;
			}
		|REALVALUE
			{
				$$ = malloc(sizeof(struct mathlist));
				$$->value = $1;
				$$->isVar = 0;
			}
		|ID 
			{
				struct syntree* tmp = (struct syntree*)malloc(sizeof(struct syntree));
				tmp->id = $1;
				$$ = malloc(sizeof(struct mathlist));
				$$->value = lookup(tmp)->address;
				$$->isVar = 1;
				lines += 1;
			}
		|ID LBRACKET INTVALUE RBRACKET
			{
				struct syntree* tmp = (struct syntree*)malloc(sizeof(struct syntree));
				tmp->id = $1;
				$$ = malloc(sizeof(struct mathlist));
				$$->value = lookup(tmp)->address + $3;
				$$->isVar = 1;
				lines += 1;
			}
		;


end_stmt : END IF SEMICOLON
				{
					for(int i = 0; i < condNum; i++){
						push(lines);
					}
					condNum = 0;
					elseCheck = 0;
				}
		 | END WHILE SEMICOLON
		 		{
					for(int i = 0; i < condNum; i++){
						push(lines + 1);
					}
					condNum = 0;
					elseCheck = 0;
					lines++;
					struct expression* tmp = (struct expression*)malloc(sizeof(struct expression));
					tmp->value = (float)whileArray[whilecount - 1];
					tmp->op = 13;
					createSTree(NULL, tmp, 0, 5, 0);
				}
		 
		 | END COUNTING SEMICOLON
		 ;

end_sec : END MAIN_DEC SEMICOLON 
		;

%%

int yyerror() {
   printf("Called yyerror()\n");
   return  0;
}
