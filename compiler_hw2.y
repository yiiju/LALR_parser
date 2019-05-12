/*	Definition section */
%{
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

extern int yylineno;
extern int yylex();
extern void yyerror(char *s);
extern char* yytext;   // Get current token from lex
extern char buf[256];  // Get current code line from lex

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

int lookup_symbol(char[]);
void create_symbol();
void insert_symbol(char[], char[], char[], char[]);
void dump_symbol();

struct symbol* global_table[30];
int table_num;

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
%type <string_val> type
%type <string_val> ID INT FLOAT BOOL STRING VOID

/* Yacc will start at this nonterminal */
%start program

/* Grammar section */
%%

program
    : program stat
    |
;

stat
    : type ID declaration
    | expression
	| iteration_stat
    | print_func
	| comment_stat
	| RET return_stat
;

return_stat
	: initializer
	| expression_stat
;

func
	: func_declaration RB func_end
	| RB LCB mul_stat RCB
;

func_end
	: SEMICOLON
	| LCB mul_stat RCB
;

declaration
    : ASGN initializer SEMICOLON 
	/*
	{
		int hasSymbol = lookup_symbol($1); 
		if(hasSymbol == 1) {
			insert_symbol($2, "variable", $1, "\0");
			printf("//%s//\n",$2);
		}
	}
	*/
    | SEMICOLON
	| ASGN expression_stat SEMICOLON
	| LB func
;

func_declaration
	: func_declaration COMMA type ID
	| type ID
	/*
	{
		int hasSymbol = lookup_symbol($1); 
			printf("//%s//\n",$2);
		if(hasSymbol == 1) {
			printf("//%s//\n",$2);
			insert_symbol($2, "parameter", $1, "\0");
		}
	}
	*/
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
	| IF LB iter_expression RB LCB mul_stat RCB haselse
;

haselse
	: ELSE haselseif LCB mul_stat RCB
	| 
;

haselseif
	: IF LB iter_expression RB LCB mul_stat RCB moreelseif
	| 
;

moreelseif
	: ELSE haselseif
	|
;

iter_expression
	: I_CONST 
	| ID relational factor 
;

mul_stat
	: stat mul_stat
	| stat
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
	: PRINT LB print_type
;

print_type
	: S_CONST RB SEMICOLON
	| ID RB SEMICOLON
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

void create_symbol() {
	struct symbol new_table[30];
	for(int i;i<30;i++) new_table[i].index = -1;
	global_table[table_num] = new_table;
	printf("creat_symbol:\n");
}
void insert_symbol(char name[], char kind[], char type[], char attribute[]) {
	struct symbol new_entry;
	strcpy(new_entry.name, name);
	strcpy(new_entry.kind, kind);
	strcpy(new_entry.type, type);
	new_entry.scope = table_num;
	strcpy(new_entry.attribute, attribute);
	int index = 0;
	for(int i=0;i<30;i++) {
		if(global_table[table_num][i].index == -1) {
			index = i;
			break;
		}
	}
	new_entry.index = index;
}
int lookup_symbol(char name[]) {
	printf("lookup:%s\n",name);
	printf("lookup:%d %p\n",table_num, global_table[table_num]);
	for(int i=0;i<30;i++) {
		if(!strcmp(global_table[table_num][i].name, name)) {
			return 1;
		}
	}
	return 2;
}
void dump_symbol() {
	if(global_table[table_num][0].index != -1) {
    	printf("\n%-10s%-10s%-12s%-10s%-10s%-10s\n\n",
           "Index", "Name", "Kind", "Type", "Scope", "Attribute");
	}
	for(int i=0;i<30;i++)	{
		if(global_table[table_num][i].index != -1) {
			printf("%-10d%-10s%-12s%-10s%-10d%-10s\n",
					global_table[table_num][i].index, global_table[table_num][i].name, 
					global_table[table_num][i].kind, global_table[table_num][i].type, 
					global_table[table_num][i].scope, global_table[table_num][i].attribute);
			continue;
		}
		break;
	}
	table_num++;
}
