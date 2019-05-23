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
#line 2 "compiler_hw2.y" /* yacc.c:339  */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

extern int yylineno;
extern int yylex();
extern void yyerror(char *s);
extern char* yytext;   // Get current token from lex
extern char buf[256];  // Get current code line from lex

void semantic_error(char errormsg[100], int sem_line);
int error_flag;
char sem_error_msg[100];

void syntax_error(char errormsg[100]);
int syntax_flag;
char syn_error_msg[100];

char function_name[100];

/* Symbol table function - you can add new function if needed. */
struct symbol
{
	int index;
	char name[100];
	char kind[100];
	char type[100];
	int scope;
	char attribute[100];
};

struct scope
{
	struct symbol table[30];
};

int lookup_symbol(char[], char[]);
void create_symbol();
void insert_symbol(char[], char[], char[], char[], int);
void dump_symbol(int);
int dump_flag;

struct scope global_table[40];
int table_num;

struct scope temp_dump_table;
void clear_temp_table();
void fill_temp_table();

void init_func_table();
void insert_func_table(char[]);
int lookup_func_table(char[]);
struct func_table
{
	int flag;
	char name[100];
}implement_func_table[30];
int func_flag;


#line 129 "y.tab.c" /* yacc.c:339  */

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
    INT = 258,
    FLOAT = 259,
    STRING = 260,
    BOOL = 261,
    VOID = 262,
    ADD = 263,
    SUB = 264,
    MUL = 265,
    DIV = 266,
    MOD = 267,
    INC = 268,
    DEC = 269,
    MT = 270,
    LT = 271,
    MTE = 272,
    LTE = 273,
    EQ = 274,
    NE = 275,
    ASGN = 276,
    ADDASGN = 277,
    SUBASGN = 278,
    MULASGN = 279,
    DIVASGN = 280,
    MODASGN = 281,
    AND = 282,
    OR = 283,
    NOT = 284,
    LB = 285,
    RB = 286,
    LCB = 287,
    RCB = 288,
    LSB = 289,
    RSB = 290,
    COMMA = 291,
    PRINT = 292,
    IF = 293,
    ELSE = 294,
    FOR = 295,
    WHILE = 296,
    ID = 297,
    SEMICOLON = 298,
    RET = 299,
    START_COMMENT = 300,
    END_COMMENT = 301,
    CPLUS_COMMENT = 302,
    I_CONST = 303,
    F_CONST = 304,
    S_CONST = 305,
    TRUE = 306,
    FALSE = 307
  };
#endif
/* Tokens.  */
#define INT 258
#define FLOAT 259
#define STRING 260
#define BOOL 261
#define VOID 262
#define ADD 263
#define SUB 264
#define MUL 265
#define DIV 266
#define MOD 267
#define INC 268
#define DEC 269
#define MT 270
#define LT 271
#define MTE 272
#define LTE 273
#define EQ 274
#define NE 275
#define ASGN 276
#define ADDASGN 277
#define SUBASGN 278
#define MULASGN 279
#define DIVASGN 280
#define MODASGN 281
#define AND 282
#define OR 283
#define NOT 284
#define LB 285
#define RB 286
#define LCB 287
#define RCB 288
#define LSB 289
#define RSB 290
#define COMMA 291
#define PRINT 292
#define IF 293
#define ELSE 294
#define FOR 295
#define WHILE 296
#define ID 297
#define SEMICOLON 298
#define RET 299
#define START_COMMENT 300
#define END_COMMENT 301
#define CPLUS_COMMENT 302
#define I_CONST 303
#define F_CONST 304
#define S_CONST 305
#define TRUE 306
#define FALSE 307

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 68 "compiler_hw2.y" /* yacc.c:355  */

    int i_val;
    double f_val;
    char* string_val;
//	bool bool_val;

