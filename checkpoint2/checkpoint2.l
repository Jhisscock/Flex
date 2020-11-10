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

#include <stdio.h>

%}

INTEGER [+|-]?[0-9]+
FLOAT [+|-]?[0-9]+"."([0-9])*
REAL [+|-]?([0-9]*[.]?[0-9]+|[0-9]+[.]?[0-9])
ID  [a-zA-Z]+[a-zA-Z0-9]*
COMMMENT \#.*
CHAR .
STRING \"(\\.|[^"\\])*\"

%%

[\t ]+                      { printf("white space: %s\n", yytext);}
{INTEGER}                   { printf("integer: %s\n", yytext); }
{REAL}                      { printf("real: %s\n", yytext); }
{FLOAT}                     { printf("float: %s\n", yytext); }
{COMMMENT}                  { printf("comment: %s\n", yytext); }
{STRING}                    { printf("string: %s\n", yytext); }
[mM][aA][iI][nN]|[eE][nN][dD]|[iI][fF]|[wW][hH][iI][lL][eE]|[dD][aA][tT][aA]|[aA][lL][gG][oO][rR][iI][tT][mM]|[eE][xX][iI][tT]|[iI][nN][tT][eE][gG][eE][rR]|[rR][eE][aA][lL]|[cC][oO][uU][nN][tT][iI][nN][gG]|[uU][pP][wW][aA][rR][dD][sS]|[dD][oO][wW][nN][wW][aA][rR][dD][sS]|[tT][oO]|[iI][fF]|[eE][lL][sS][eE]|[rR][eE][aA][dD]|[pP][rR][iI][nN][tT] { printf("reserved word: %s\n", yytext); }
"-"|"+"|"*"|"/"|"%"|"<"|"<="|">"|">="|"<>"|"&"|"|"|"~"|"."|"," { printf("operator: %s\n", yytext); }
":="                        { printf("assignment operator: %s\n", yytext); }
";"                         { printf("end statement operator: %s\n", yytext); }
"!"                         { printf("misc token: %s\n", yytext); }
"("                         { printf("begin function: %s\n", yytext); }
")"                         { printf("end function: %s\n", yytext); }
"["                         { printf("index array begin: %s\n", yytext); }
"]"                         { printf("index array end: %s\n", yytext); }
{ID}                        { printf("indentifier: %s\n", yytext); }
\n                          { printf("NEWLINE: %s\n", yytext);}
{CHAR}                      { printf("character: %s\n", yytext); }

%%

int main()
{
    yylex();
    return 0;
}
