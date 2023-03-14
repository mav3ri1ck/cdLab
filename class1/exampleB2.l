%{
#include<stdio.h>
%}

%%
[A-Z]+	{ECHO; printf("\n");}
[a-z]*	{printf("%s\n", yytext);}
.|\n	 ;
%%

int main() {
yylex();
}
