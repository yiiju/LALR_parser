/*	Definition section */
%{
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

extern int yylineno;
extern int yylex();
extern void yyerror(char *s);
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
%token START_COMMENT END_COMMENT CPLUS_COMMENT

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

/* Yacc will start at this nonterminal */
%start program

/* Grammar section */
%%

program
    : program stat
    |
;

stat
    : declaration
    | expression
	| iteration_stat
    | print_func
	| comment_stat
    | compound_stat
	| return_stat
;

return_stat
	: RET initializer
	| RET expression_stat
;

compound_stat
	: type ID LB func_declaration RB LCB mul_stat RCB
	| type ID LB RB LCB mul_stat RCB
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

func_call
	: func_call COMMA const
	| const
;

const
	: I_CONST
	| F_CONST
	| S_CONST
	| ID
;

expression
	: ID asgn expression_stat SEMICOLON
	| ID arithmetic_postfix SEMICOLON
	| ID LB func_call RB SEMICOLON
	| ID LB RB SEMICOLON
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
	| ID arithmetic_postfix
;

iteration_stat
	: WHILE LB iter_expression RB LCB mul_stat RCB 
	| IF LB iter_expression RB LCB mul_stat RCB 
	| IF LB iter_expression RB LCB mul_stat RCB ELSE else_stat
	| IF LB iter_expression RB LCB mul_stat RCB ELSE elseif_stat else_stat
;

iter_expression
	: I_CONST 
	| ID relational factor 
;

mul_stat
	: stat mul_stat
	| stat
;

elseif_stat
	: IF LB iter_expression RB LCB mul_stat RCB ELSE elseif_stat
	| IF LB iter_expression RB LCB mul_stat RCB ELSE
;

else_stat
	: LCB mul_stat RCB 
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
	: CPLUS_COMMENT 
	| START_COMMENT END_COMMENT
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

arithmetic_postfix
	: INC
	| DEC
;

/* actions can be taken when meet the token or rule */
type
    : INT
    | FLOAT
    | BOOL
    | STRING
    | VOID
;

%%

/* C code section */
int main(int argc, char** argv)
{
    yylineno = 1;

	printf("1: ");
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
