%{
#include<stdio.h>
%}


%%
for |
while |
do |
if |
else |
printf		printf("%s is a keyword\n", yytext);
[a-zA-Z]	printf("%s is a word\n", yytext);
[0-9]		printf("%s is a number\n", yytext);
%%

int main() {
	yylex();
}

int yywrap(void) {
	return 1;
}