#line 280 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 297 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   237

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  53
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  39
/* YYNRULES -- Number of rules.  */
#define YYNRULES  101
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  171

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   307

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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   108,   108,   109,   113,   114,   115,   116,   117,   118,
     119,   123,   124,   125,   126,   127,   128,   132,   133,   137,
     138,   142,   150,   161,   162,   172,   185,   198,   215,   214,
     263,   270,   280,   281,   285,   286,   290,   299,   309,   308,
     325,   334,   338,   339,   343,   344,   345,   349,   350,   351,
     352,   356,   357,   358,   359,   360,   369,   370,   379,   391,
     391,   398,   399,   398,   408,   409,   413,   414,   413,   420,
     420,   430,   431,   435,   436,   440,   441,   442,   443,   444,
     445,   449,   453,   454,   466,   467,   471,   472,   473,   477,
     478,   479,   480,   481,   482,   486,   487,   492,   493,   494,
     495,   496
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INT", "FLOAT", "STRING", "BOOL", "VOID",
  "ADD", "SUB", "MUL", "DIV", "MOD", "INC", "DEC", "MT", "LT", "MTE",
  "LTE", "EQ", "NE", "ASGN", "ADDASGN", "SUBASGN", "MULASGN", "DIVASGN",
  "MODASGN", "AND", "OR", "NOT", "LB", "RB", "LCB", "RCB", "LSB", "RSB",
  "COMMA", "PRINT", "IF", "ELSE", "FOR", "WHILE", "ID", "SEMICOLON", "RET",
  "START_COMMENT", "END_COMMENT", "CPLUS_COMMENT", "I_CONST", "F_CONST",
  "S_CONST", "TRUE", "FALSE", "$accept", "program", "stat", "func_stat",
  "func_mul_stat", "return_stat", "func", "func_end", "declaration",
  "declaration_func", "$@1", "func_parameter", "func_call", "const",
  "expression", "$@2", "expression_stat", "add_expression_stat",
  "mul_expression_stat", "factor", "iteration_stat", "$@3", "$@4", "$@5",
  "haselse", "haselseif", "$@6", "$@7", "$@8", "moreelseif", "mul_stat",
  "relational", "print_func", "print_type", "comment_stat", "initializer",
  "asgn", "arithmetic_postfix", "type", YY_NULLPTR
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
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307
};
# endif

