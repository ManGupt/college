%{
#include<stdio.h>
%}
%token NUM
%left '+' '-'
%left '*' '/'
%%
prog	:prog stmnt '\n'
	|
	;
stmnt	:expr '=' {printf("%d\n",$1);}
	;
expr	:NUM
	|expr '+' expr {$$ = $1 + $3;}
	|expr '-' expr {$$ = $1 - $3;}
	|expr '*' expr {$$ = $1 * $3;}
	|expr '/' expr {$$ = $1 / $3;}
	;
%%
int main(void) {
yyparse();
return 0;
}