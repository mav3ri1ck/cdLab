%{
#include<stdio.h>
%}

%%
[a-z]+	printf("Lowercase letter: %s \n", yytext);
[A-Z]+	printf("Uppercase letter\n");
[0-9]+	printf("Integer\n");
[0-9].[0-9]	printf("Float\n");
";"	printf("Semicolon\n");
"("	printf("Opening parentheses\n");
")"	printf("Closing parentheses\n");
%%
