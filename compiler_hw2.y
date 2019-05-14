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

struct scope
{
	struct symbol table[30];
};

int lookup_symbol(char[]);
void create_symbol();
void insert_symbol(char[], char[], char[], char[], int);
void dump_symbol(int);
int dump_flag;
int dump_scope;

struct scope global_table[40];
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
    : declaration 
    | expression
	| iteration_stat
    | print_func
	| comment_stat
	| RET return_stat
;

return_stat
	: initializer SEMICOLON
	| expression_stat SEMICOLON
;

func
	: func_parameter RB func_end
	| RB LCB mul_stat RCB { dump_flag = 1; dump_scope = table_num; table_num--; }
;

func_end
	: SEMICOLON
	| LCB mul_stat RCB { dump_flag = 1; dump_scope = table_num; table_num--; }
;

declaration
    : type ID ASGN initializer SEMICOLON 
	{
		int index = lookup_symbol($2); 
		if(index != -1) {
			insert_symbol($2, "variable", $1, "\0", index);
		}
	}
    | type ID SEMICOLON
	{
		int index = lookup_symbol($2); 
		if(index != -1) {
			insert_symbol($2, "variable", $1, "\0", index);
		}
	}
	| type ID ASGN expression_stat SEMICOLON
	{
		int index = lookup_symbol($2); 
		if(index != -1) {
			insert_symbol($2, "variable", $1, "\0", index);
		}
	}
	| type ID LB { table_num++; create_symbol(); } func
	{
		int index = lookup_symbol($2); 
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
			insert_symbol($2, "function", $1, attr, index);
		}
	}
;

func_parameter
	: func_parameter COMMA type ID
	{
		int index = lookup_symbol($4); 
		if(index != -1) {
			insert_symbol($4, "parameter", $3, "\0", index);
		}
	}
	| type ID
	{
		int index = lookup_symbol($2); 
		if(index != -1) {
			insert_symbol($2, "parameter", $1, "\0", index);
		}
	}
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
	: WHILE LB iter_expression RB LCB { table_num++; create_symbol(); } mul_stat RCB
	{
		dump_flag = 1; 
		dump_scope = table_num; 
		table_num--;
	}
	| IF LB iter_expression RB LCB { table_num++; create_symbol(); }  mul_stat RCB
	{
		dump_flag = 1; 
		dump_scope = table_num; 
		table_num--;
	} haselse
;

haselse
	: ELSE haselseif LCB { table_num++; create_symbol(); }  mul_stat RCB
	{
		dump_flag = 1; 
		dump_scope = table_num; 
		table_num--;
	}
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
	
	table_num = 0;
	create_symbol();

    yyparse();
	dump_symbol(0);
	printf("\nTotal lines: %d \n",yylineno-1);

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
	for(int i;i<30;i++) global_table[table_num].table[i].index = -1;
}
void insert_symbol(char name[], char kind[], char type[], char attribute[], int index) {
	global_table[table_num].table[index].index = index;
	strcpy(global_table[table_num].table[index].name, name);
	strcpy(global_table[table_num].table[index].kind, kind);
	strcpy(global_table[table_num].table[index].type, type);
	global_table[table_num].table[index].scope = table_num;
	strcpy(global_table[table_num].table[index].attribute, attribute);
	int i;
	for(i=0;i<30;i++) {
		if(global_table[table_num].table[i].index == -1) {
			index = i;
			break;
		}
	}
//	printf("insert_symbol:%d\n", table_num);
}
int lookup_symbol(char name[]) {
	//printf("lookup:%s\n",name);
	int i;
	for(i=0;i<30;i++) {
		if(!strcmp(global_table[table_num].table[i].name, name)) {
			return -1;
		}
	}
	for(i=0;i<30;i++) {
		if(global_table[table_num].table[i].index == -1) {
			strcpy(global_table[table_num].table[i].name, name);
	//		printf("lookup_symbol:%d\n", i);
			return i;
		}
	}
}
void dump_symbol(int scope) {
	if(global_table[scope].table[0].index != -1) {
    	printf("\n%-10s%-10s%-12s%-10s%-10s%-10s\n\n",
           "Index", "Name", "Kind", "Type", "Scope", "Attribute");
	}
	int has = 0;
	for(int i=0;i<30;i++) {
		if(global_table[scope].table[i].index != -1) {
			has = 1;
			printf("%-10d%-10s%-12s%-10s%-10d%-s\n",
					global_table[scope].table[i].index, 
					global_table[scope].table[i].name, 
					global_table[scope].table[i].kind, 
					global_table[scope].table[i].type, 
					global_table[scope].table[i].scope, 
					global_table[scope].table[i].attribute);
			continue;
		}
		if(has == 1) printf("\n");
		break;
	}
}