#define YYPACT_NINF -102

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-102)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -102,     1,  -102,  -102,  -102,  -102,  -102,  -102,   -20,   -16,
       6,   155,  -102,    28,   -25,  -102,  -102,  -102,  -102,  -102,
    -102,  -102,  -102,    -2,    -9,    78,    78,  -102,  -102,  -102,
    -102,  -102,  -102,  -102,  -102,    54,    78,     4,   104,    78,
      21,  -102,  -102,  -102,  -102,  -102,  -102,   113,    74,   112,
    -102,    55,  -102,   -19,    87,    94,  -102,   171,   177,   101,
    -102,    69,  -102,   217,   119,  -102,  -102,  -102,   194,    64,
    -102,  -102,  -102,  -102,  -102,  -102,  -102,  -102,    78,    78,
      78,    78,    78,    78,  -102,    28,  -102,  -102,   115,   116,
     128,   132,  -102,  -102,    64,  -102,  -102,    79,    74,   112,
     112,  -102,  -102,  -102,   131,   120,    86,  -102,  -102,  -102,
    -102,   122,  -102,  -102,  -102,  -102,   -23,  -102,    85,    44,
      12,    12,  -102,    24,  -102,  -102,   -23,   223,  -102,    12,
     133,   137,    28,    24,   138,  -102,  -102,  -102,  -102,  -102,
     130,  -102,   140,  -102,  -102,  -102,  -102,  -102,  -102,   -18,
    -102,   134,    43,  -102,  -102,   145,  -102,    12,    78,   150,
     200,  -102,   152,  -102,    12,   165,  -102,   160,    43,  -102,
    -102
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     1,    97,    98,   100,    99,   101,     0,     0,
       0,     0,    41,     0,     0,    84,     2,     4,     5,     6,
       7,     8,     9,     0,     0,     0,     0,    95,    96,    89,
      90,    91,    92,    93,    94,     0,     0,     0,     0,     0,
      55,    51,    52,    86,    87,    88,    10,     0,    43,    46,
      50,     0,    85,     0,     0,     0,    81,     0,     0,     0,
      34,     0,    33,    35,     0,    37,    53,    54,     0,     0,
      57,    75,    76,    77,    78,    79,    80,    20,     0,     0,
       0,     0,     0,     0,    19,     0,    28,    26,     0,     0,
       0,     0,    40,    38,     0,    36,    56,     0,    42,    44,
      45,    47,    48,    49,     0,     0,     0,    83,    82,    61,
      59,     0,    32,    58,    27,    25,     0,    29,     0,     0,
       0,     0,    39,     0,    23,    22,     0,     0,    31,    74,
       0,     0,     0,    18,     0,    11,    12,    13,    14,    15,
       0,    21,     0,    73,    62,    60,    16,    17,    24,     0,
      30,    65,     0,    63,    69,     0,    64,     0,     0,     0,
       0,    70,     0,    66,     0,     0,    67,    72,     0,    68,
      71
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -102,  -102,   199,  -102,    68,    71,  -102,    80,  -101,  -102,
    -102,  -102,   135,   111,   -59,  -102,   -13,   129,    75,    60,
     -26,  -102,  -102,  -102,  -102,    53,  -102,  -102,  -102,  -102,
     -69,  -102,   -24,  -102,   -22,   139,  -102,   182,    34
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,   129,   133,   134,    46,   117,   125,    17,    18,
     106,   118,    61,    62,    19,   111,    63,    48,    49,    50,
      20,   121,   120,   151,   153,   156,   164,   167,   157,   169,
     130,    78,    21,    56,    22,    51,    36,    37,    23
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      47,     2,    85,    85,     3,     4,     5,     6,     7,   123,
      24,    86,    57,    58,    25,     3,     4,     5,     6,     7,
     124,    52,   135,    64,    87,    87,    68,     3,     4,     5,
       6,     7,   135,    54,    27,    28,    26,    38,     8,     9,
      53,    55,    10,    11,    12,    13,    14,    65,    15,     8,
       9,    69,   131,    10,    11,    12,    13,    14,    39,    15,
     143,     8,     9,    38,   136,    10,    11,    12,   132,    14,
      40,    15,   104,    38,   136,   154,    41,    42,    43,    44,
      45,   155,    79,    80,    39,    59,   128,    38,   159,     3,
       4,     5,     6,     7,    39,   165,    40,   137,    84,   138,
      93,   139,    41,    42,    60,    94,    40,   137,    39,   138,
     113,   139,    41,    42,    60,    94,   126,   116,    88,    47,
      40,   127,    81,    82,    83,    89,    41,    42,    71,    72,
      73,    74,    75,    76,    71,    72,    73,    74,    75,    76,
     119,   101,   102,   103,    92,   160,    71,    72,    73,    74,
      75,    76,    66,    67,    99,   100,    77,   140,   107,   108,
     109,   142,    95,   115,   110,   122,   144,   140,    27,    28,
     145,   148,   149,   152,   114,   158,    29,    30,    31,    32,
      33,    34,   150,   161,   163,    35,    71,    72,    73,    74,
      75,    76,    71,    72,    73,    74,    75,    76,   166,   168,
      16,   147,    90,   146,    97,   112,   141,    98,    91,    71,
      72,    73,    74,    75,    76,    71,    72,    73,    74,    75,
      76,   170,    70,     0,   105,    96,     3,     4,     5,     6,
       7,   162,    71,    72,    73,    74,    75,    76
};

