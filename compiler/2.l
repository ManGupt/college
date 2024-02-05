%{
#include"y.tab.h"
%}
D	[0-9]
A	[a-zA-Z]
id	{A}({A}|{D})*
%%
int|float|char	{return TYPE;}
if		{return IF;}
else		{return ELSE;}
for|while	{return LOOP;}
{D}* 		{return NUM;}
{id}		{return ALPHA;}
[ \t]*		{}
[-+()=/*\n] 	{return *yytext;}
[;,{}><]	{return *yytext;}
%%