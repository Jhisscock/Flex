%{ 

/*
 * ========================================================================
 * 
 * Scanner for slic file. Prints out name of the token along with lexeme.
 * 
 * Programmer --- Jacob Hisscock
 * Date --- 10/1/2020
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
"-"|"+"|"*"|"/"|"%"|"<"|"<="|">"|">="|"<>"|"&"|"|"|"~"|"."|"!"|"("|")"|":=" { if (DEBUG) printf(yytext);}

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

[iI][fF]|[wW][hH][iI][lL][eE]|[eE][xX][iI][tT]|[cC][oO][uU][nN][tT][iI][nN][gG]|[uU][pP][wW][aA][rR][dD][sS]|[dD][oO][wW][nN][wW][aA][rR][dD][sS]|[tT][oO]|[eE][lL][sS][eE]|[rR][eE][aA][dD]|[pP][rR][iI][nN][tT] { if (DEBUG) printf(yytext);}

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
                                    return(INTEGER);
                                  }

[rR][eE][aA][lL]                  {
                                    if (DEBUG) printf(yytext);
                                    return(REAL);
                                  }

{INTEGER}                   {
                              if (DEBUG) printf(yytext);
                              return(INTVALUE);
                            }

{ID}                        { 
                              if (DEBUG) printf(yytext);
                              return(ID);
                            }
                            
{REAL}                      { if (DEBUG) printf(yytext);}

{FLOAT}                     { if (DEBUG) printf(yytext);}

{CHAR}                      { if (DEBUG) printf(yytext);}

{COMMMENT}                  { if (DEBUG) printf(yytext);}

{STRING}                    { if (DEBUG) printf(yytext);}

\n           { if (DEBUG) printf(yytext);}

[\t ]+       { if (DEBUG) printf(yytext);}

%%
