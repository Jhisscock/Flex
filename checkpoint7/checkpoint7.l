%{ 

/*
 * ========================================================================
 * checkpoint7.l --- Scanner for slic file.
 * 
 * Programmer --- Jacob Hisscock
 * Date --- 11/5/2020
 * 
 * ========================================================================
 */

#define  DEBUG 1
#include "y.tab.h"
#include <stdio.h>
#include <string.h>


%}

INTEGER [+|-]?[0-9]+
FLOAT [+|-]?[0-9]+"."([0-9])*
REAL [+|-]?([0-9]*[.]?[0-9]+|[0-9]+[.]?[0-9])
ID  [a-zA-Z]+[a-zA-Z0-9]*
COMMMENT \#.*
CHAR .
STRING \"(\\.|[^"\\])*\"

%%
"-"|"+"|"*"|"/"|"%"|"~"|"." { if (DEBUG) printf(yytext);}

"|"                         {
                              if (DEBUG) printf(yytext);
                              return(OR);
                            }

"&"                         {
                              if (DEBUG) printf(yytext);
                              return(AND);
                            }

"!"                         {
                              if (DEBUG) printf(yytext);
                              return(EXC);
                            }

")"                         {
                              if (DEBUG) printf(yytext);
                              return(RPAREN);
                            }

"("                         {
                              if (DEBUG) printf(yytext);
                              return(LPAREN);
                            }

"<>"                        {
                              if (DEBUG) printf(yytext);
                              return(NTE);
                            }

">="                        {
                              if (DEBUG) printf(yytext);
                              return(GTE);
                            }

">"                         {
                              if (DEBUG) printf(yytext);
                              return(GT);
                            }

"<="                        {
                              if (DEBUG) printf(yytext);
                              return(LTE);
                            }

"<"                         {
                              if (DEBUG) printf(yytext);
                              return(LT);
                            }

"="                         {
                              if (DEBUG) printf(yytext);
                              return(EQUAL);
                            }

":="                        {
                              if (DEBUG) printf(yytext);
                              return(ASSIGN);
                            }

","                         {
                              if (DEBUG) printf(yytext);
                              return(COMMA);
                            }

";"                         {
                              if (DEBUG) printf(yytext);
                              return(SEMICOLON);
                            }

":"                         {
                              if (DEBUG) printf(yytext);
                              return(COLON);
                            }

"["                         {
                              if (DEBUG) printf(yytext);
                              return(LBRACKET);
                            }

"]"                         {
                              if (DEBUG) printf(yytext);
                              return(RBRACKET);
                            }

[wW][hH][iI][lL][eE]|[eE][xX][iI][tT]|[cC][oO][uU][nN][tT][iI][nN][gG]|[uU][pP][wW][aA][rR][dD][sS]|[dD][oO][wW][nN][wW][aA][rR][dD][sS]|[tT][oO]|[rR][eE][aA][dD] { if (DEBUG) printf(yytext);}

[iI][fF]                    {
                              if (DEBUG) printf(yytext);
                              return(IF);
                            }

[eE][lL][sS][eE]            {
                              if (DEBUG) printf(yytext);
                              return(ELSE);
                            }

[pP][rR][iI][nN][tT]        {
                              if (DEBUG) printf(yytext);
                              return(PRINT);
                            }

[mM][aA][iI][nN]            {
                              if (DEBUG) printf(yytext);
                              return(MAIN_DEC);
                            }
                            
[eE][nN][dD]                {
                              if (DEBUG) printf(yytext);
                              return(END);
                            }

[dD][aA][tT][aA]            {
                              if (DEBUG) printf(yytext);
                              return(DATA);
                            }

[aA][lL][gG][oO][rR][iI][tT][hh][mM]  {
                                        if (DEBUG) printf(yytext);
                                        return(ALGORITHM);
                                      }

[iI][nN][tT][eE][gG][eE][rR]      {
                                    if (DEBUG) printf(yytext);
                                    return(INTEGERV);
                                  }

[rR][eE][aA][lL]                  {
                                    if (DEBUG) printf(yytext);
                                    return(REALV);
                                  }

{INTEGER}                   {
                              if (DEBUG) printf(yytext);
                              yylval.ival = atoi((char *)yytext);
                              return(INTVALUE);
                            }

{ID}                        { 
                              if (DEBUG) printf(yytext);
                              yylval.sval = strdup(yytext);
                              return(ID);
                            }
                            
{REAL}                      { if (DEBUG) printf(yytext);
                              yylval.rval = atof((char *)yytext);
                              return(REALVALUE);
                            }

{STRING}                    { 
                              if (DEBUG) printf(yytext);
                              yylval.sval = strdup(yytext);
                              return(STRING);
}                           

{FLOAT}                     { if (DEBUG) printf(yytext);}

{CHAR}                      { if (DEBUG) printf(yytext);}

{COMMMENT}                  { if (DEBUG) printf(yytext);}

\n           { if (DEBUG) printf(yytext);}

[\t ]+       { if (DEBUG) printf(yytext);}

%%
