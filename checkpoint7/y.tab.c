/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "checkpoint7.y" /* yacc.c:339  */


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


#line 105 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
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
#line 40 "checkpoint7.y" /* yacc.c:355  */

   char *sval;
   int ival;
   float rval;
   struct expression *ex;
   struct mathlist *ml;

#line 239 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 256 "y.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   202

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  44
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  27
/* YYNRULES -- Number of rules.  */
#define YYNRULES  75
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  143

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   298

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    97,    97,   100,   103,   104,   107,   108,   111,   114,
     118,   124,   125,   128,   133,   140,   141,   144,   145,   148,
     149,   150,   151,   152,   153,   156,   157,   160,   169,   178,
     187,   195,   204,   213,   222,   233,   243,   244,   247,   253,
     259,   266,   267,   270,   278,   286,   293,   302,   315,   324,
     334,   344,   355,   365,   368,   376,   384,   392,   400,   408,
     416,   425,   433,   441,   449,   455,   463,   471,   477,   483,
     489,   498,   510,   518,   532,   535
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INTEGERV", "REALV", "MAIN_DEC",
  "SEMICOLON", "DATA", "COLON", "COMMA", "END", "ALGORITHM", "LBRACKET",
  "RBRACKET", "INTVALUE", "REALVALUE", "ID", "ASSIGN", "IF", "ELSE",
  "PRINT", "NTE", "GTE", "LTE", "GT", "LT", "EQUAL", "LPAREN", "RPAREN",
  "EXC", "STRING", "AND", "OR", "PLUS", "MINUS", "MULTIPLY", "DIVIDE",
  "WHILE", "EXIT", "READ", "TO", "DOWNWARDS", "UPWARDS", "COUNTING",
  "$accept", "prog", "main_sec", "data_sec", "dec_stmt_list", "dec_stmt",
  "data_type", "dec_item_list", "identifier", "alg_sec", "alg_stmt_list",
  "alg_stmt", "print_list", "print_stmt", "else_stmt", "if_stmt_list",
  "if_stmt", "while_stmt_list", "while_stmt", "count_stmt", "operation",
  "exp", "math", "term", "factor", "end_stmt", "end_sec", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298
};
# endif

