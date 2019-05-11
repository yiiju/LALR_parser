/*	Definition section */
%{
#include <stdio.h>
#include <stdbool.h>

extern int yylineno;
extern int yylex();
extern char* yytext;   // Get current token from lex
extern char buf[256];  // Get current code line from lex

/* Symbol table function - you can add new function if needed. */
int lookup_symbol();
void create_symbol();
void insert_symbol();
void dump_symbol();

%}

/* Use variable or self-defined structure to represent
 * nonterminal and token type
 */
%union {
    int i_val;
    double f_val;
    char* string_val;
//	bool bool_val;
}

/* Token without return */
%token INT FLOAT STRING BOOL VOID
%token ADD SUB MUL DIV MOD INC DEC
%token MT LT MTE LTE EQ NE
%token ASGN ADDASGN SUBASGN MULASGN DIVASGN MODASGN
%token AND OR NOT
%token LB RB LCB RCB LSB RSB COMMA
%token PRINT 
%token IF ELSE FOR WHILE
%token ID SEMICOLON
%token RET
%token START_COMMENT C_COMMENT C_COMMENT_N END_COMMENT CPLUS_COMMENT
%token NEWLINE TAB

/* Token with return, which need to sepcify type */
%token <i_val> I_CONST
%token <f_val> F_CONST
%token <string_val> S_CONST
%token <bool_val> TRUE
%token <bool_val> FALSE

/* Nonterminal with return, which need to sepcify type */
/*
%type <f_val> stat
*/
%type <string_val> INT
%type <string_val> FLOAT
%type <string_val> STRING
%type <string_val> BOOL
%type <string_val> type
%type <string_val> ID
%type <string_val> SEMICOLON
%type <string_val> stat
%type <string_val> declaration
%type <string_val> print_func
%type <string_val> comment_stat
%type <string_val> c_comment_stat
%type <string_val> END_COMMENT
%type <string_val> RCB
%type <string_val> while_expression

/* Yacc will start at this nonterminal */
%start program

/* Grammar section */
%%

program
    : program stat
    |
;

stat
    : tab declaration NEWLINE { printf("%d: %s", yylineno-1, $$); }
    | declaration NEWLINE { printf("%d: %s", yylineno-1, $$); }
    | tab expression NEWLINE { printf("%d: %s", yylineno-1, $$); }
    | expression NEWLINE { printf("%d: %s", yylineno-1, $$); }
	| tab iteration_stat NEWLINE
	| iteration_stat NEWLINE
    | tab print_func NEWLINE { printf("%d: %s", yylineno-1, $$); }
    | print_func NEWLINE { printf("%d: %s", yylineno-1, $$); }
	| tab comment_stat NEWLINE
	| comment_stat NEWLINE
	| NEWLINE { printf("%d:\n", yylineno-1); }
	/*
    | compound_stat
	*/
;

tab
	: TAB tab
	|
;

declaration
    : type ID ASGN initializer SEMICOLON
    | type ID SEMICOLON
	| type ID ASGN expression_stat SEMICOLON
	| type ID LB func_declaration RB SEMICOLON
;

func_declaration
	: func_declaration COMMA type ID
	| type ID
;

expression
	: ID asgn expression_stat SEMICOLON
	| SEMICOLON
;

expression_stat
	: expression_stat ADD mul_expression_stat
	| expression_stat SUB mul_expression_stat
	| mul_expression_stat
;

mul_expression_stat
	: mul_expression_stat MUL factor
	| mul_expression_stat DIV factor
	| mul_expression_stat MOD factor
	| factor
;

factor
	: I_CONST
	| F_CONST
	| ID
	| LB expression_stat RB
;

iteration_stat
	: WHILE LB while_expression RB LCB NEWLINE mul_stat RCB { printf("%d: %s\n", yylineno, $8); }
;

while_expression
	: I_CONST { printf("%d: while(%d) {\n", yylineno, $1); }
	| ID relational factor { printf("%d: while(%s) {\n", yylineno, $$); }
;

mul_stat
	: stat mul_stat
	|
;

relational
	: MT
	| LT
	| MTE
	| LTE
	| EQ
	| NE
;

print_func
	: PRINT LB S_CONST RB SEMICOLON
	| PRINT LB ID RB SEMICOLON
;

comment_stat
	: CPLUS_COMMENT { printf("%d: %s\n", yylineno, $$); }
	| c_comment_stat END_COMMENT { printf("%d: %s\n", yylineno, $2); }
;

c_comment_stat
	: C_COMMENT_N { printf("%d: %s", yylineno-1, $$); }
	| c_comment_stat c_comment_stat
	|
;

initializer
	: S_CONST
	| TRUE
	| FALSE
;

asgn
	: ASGN
	| ADDASGN
	| SUBASGN
	| MULASGN
	| DIVASGN
	| MODASGN
;

/* actions can be taken when meet the token or rule */
type
    : INT
    | FLOAT
    | BOOL
    | STRING
    | VOID
    /*
	: INT { $$ = $1; }
    | FLOAT { $$ = $1; }
    | BOOL  { $$ = $1; }
    | STRING { $$ = $1; }
    | VOID { $$ = $1; }
	*/
;

%%

/* C code section */
int main(int argc, char** argv)
{
    yylineno = 1;

    yyparse();
	printf("\nTotal lines: %d \n",yylineno);

    return 0;
}

void yyerror(char *s)
{
    printf("\n|-----------------------------------------------|\n");
    printf("| Error found in line %d: %s\n", yylineno, buf);
    printf("| %s", s);
    printf("\n|-----------------------------------------------|\n\n");
}

void create_symbol() {}
void insert_symbol() {}
int lookup_symbol() {}
void dump_symbol() {
    printf("\n%-10s%-10s%-12s%-10s%-10s%-10s\n\n",
           "Index", "Name", "Kind", "Type", "Scope", "Attribute");
}