static const yytype_int16 yycheck[] =
{
      13,     0,    21,    21,     3,     4,     5,     6,     7,    32,
      30,    30,    25,    26,    30,     3,     4,     5,     6,     7,
      43,    46,   123,    36,    43,    43,    39,     3,     4,     5,
       6,     7,   133,    42,    13,    14,    30,     9,    37,    38,
      42,    50,    41,    42,    43,    44,    45,    43,    47,    37,
      38,    30,   121,    41,    42,    43,    44,    45,    30,    47,
     129,    37,    38,     9,   123,    41,    42,    43,    44,    45,
      42,    47,    85,     9,   133,    32,    48,    49,    50,    51,
      52,    38,     8,     9,    30,    31,    42,     9,   157,     3,
       4,     5,     6,     7,    30,   164,    42,   123,    43,   123,
      31,   123,    48,    49,    50,    36,    42,   133,    30,   133,
      31,   133,    48,    49,    50,    36,    31,    31,    31,   132,
      42,    36,    10,    11,    12,    31,    48,    49,    15,    16,
      17,    18,    19,    20,    15,    16,    17,    18,    19,    20,
     106,    81,    82,    83,    43,   158,    15,    16,    17,    18,
      19,    20,    48,    49,    79,    80,    43,   123,    43,    43,
      32,   127,    43,    43,    32,    43,    33,   133,    13,    14,
      33,    33,    42,    39,    43,    30,    21,    22,    23,    24,
      25,    26,    42,    33,    32,    30,    15,    16,    17,    18,
      19,    20,    15,    16,    17,    18,    19,    20,    33,    39,
       1,   133,    31,   132,    69,    94,   126,    78,    31,    15,
      16,    17,    18,    19,    20,    15,    16,    17,    18,    19,
      20,   168,    40,    -1,    85,    31,     3,     4,     5,     6,
       7,    31,    15,    16,    17,    18,    19,    20
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    54,     0,     3,     4,     5,     6,     7,    37,    38,
      41,    42,    43,    44,    45,    47,    55,    61,    62,    67,
      73,    85,    87,    91,    30,    30,    30,    13,    14,    21,
      22,    23,    24,    25,    26,    30,    89,    90,     9,    30,
      42,    48,    49,    50,    51,    52,    58,    69,    70,    71,
      72,    88,    46,    42,    42,    50,    86,    69,    69,    31,
      50,    65,    66,    69,    69,    43,    48,    49,    69,    30,
      90,    15,    16,    17,    18,    19,    20,    43,    84,     8,
       9,    10,    11,    12,    43,    21,    30,    43,    31,    31,
      31,    31,    43,    31,    36,    43,    31,    65,    70,    71,
      71,    72,    72,    72,    69,    88,    63,    43,    43,    32,
      32,    68,    66,    31,    43,    43,    31,    59,    64,    91,
      75,    74,    43,    32,    43,    60,    31,    36,    42,    55,
      83,    83,    44,    56,    57,    61,    67,    73,    85,    87,
      91,    60,    91,    83,    33,    33,    58,    57,    33,    42,
      42,    76,    39,    77,    32,    38,    78,    81,    30,    83,
      69,    33,    31,    32,    79,    83,    33,    80,    39,    82,
      78
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    53,    54,    54,    55,    55,    55,    55,    55,    55,
      55,    56,    56,    56,    56,    56,    56,    57,    57,    58,
      58,    59,    59,    60,    60,    61,    61,    61,    63,    62,
      64,    64,    65,    65,    66,    66,    67,    67,    68,    67,
      67,    67,    69,    69,    70,    70,    70,    71,    71,    71,
      71,    72,    72,    72,    72,    72,    72,    72,    72,    74,
      73,    75,    76,    73,    77,    77,    79,    80,    78,    81,
      78,    82,    82,    83,    83,    84,    84,    84,    84,    84,
      84,    85,    86,    86,    87,    87,    88,    88,    88,    89,
      89,    89,    89,    89,    89,    90,    90,    91,    91,    91,
      91,    91
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     0,     1,     1,     1,     1,     1,     1,
       2,     1,     1,     1,     1,     1,     2,     2,     1,     2,
       2,     3,     2,     1,     3,     5,     3,     5,     0,     5,
       4,     2,     3,     1,     1,     1,     4,     3,     0,     6,
       4,     1,     3,     1,     3,     3,     1,     3,     3,     3,
       1,     1,     1,     2,     2,     1,     3,     2,     4,     0,
       8,     0,     0,    10,     2,     0,     0,     0,    10,     0,
       4,     2,     0,     2,     1,     1,     1,     1,     1,     1,
       1,     3,     3,     3,     1,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1
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
        case 21:
#line 143 "compiler_hw2.y" /* yacc.c:1646  */
    {
		if(!strcmp((yyvsp[0].string_val), ";")) {
			table_num--;
			func_flag = 1;
		}
		//else func_flag = 1;
	}
#line 1523 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 151 "compiler_hw2.y" /* yacc.c:1646  */
    {
		if(!strcmp((yyvsp[0].string_val), ";")) {
			table_num--;
			func_flag = 1;
		}
		//else func_flag = 1;
	}
#line 1535 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 163 "compiler_hw2.y" /* yacc.c:1646  */
    { 
		dump_flag = 1; 
		clear_temp_table();
		fill_temp_table();
		table_num--;
	}
#line 1546 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 173 "compiler_hw2.y" /* yacc.c:1646  */
    {
		int index = lookup_symbol((yyvsp[-3].string_val), "insert"); 
		if(index != -1) {
			insert_symbol((yyvsp[-3].string_val), "variable", (yyvsp[-4].string_val), "\0", index);
		}
		else {
			error_flag = 1;
			bzero(sem_error_msg, 100);
			strcat(sem_error_msg, "Redeclared variable ");
			strcat(sem_error_msg, (yyvsp[-3].string_val));
		}
	}
#line 1563 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 186 "compiler_hw2.y" /* yacc.c:1646  */
    {
		int index = lookup_symbol((yyvsp[-1].string_val), "insert"); 
		if(index != -1) {
			insert_symbol((yyvsp[-1].string_val), "variable", (yyvsp[-2].string_val), "\0", index);
		}
		else {
			error_flag = 1;
			bzero(sem_error_msg, 100);
			strcat(sem_error_msg, "Redeclared variable ");
			strcat(sem_error_msg, (yyvsp[-1].string_val));
		}
	}
#line 1580 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 199 "compiler_hw2.y" /* yacc.c:1646  */
    {
		int index = lookup_symbol((yyvsp[-3].string_val), "insert"); 
		if(index != -1) {
			insert_symbol((yyvsp[-3].string_val), "variable", (yyvsp[-4].string_val), "\0", index);
		}
		else {
			error_flag = 1;
			bzero(sem_error_msg, 100);
			strcat(sem_error_msg, "Redeclared variable ");
			strcat(sem_error_msg, (yyvsp[-3].string_val));
		}
	}
#line 1597 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 215 "compiler_hw2.y" /* yacc.c:1646  */
    { 
		table_num++; 
		create_symbol(); 
		/*
		int index = lookup_func_table($2);
		if(index == 2) {
			error_flag = 1;
			bzero(sem_error_msg, 100);
			strcat(sem_error_msg, "Redeclared function ");
			strcat(sem_error_msg, $2);
		}
		*/
	}
#line 1615 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 228 "compiler_hw2.y" /* yacc.c:1646  */
    {
		int index = lookup_symbol((yyvsp[-3].string_val), "insert"); 
		if(index != -1) {
			char attr[100];
			bzero(attr, 100);
			int flag = 0;
			for(int i=0;i<30;i++) {
				if(global_table[table_num+1].table[i].index != -1) {
					if(!strcmp(global_table[table_num+1].table[i].kind, "parameter")) {
						if(flag == 1) {
							strcat(attr, ", ");
						}
						strcat(attr, global_table[table_num+1].table[i].type);
						flag = 1;
					}
				}
				else break;
			}
			insert_symbol((yyvsp[-3].string_val), "function", (yyvsp[-4].string_val), attr, index);
		}
		if(func_flag == 1) {
			int index = lookup_func_table((yyvsp[-3].string_val));
			if(index == 2) {
				error_flag = 1;
				bzero(sem_error_msg, 100);
				strcat(sem_error_msg, "Redeclared function ");
				strcat(sem_error_msg, (yyvsp[-3].string_val));
			}
			else insert_func_table((yyvsp[-3].string_val));
			func_flag = 0;
		}
	}
#line 1652 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 264 "compiler_hw2.y" /* yacc.c:1646  */
    {
		int index = lookup_symbol((yyvsp[0].string_val), "insert"); 
		if(index != -1) {
			insert_symbol((yyvsp[0].string_val), "parameter", (yyvsp[-1].string_val), "\0", index);
		}
	}
#line 1663 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 271 "compiler_hw2.y" /* yacc.c:1646  */
    {
		int index = lookup_symbol((yyvsp[0].string_val), "insert"); 
		if(index != -1) {
			insert_symbol((yyvsp[0].string_val), "parameter", (yyvsp[-1].string_val), "\0", index);
		}
	}
#line 1674 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 291 "compiler_hw2.y" /* yacc.c:1646  */
    {
		if(lookup_symbol((yyvsp[-3].string_val), "semantic") == -1) {
			error_flag = 1;
			bzero(sem_error_msg, 100);
			strcat(sem_error_msg, "Undeclared variable ");
			strcat(sem_error_msg, (yyvsp[-3].string_val));
		}
	}
#line 1687 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 300 "compiler_hw2.y" /* yacc.c:1646  */
    {
		if(lookup_symbol((yyvsp[-2].string_val), "semantic") == -1) {
			error_flag = 1;
			bzero(sem_error_msg, 100);
			strcat(sem_error_msg, "Undeclared variable ");
			strcat(sem_error_msg, (yyvsp[-2].string_val));
		}
	}
#line 1700 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 309 "compiler_hw2.y" /* yacc.c:1646  */
    { 
		if(lookup_symbol((yyvsp[-3].string_val), "semantic") == -1) {
			error_flag = 1;
			bzero(sem_error_msg, 100);
			strcat(sem_error_msg, "Undeclared function ");
			strcat(sem_error_msg, (yyvsp[-3].string_val));
		}
	}
#line 1713 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 317 "compiler_hw2.y" /* yacc.c:1646  */
    {
		if(lookup_symbol((yyvsp[-5].string_val), "semantic") == -1) {
			error_flag = 1;
			bzero(sem_error_msg, 100);
			strcat(sem_error_msg, "Undeclared variable ");
			strcat(sem_error_msg, (yyvsp[-5].string_val));
		}
	}
#line 1726 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 326 "compiler_hw2.y" /* yacc.c:1646  */
    {
		if(lookup_symbol((yyvsp[-3].string_val), "semantic") == -1) {
			error_flag = 1;
			bzero(sem_error_msg, 100);
			strcat(sem_error_msg, "Undeclared variable ");
			strcat(sem_error_msg, (yyvsp[-3].string_val));
		}
	}
#line 1739 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 361 "compiler_hw2.y" /* yacc.c:1646  */
    {
		if(lookup_symbol((yyvsp[0].string_val), "semantic") == -1) {
			error_flag = 1;
			bzero(sem_error_msg, 100);
			strcat(sem_error_msg, "Undeclared variable ");
			strcat(sem_error_msg, (yyvsp[0].string_val));
		}
	}
#line 1752 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 371 "compiler_hw2.y" /* yacc.c:1646  */
    {
		if(lookup_symbol((yyvsp[-1].string_val), "semantic") == -1) {
			error_flag = 1;
			bzero(sem_error_msg, 100);
			strcat(sem_error_msg, "Undeclared variable ");
			strcat(sem_error_msg, (yyvsp[-1].string_val));
		}
	}
#line 1765 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 380 "compiler_hw2.y" /* yacc.c:1646  */
    {
		if(lookup_symbol((yyvsp[-3].string_val), "semantic") == -1) {
			error_flag = 1;
			bzero(sem_error_msg, 100);
			strcat(sem_error_msg, "Undeclared function ");
			strcat(sem_error_msg, (yyvsp[-3].string_val));
		}
	}
#line 1778 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 391 "compiler_hw2.y" /* yacc.c:1646  */
    { table_num++; create_symbol(); }
#line 1784 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 392 "compiler_hw2.y" /* yacc.c:1646  */
    {
		dump_flag = 1; 
		clear_temp_table();
		fill_temp_table();
		table_num--;
	}
#line 1795 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 398 "compiler_hw2.y" /* yacc.c:1646  */
    { table_num++; create_symbol(); }
#line 1801 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 399 "compiler_hw2.y" /* yacc.c:1646  */
    {
		dump_flag = 1; 
		clear_temp_table();
		fill_temp_table();
		table_num--;
	}
#line 1812 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 413 "compiler_hw2.y" /* yacc.c:1646  */
    { table_num++; create_symbol(); }
#line 1818 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 414 "compiler_hw2.y" /* yacc.c:1646  */
    {
		dump_flag = 1; 
		clear_temp_table();
		fill_temp_table();
		table_num--;
	}
#line 1829 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 420 "compiler_hw2.y" /* yacc.c:1646  */
    { table_num++; create_symbol(); }
#line 1835 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 421 "compiler_hw2.y" /* yacc.c:1646  */
    {
		dump_flag = 1; 
		clear_temp_table();
		fill_temp_table();
		table_num--;
	}
#line 1846 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 455 "compiler_hw2.y" /* yacc.c:1646  */
    {
		if(lookup_symbol((yyvsp[-2].string_val), "semantic") == -1) {
			error_flag = 1;
			bzero(sem_error_msg, 100);
			strcat(sem_error_msg, "Undeclared variable ");
			strcat(sem_error_msg, (yyvsp[-2].string_val));
		}
	}
#line 1859 "y.tab.c" /* yacc.c:1646  */
    break;


#line 1863 "y.tab.c" /* yacc.c:1646  */
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
#line 499 "compiler_hw2.y" /* yacc.c:1906  */


/* C code section */
int main(int argc, char** argv)
{
    yylineno = 1;
	
	table_num = 0;
	create_symbol();
	init_func_table();

    yyparse();
	if(syntax_flag == 1) {
		if(error_flag == 1) {
			printf("%d: %s\n", yylineno, buf);
			semantic_error(sem_error_msg, yylineno);
		}
		syntax_error(syn_error_msg);
	}
	if(syntax_flag == 0) {
		dump_symbol(0);
		printf("\nTotal lines: %d \n",yylineno-1);
	}
    return 0;
}

void yyerror(char *s)
{
	syntax_flag = 1;
	strcpy(syn_error_msg, s);
}

void syntax_error(char errormsg[100]) {
    printf("\n|-----------------------------------------------|\n");
    printf("| Error found in line %d: %s\n", yylineno, buf);
    printf("| %s", errormsg);
    printf("\n|-----------------------------------------------|\n\n");
}

void semantic_error(char errormsg[100], int sem_line) {
    printf("\n|-----------------------------------------------|\n");
    printf("| Error found in line %d: %s\n", sem_line, buf);
    printf("| %s", errormsg);
    printf("\n|-----------------------------------------------|\n\n");	
}

void create_symbol() {
	for(int i;i<30;i++) {
		global_table[table_num].table[i].index = -1;
		strcpy(global_table[table_num].table[i].name, "\0");
		strcpy(global_table[table_num].table[i].kind, "\0");
		strcpy(global_table[table_num].table[i].type, "\0");
		global_table[table_num].table[i].scope = table_num;
		strcpy(global_table[table_num].table[i].attribute, "\0");
	}
}
void insert_symbol(char name[], char kind[], char type[], char attribute[], int index) {
	global_table[table_num].table[index].index = index;
	strcpy(global_table[table_num].table[index].name, name);
	strcpy(global_table[table_num].table[index].kind, kind);
	strcpy(global_table[table_num].table[index].type, type);
	global_table[table_num].table[index].scope = table_num;
	strcpy(global_table[table_num].table[index].attribute, attribute);
}
int lookup_symbol(char name[], char type[]) {
	if(!strcmp(type, "insert")) {
		int i;
		// redeclard variable, return -1
		for(i=0;i<30;i++) {
			if(!strcmp(global_table[table_num].table[i].name, name)) {
				return -1;
			}
		}
		for(i=0;i<30;i++) {
			if(global_table[table_num].table[i].index == -1) {
				strcpy(global_table[table_num].table[i].name, name);
				return i;
			}
		}
	}
	else {
		// undeclared variable, return -1 
		int i;
		for (int j=0;j<=table_num;j++) {
			for(i=0;i<30;i++) {
				if(!strcmp(global_table[j].table[i].name, name)) {
					return 1;
				}
			}
		}
		return -1;
	}
}
void dump_symbol(int scope) {
	if(scope == 0) {
		if(global_table[0].table[0].index != -1) {
			printf("\n%-10s%-10s%-12s%-10s%-10s%-10s\n\n",
					"Index", "Name", "Kind", "Type", "Scope", "Attribute");
		}
		int has = 0;
		for(int i=0;i<30;i++) {
			if(global_table[0].table[i].index != -1) {
				has = 1;
				printf("%-10d%-10s%-12s%-10s%-10d%-s\n",
						global_table[0].table[i].index, 
						global_table[0].table[i].name, 
						global_table[0].table[i].kind, 
						global_table[0].table[i].type, 
						global_table[0].table[i].scope, 
						global_table[0].table[i].attribute);
				continue;
			}
			if(has == 1) printf("\n");
			break;
		}
	}
	else {
		if(temp_dump_table.table[0].index != -1) {
			printf("\n%-10s%-10s%-12s%-10s%-10s%-10s\n\n",
					"Index", "Name", "Kind", "Type", "Scope", "Attribute");
		}
		int has = 0;
		for(int i=0;i<30;i++) {
			if(temp_dump_table.table[i].index != -1) {
				has = 1;
				printf("%-10d%-10s%-12s%-10s%-10d%-s\n",
						temp_dump_table.table[i].index, 
						temp_dump_table.table[i].name, 
						temp_dump_table.table[i].kind, 
						temp_dump_table.table[i].type, 
						temp_dump_table.table[i].scope, 
						temp_dump_table.table[i].attribute);
				continue;
			}
			if(has == 1) printf("\n");
			break;
		}
	}
}

void clear_temp_table() {
	for(int i=0;i<30;i++) {
		temp_dump_table.table[i].index = -1;
		strcpy(temp_dump_table.table[i].name, "\0");
		strcpy(temp_dump_table.table[i].kind, "\0");
		strcpy(temp_dump_table.table[i].type, "\0");
		temp_dump_table.table[i].scope = table_num;
		strcpy(temp_dump_table.table[i].attribute, "\0");
	}
}

void fill_temp_table() {
	for(int i=0;i<30;i++) {
		temp_dump_table.table[i].index = global_table[table_num].table[i].index;
		strcpy(temp_dump_table.table[i].name, global_table[table_num].table[i].name);
		strcpy(temp_dump_table.table[i].kind, global_table[table_num].table[i].kind);
		strcpy(temp_dump_table.table[i].type, global_table[table_num].table[i].type);
		temp_dump_table.table[i].scope = table_num;
		strcpy(temp_dump_table.table[i].attribute, global_table[table_num].table[i].attribute);
	}
}

void init_func_table() {
	for(int i=0;i<30;i++) {
		implement_func_table[i].flag = -1;
	}
}

void insert_func_table(char name[]) {
	for(int i=0;i<30;i++) {
		if(!strcmp(implement_func_table[i].name, name)) {
			return;
		}
		if(implement_func_table[i].flag == -1) {
			strcpy(implement_func_table[i].name, name);
			implement_func_table[i].flag = 1;
			return;
		}
	}
}

int lookup_func_table(char name[]) {
	for(int i=0;i<30;i++) {
		if(implement_func_table[i].flag == -1) {
			return 1;
		}
		if(!strcmp(implement_func_table[i].name, name)) {
			return 2;
		}
	}
}
