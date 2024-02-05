%{
#include<stdio.h>
#include<stdlib.h>
#include "y.tab.h"
%}
ws	[ \t\n\r]
digit	[0-9]
alpha	[A-Za-z]
num	{digit}+
id	{alpha}({alpha}|{digit})*
ops	[+\-*/\%\\\^]
%%
int|float|char	{printf("Data-Type:%s",yytext);}
if|else		{printf("Conditional:%s",yytext);}
switch|case	{printf("Conditional:%s",yytext);}
for		{printf("Loop:%s",yytext);}
{ws}*		{printf(" ");}
{id}		{printf("Identifier:%s",yytext);}
{num}		{printf("Number:%s",yytext);}
[()\[\]{}]|{ops}{printf("Operator:%s",yytext);}
.		{printf("Error:%s",yytext);}
%%
int main(){yylex();}