#define YYPACT_NINF -95

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-95)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       0,    38,    52,    56,   -95,   -95,    68,    67,    10,    76,
      86,   -95,   -95,    10,   -95,    91,    89,    92,   -95,   -95,
      84,   -95,   -95,   113,    32,    74,   -12,    32,    32,    32,
      32,    32,    32,   126,   100,    89,   -95,   -95,   -95,   -95,
     117,   112,    15,   -95,   119,   132,   125,   -14,    31,   -95,
     140,   139,    74,    33,   137,   149,    35,   -95,   -14,   -14,
     -14,   -14,   -14,   -14,   140,   154,   126,   -95,    28,    89,
     -95,   -95,   153,   -95,    84,   146,   157,   -95,    32,    32,
      32,    32,   144,    89,   -95,   -95,   159,   -95,   -95,   -95,
     -95,   152,    89,   -95,   167,   168,    65,   170,   -95,   153,
     171,    31,    31,   -95,   -95,    41,    12,   172,    61,    65,
     147,   148,    25,   -95,   -95,   180,   -95,   -95,   -95,   183,
      89,   -95,   181,   -95,   -95,   -95,   177,   178,   187,   188,
     189,   -95,   -95,    65,   -95,   190,   191,   -95,   -95,   -95,
     -95,   -95,   -95
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     3,     1,     0,     0,     4,     0,
       0,     9,    10,     5,     6,     0,    15,     0,     2,     7,
       0,    68,    69,    70,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    16,    17,    24,    53,    61,
       0,    13,     0,    11,     0,    70,    51,    60,    64,    67,
       0,     0,    36,    29,    33,    27,     0,    25,    54,    58,
      57,    56,    55,    59,     0,     0,    41,    46,     0,     0,
      18,    75,     0,     8,     0,     0,     0,    49,     0,     0,
       0,     0,     0,     0,    37,    30,     0,    34,    28,    19,
      26,     0,     0,    42,     0,     0,     0,     0,    12,    71,
       0,    62,    63,    66,    65,    39,     0,     0,    44,     0,
       0,     0,     0,    23,    14,    52,    71,    40,    38,     0,
       0,    22,    31,    45,    43,    20,     0,     0,     0,     0,
       0,    50,    35,     0,    32,     0,     0,    72,    73,    74,
      21,    47,    48
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -95,   -95,   -95,   -95,   -95,   185,   -95,   -95,   127,   -95,
     -67,   -35,   -95,   143,   -95,   150,   -95,   134,   -95,   -95,
     -10,   -22,    90,    16,   -21,   -94,   -95
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     3,     7,    13,    14,    15,    42,    43,    10,
      35,    36,    56,    57,   120,    51,    52,    65,    66,    69,
      37,    38,    47,    48,    39,   113,    18
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      70,    46,    96,    49,    53,     1,    49,    49,    49,    49,
      49,    49,   121,    11,    12,   125,   106,    54,    55,    78,
      79,    73,   112,    67,    74,   109,    21,    22,    23,    24,
      25,   119,    26,    27,    28,    29,    30,    31,    32,   140,
      82,    89,    85,   128,     4,    86,    21,    22,    45,    33,
      97,    53,     5,   133,    91,    34,    67,    49,    49,   103,
     104,    70,   129,     6,    54,    55,    80,    81,   130,    94,
      95,    70,   117,   118,    70,   112,     8,   115,     9,    21,
      22,    23,    24,    25,    16,    26,    27,    28,    29,    30,
      31,    32,   123,   124,   101,   102,    17,    40,    70,    20,
      41,    50,    33,    21,    22,    23,    24,    25,    34,    26,
      27,    28,    29,    30,    31,    32,    68,    58,    59,    60,
      61,    62,    63,    71,    72,    44,    33,    21,    22,    45,
      24,    77,    34,    75,    27,    28,    29,    30,    31,    32,
      21,    22,    23,    24,    76,    83,    87,    27,    28,    29,
      30,    31,    32,    64,    21,    22,    23,    24,    88,    99,
      92,    27,    28,    29,    30,    31,    32,    21,    22,    45,
      24,   100,   105,   107,    27,    28,    29,    30,    31,    32,
     108,   110,   111,   114,   116,   122,   131,   126,   127,   132,
     134,   135,   136,   137,   138,   139,   141,   142,    19,    90,
      93,    98,    84
};

