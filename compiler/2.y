%{
#include<stdio.h>
%}
%token NUM ALPHA TYPE IF ELSE LOOP
%%
prog	:prog func '\n' {printf("correct");}
	|'\n'
	|
	;
func	:def '(' para ')' '\n' '{' exprs '}'
	|'\n'
	;
cond	:ALPHA ops NUM
	|ALPHA ops ALPHA
	|NUM ops NUM
	|NUM ops ALPHA
	;
ops	:'=''='
	|'='
	|'<''='
	|'>''='
	|'<'
	|'>'
	;
def	:TYPE ALPHA
	;
para	:init
	|
	;
init	:def
	|init ',' init
	|ALPHA
	;
exprs	:exprs expr '\n'
	|exprs '\n'
	|
	;
expr	:NUM
	|init ';'
	|expr '+' expr ';'
	|expr '-' expr ';'
	|expr '*' expr ';'
	|expr '/' expr ';'
	|ALPHA '=' expr ';'
	|IF '(' cond ')' '{' exprs '}' ELSE '{' exprs '}'
	|IF '(' cond ')' '{' exprs '}'
	|';'
	;
%%
int main(void) {
yyparse();
return 0;
}