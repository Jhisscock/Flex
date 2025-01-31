/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    INTEGERV = 258,
    REALV = 259,
    MAIN_DEC = 260,
    SEMICOLON = 261,
    DATA = 262,
    COLON = 263,
    COMMA = 264,
    END = 265,
    ALGORITHM = 266,
    LBRACKET = 267,
    RBRACKET = 268,
    INTVALUE = 269,
    REALVALUE = 270,
    ID = 271,
    ASSIGN = 272,
    IF = 273,
    ELSE = 274,
    PRINT = 275,
    NTE = 276,
    GTE = 277,
    LTE = 278,
    GT = 279,
    LT = 280,
    EQUAL = 281,
    LPAREN = 282,
    RPAREN = 283,
    EXC = 284,
    STRING = 285,
    AND = 286,
    OR = 287,
    PLUS = 288,
    MINUS = 289,
    MULTIPLY = 290,
    DIVIDE = 291,
    WHILE = 292,
    EXIT = 293,
    READ = 294,
    TO = 295,
    DOWNWARDS = 296,
    UPWARDS = 297,
    COUNTING = 298
  };
#endif
/* Tokens.  */
#define INTEGERV 258
#define REALV 259
#define MAIN_DEC 260
#define SEMICOLON 261
#define DATA 262
#define COLON 263
#define COMMA 264
#define END 265
#define ALGORITHM 266
#define LBRACKET 267
#define RBRACKET 268
#define INTVALUE 269
#define REALVALUE 270
#define ID 271
#define ASSIGN 272
#define IF 273
#define ELSE 274
#define PRINT 275
#define NTE 276
#define GTE 277
#define LTE 278
#define GT 279
#define LT 280
#define EQUAL 281
#define LPAREN 282
#define RPAREN 283
#define EXC 284
#define STRING 285
#define AND 286
#define OR 287
#define PLUS 288
#define MINUS 289
#define MULTIPLY 290
#define DIVIDE 291
#define WHILE 292
#define EXIT 293
#define READ 294
#define TO 295
#define DOWNWARDS 296
#define UPWARDS 297
#define COUNTING 298

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 40 "checkpoint7.y" /* yacc.c:1909  */

   char *sval;
   int ival;
   float rval;
   struct expression *ex;
   struct mathlist *ml;

#line 148 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