static const yytype_uint8 yycheck[] =
{
      35,    23,    69,    24,    16,     5,    27,    28,    29,    30,
      31,    32,   106,     3,     4,   109,    83,    29,    30,    33,
      34,     6,    10,    33,     9,    92,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,   133,
      50,     6,     9,    18,     6,    12,    14,    15,    16,    37,
      72,    16,     0,   120,    64,    43,    66,    78,    79,    80,
      81,    96,    37,     7,    29,    30,    35,    36,    43,    41,
      42,   106,    31,    32,   109,    10,     8,    99,    11,    14,
      15,    16,    17,    18,     8,    20,    21,    22,    23,    24,
      25,    26,    31,    32,    78,    79,    10,     5,   133,     8,
      16,    27,    37,    14,    15,    16,    17,    18,    43,    20,
      21,    22,    23,    24,    25,    26,    16,    27,    28,    29,
      30,    31,    32,     6,    12,    12,    37,    14,    15,    16,
      17,     6,    43,    14,    21,    22,    23,    24,    25,    26,
      14,    15,    16,    17,    12,     6,     9,    21,    22,    23,
      24,    25,    26,    27,    14,    15,    16,    17,     9,    13,
       6,    21,    22,    23,    24,    25,    26,    14,    15,    16,
      17,    14,    28,    14,    21,    22,    23,    24,    25,    26,
      28,    14,    14,    13,    13,    13,     6,    40,    40,     6,
       9,    14,    14,     6,     6,     6,     6,     6,    13,    56,
      66,    74,    52
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     5,    45,    46,     6,     0,     7,    47,     8,    11,
      53,     3,     4,    48,    49,    50,     8,    10,    70,    49,
       8,    14,    15,    16,    17,    18,    20,    21,    22,    23,
      24,    25,    26,    37,    43,    54,    55,    64,    65,    68,
       5,    16,    51,    52,    12,    16,    65,    66,    67,    68,
      27,    59,    60,    16,    29,    30,    56,    57,    66,    66,
      66,    66,    66,    66,    27,    61,    62,    64,    16,    63,
      55,     6,    12,     6,     9,    14,    12,     6,    33,    34,
      35,    36,    64,     6,    59,     9,    12,     9,     9,     6,
      57,    64,     6,    61,    41,    42,    54,    65,    52,    13,
      14,    67,    67,    68,    68,    28,    54,    14,    28,    54,
      14,    14,    10,    69,    13,    65,    13,    31,    32,    19,
      58,    69,    13,    31,    32,    69,    40,    40,    18,    37,
      43,     6,     6,    54,     9,    14,    14,     6,     6,     6,
      69,     6,     6
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    44,    45,    46,    47,    47,    48,    48,    49,    50,
      50,    51,    51,    52,    52,    53,    53,    54,    54,    55,
      55,    55,    55,    55,    55,    56,    56,    57,    57,    57,
      57,    57,    57,    57,    57,    58,    59,    59,    60,    60,
      60,    61,    61,    62,    62,    62,    62,    63,    63,    64,
      64,    64,    64,    64,    65,    65,    65,    65,    65,    65,
      65,    65,    66,    66,    66,    67,    67,    67,    68,    68,
      68,    68,    69,    69,    69,    70
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     4,     2,     2,     3,     1,     2,     4,     1,
       1,     1,     3,     1,     4,     2,     3,     1,     2,     3,
       5,     7,     5,     4,     1,     1,     2,     1,     2,     1,
       2,     4,     5,     1,     2,     2,     1,     2,     4,     3,
       4,     1,     2,     4,     3,     4,     1,     6,     6,     3,
       6,     2,     5,     1,     2,     2,     2,     2,     2,     2,
       2,     1,     3,     3,     1,     3,     3,     1,     1,     1,
       1,     4,     3,     3,     3,     3
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 9:
#line 115 "checkpoint7.y" /* yacc.c:1646  */
    {
					dtype = DT_INT;
				}
#line 1447 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 119 "checkpoint7.y" /* yacc.c:1646  */
    {
					dtype = DT_REAL;
				}
#line 1455 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 129 "checkpoint7.y" /* yacc.c:1646  */
    {
					createNode((yyvsp[0].sval), dtype, adCount, TP_SCALAR, 1);
					adCount++;
				}
#line 1464 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 134 "checkpoint7.y" /* yacc.c:1646  */
    {
					createNode((yyvsp[-3].sval), dtype, adCount, TP_ARRAY, (int)(yyvsp[-1].ex)->value);
					adCount += (int)(yyvsp[-1].ex)->value;
				}
#line 1473 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 161 "checkpoint7.y" /* yacc.c:1646  */
    {
					struct expression *pr = malloc(sizeof(struct expression));
					pr->value = 0;
					pr->op = 8;
					createSTree((yyvsp[0].sval), pr, 0, 1, andor);
					lines += charCount((yyvsp[0].sval)) * 2;
				}
#line 1485 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 170 "checkpoint7.y" /* yacc.c:1646  */
    {
					struct expression *pr = malloc(sizeof(struct expression));
					pr->value = 0;
					pr->op = 8;
					createSTree((yyvsp[-1].sval), pr, 0, 1, andor);
					lines += charCount((yyvsp[-1].sval)) * 2;
				}
#line 1497 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 179 "checkpoint7.y" /* yacc.c:1646  */
    {
					struct expression *pr = malloc(sizeof(struct expression));
					pr->value = 0;
					pr->op = 8;
					createSTree((yyvsp[0].sval), pr, 0, 3, andor);
					lines += 3;
				}
#line 1509 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 188 "checkpoint7.y" /* yacc.c:1646  */
    {
					struct expression *pr = malloc(sizeof(struct expression));
					pr->value = 0;
					pr->op = 8;
					createSTree((yyvsp[-1].sval), pr, 0, 3, andor);
					lines += 3;
				}
#line 1521 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 196 "checkpoint7.y" /* yacc.c:1646  */
    {
					struct expression *pr = malloc(sizeof(struct expression));
					pr->value = 0;
					pr->op = 8;
					createSTree((yyvsp[-3].sval), pr, (yyvsp[-1].ival), 3, andor);
					lines += 3;
				}
#line 1533 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 205 "checkpoint7.y" /* yacc.c:1646  */
    {
					struct expression *pr = malloc(sizeof(struct expression));
					pr->value = 0;
					pr->op = 8;
					createSTree((yyvsp[-4].sval), pr, (yyvsp[-2].ival), 3, andor);
					lines += 3;
				}
#line 1545 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 214 "checkpoint7.y" /* yacc.c:1646  */
    {
					struct expression *pr = malloc(sizeof(struct expression));
					pr->value = 0;
					pr->op = 8;
					createSTree(NULL, pr, 0, 2, andor);
					lines++;
				}
#line 1557 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 223 "checkpoint7.y" /* yacc.c:1646  */
    {
					struct expression *pr = malloc(sizeof(struct expression));
					pr->value = 0;
					pr->op = 8;
					createSTree(NULL, pr, 0, 2, andor);
					lines++;
				}
#line 1569 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 234 "checkpoint7.y" /* yacc.c:1646  */
    {
					if(elseCheck == 0){
						push(lines + 1);
						lines++;
						elseCheck = 1;
					}
				}
#line 1581 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 248 "checkpoint7.y" /* yacc.c:1646  */
    {
					andor = 1;
					condNum++;
					push(lines + 5);
				}
#line 1591 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 254 "checkpoint7.y" /* yacc.c:1646  */
    {
					andor = -1;
					condNum++;
				}
#line 1600 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 260 "checkpoint7.y" /* yacc.c:1646  */
    {
					andor = 0;
					condNum++;
				}
#line 1609 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 271 "checkpoint7.y" /* yacc.c:1646  */
    {
					andor = 1;
					condNum++;
					push(lines + 5);
					whileArray[whilecount] = lines - 6;
					whilecount++;
				}
#line 1621 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 279 "checkpoint7.y" /* yacc.c:1646  */
    {
					andor = -1;
					condNum++;
					whileArray[whilecount] = lines - 6;
					whilecount++;
				}
#line 1632 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 287 "checkpoint7.y" /* yacc.c:1646  */
    {
					andor = 0;
					condNum++;
					whileArray[whilecount] = lines - 6;
					whilecount++;
				}
#line 1643 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 294 "checkpoint7.y" /* yacc.c:1646  */
    {
					andor = -1;
					condNum++;
					whileArray[whilecount] = lines - 6;
					whilecount++;
				}
#line 1654 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 303 "checkpoint7.y" /* yacc.c:1646  */
    {
						(yyval.ex) = (struct expression*)malloc(sizeof(struct expression));
						(yyval.ex)->value = (float)(yyvsp[-3].ival);
						(yyval.ex)->op = 1;
						createSTree((yyvsp[-5].sval), (yyval.ex), 0, 0, 0);
						lines += 3;
						struct expression* tmp= (struct expression*)malloc(sizeof(struct expression));
						tmp->value = (float)(yyvsp[-1].ival);
						tmp->op = 3;
						createSTree((yyvsp[-5].sval), tmp, 0, 0, 0);
						lines += 4;
					}
#line 1671 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 316 "checkpoint7.y" /* yacc.c:1646  */
    {
						struct expression* tmp = (struct expression*)malloc(sizeof(struct expression));
						tmp->value = (float)(yyvsp[-3].ival);
						tmp->op = 1;
						createSTree((yyvsp[-5].sval), tmp, 0, (yyvsp[-1].ival), 0);
					}
#line 1682 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 325 "checkpoint7.y" /* yacc.c:1646  */
    {
					if(elseCheck == 1){
						createSTree((yyvsp[-2].sval), (yyvsp[-1].ex), 0, 4, andor);
						elseCheck = 0;
					}else{
						createSTree((yyvsp[-2].sval), (yyvsp[-1].ex), 0, 0, andor);
					}
					rootMath = NULL;
				}
#line 1696 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 335 "checkpoint7.y" /* yacc.c:1646  */
    {
					if(elseCheck == 1){
						createSTree((yyvsp[-5].sval), (yyvsp[-1].ex), (yyvsp[-3].ival), 4, andor);
						elseCheck = 0;
					}else{
						createSTree((yyvsp[-5].sval), (yyvsp[-1].ex), (yyvsp[-3].ival), 0, andor);
					}
					rootMath = NULL;
				}
#line 1710 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 345 "checkpoint7.y" /* yacc.c:1646  */
    {
					if(elseCheck == 1){
						createSTree((yyvsp[-1].sval), (yyvsp[0].ex), 0, 4, andor);
						elseCheck = 0;
					}else{
						createSTree((yyvsp[-1].sval), (yyvsp[0].ex), 0, 0, andor);
					}
					rootMath = NULL;
				}
#line 1724 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 356 "checkpoint7.y" /* yacc.c:1646  */
    {
					if(elseCheck == 1){
						createSTree((yyvsp[-4].sval), (yyvsp[0].ex), (yyvsp[-2].ival), 4, andor);
						elseCheck = 0;
					}else{
						createSTree((yyvsp[-4].sval), (yyvsp[0].ex), (yyvsp[-2].ival), 0, andor);
					}
					rootMath = NULL;
				}
#line 1738 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 369 "checkpoint7.y" /* yacc.c:1646  */
    {
				(yyval.ex) = malloc(sizeof(struct expression));
				(yyval.ex)->value = (yyvsp[0].ml)->value;
				(yyval.ex)->op = 7;
				(yyval.ex)->link = (yyvsp[0].ml);
				lines += 5;
			}
#line 1750 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 377 "checkpoint7.y" /* yacc.c:1646  */
    {
				(yyval.ex) = malloc(sizeof(struct expression));
				(yyval.ex)->value = (yyvsp[0].ml)->value;
				(yyval.ex)->op = 6;
				(yyval.ex)->link = (yyvsp[0].ml);
				lines += 5;
			}
#line 1762 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 385 "checkpoint7.y" /* yacc.c:1646  */
    {
				(yyval.ex) = malloc(sizeof(struct expression));
				(yyval.ex)->value = (yyvsp[0].ml)->value;
				(yyval.ex)->op = 5;
				(yyval.ex)->link = (yyvsp[0].ml);
				lines += 5;
			}
#line 1774 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 393 "checkpoint7.y" /* yacc.c:1646  */
    {
				(yyval.ex) = malloc(sizeof(struct expression));
				(yyval.ex)->value = (yyvsp[0].ml)->value;
				(yyval.ex)->op = 4;
				(yyval.ex)->link = (yyvsp[0].ml);
				lines += 5;
			}
#line 1786 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 401 "checkpoint7.y" /* yacc.c:1646  */
    {
				(yyval.ex) = malloc(sizeof(struct expression));
				(yyval.ex)->value = (yyvsp[0].ml)->value;
				(yyval.ex)->op = 3;
				(yyval.ex)->link = (yyvsp[0].ml);
				lines += 5;
			}
#line 1798 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 409 "checkpoint7.y" /* yacc.c:1646  */
    {
				(yyval.ex) = malloc(sizeof(struct expression));
				(yyval.ex)->value = (yyvsp[0].ml)->value;
				(yyval.ex)->op = 2;
				(yyval.ex)->link = (yyvsp[0].ml);
				lines += 5;
			}
#line 1810 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 417 "checkpoint7.y" /* yacc.c:1646  */
    {
				(yyval.ex) = malloc(sizeof(struct expression));
				(yyval.ex)->value = (yyvsp[0].ml)->value;
				(yyval.ex)->op = 1;
				(yyval.ex)->link = (yyvsp[0].ml);
				lines += 3;
			}
#line 1822 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 426 "checkpoint7.y" /* yacc.c:1646  */
    {
				(yyval.ex) = malloc(sizeof(struct expression));
				(yyval.ex)->value = (yyvsp[0].ml)->value;
				(yyval.ex)->op = 1;
			}
#line 1832 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 434 "checkpoint7.y" /* yacc.c:1646  */
    {
				(yyval.ml) = malloc(sizeof(struct mathlist));
				(yyval.ml)->op = 9;
				(yyval.ml)->lop = (yyvsp[-2].ml);
				(yyval.ml)->rop = (yyvsp[0].ml);
				lines += 2;
			}
#line 1844 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 442 "checkpoint7.y" /* yacc.c:1646  */
    {
				(yyval.ml) = malloc(sizeof(struct mathlist));
				(yyval.ml)->op = 10;
				(yyval.ml)->rop = (yyvsp[-2].ml);
				(yyval.ml)->lop = (yyvsp[0].ml);
				lines += 2;
			}
#line 1856 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 450 "checkpoint7.y" /* yacc.c:1646  */
    {
				(yyval.ml) = (yyvsp[0].ml);
		 	}
#line 1864 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 456 "checkpoint7.y" /* yacc.c:1646  */
    {
				(yyval.ml) = malloc(sizeof(struct mathlist));
				(yyval.ml)->op = 11;
				(yyval.ml)->rop = (yyvsp[-2].ml);
				(yyval.ml)->lop = (yyvsp[0].ml);
				lines += 2;
			}
#line 1876 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 464 "checkpoint7.y" /* yacc.c:1646  */
    {
				(yyval.ml) = malloc(sizeof(struct mathlist));
				(yyval.ml)->op = 12;
				(yyval.ml)->lop = (yyvsp[-2].ml);
				(yyval.ml)->rop = (yyvsp[0].ml);
				lines += 2;
			}
#line 1888 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 472 "checkpoint7.y" /* yacc.c:1646  */
    {
				(yyval.ml) = (yyvsp[0].ml);
			}
#line 1896 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 478 "checkpoint7.y" /* yacc.c:1646  */
    {
				(yyval.ml) = malloc(sizeof(struct mathlist));
				(yyval.ml)->value = (float)(yyvsp[0].ival);
				(yyval.ml)->isVar = 0;
			}
#line 1906 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 484 "checkpoint7.y" /* yacc.c:1646  */
    {
				(yyval.ml) = malloc(sizeof(struct mathlist));
				(yyval.ml)->value = (yyvsp[0].rval);
				(yyval.ml)->isVar = 0;
			}
#line 1916 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 490 "checkpoint7.y" /* yacc.c:1646  */
    {
				struct syntree* tmp = (struct syntree*)malloc(sizeof(struct syntree));
				tmp->id = (yyvsp[0].sval);
				(yyval.ml) = malloc(sizeof(struct mathlist));
				(yyval.ml)->value = lookup(tmp)->address;
				(yyval.ml)->isVar = 1;
				lines += 1;
			}
#line 1929 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 499 "checkpoint7.y" /* yacc.c:1646  */
    {
				struct syntree* tmp = (struct syntree*)malloc(sizeof(struct syntree));
				tmp->id = (yyvsp[-3].sval);
				(yyval.ml) = malloc(sizeof(struct mathlist));
				(yyval.ml)->value = lookup(tmp)->address + (yyvsp[-1].ival);
				(yyval.ml)->isVar = 1;
				lines += 1;
			}
#line 1942 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 511 "checkpoint7.y" /* yacc.c:1646  */
    {
					for(int i = 0; i < condNum; i++){
						push(lines);
					}
					condNum = 0;
					elseCheck = 0;
				}
#line 1954 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 519 "checkpoint7.y" /* yacc.c:1646  */
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
#line 1971 "y.tab.c" /* yacc.c:1646  */
    break;


#line 1975 "y.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 538 "checkpoint7.y" /* yacc.c:1906  */


int yyerror() {
   printf("Called yyerror()\n");
   return  0;
}
