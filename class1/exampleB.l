%{
#include<stdio.h>
%}

%%
begin	{printf("Started\n");}
hello	{printf("Hello yourself!\n");}
thanks	{printf("You are welcome\n");}
morning	{printf("Good Morning\n");}
hi	{printf("Hello\n");}
end	{printf("Changed the stopped\n");}
%%


int yywrap(){}

int main(){yylineno = 1; yylex();}
