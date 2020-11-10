/*
 * ========================================================================
 * 
 * main.c ------- Main program file to run bison parser and scanner
 * 
 * Programmer --- Jacob Hisscock
 * 
 * ========================================================================
 */

#include "y.tab.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
   if (yyparse())
      printf("\nParsing Failed\n");
   else
      printf("\nParsing Success\n");
      
   return 0;
}
