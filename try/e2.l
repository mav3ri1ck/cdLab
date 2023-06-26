%{
#include<stdio.h>
%}

%%
[a-z]+  printf("lower case letter\n");
[A-Z]+  printf("upper case letter\n");
[0-9.]+  printf("floating point number\n");
";"  printf("semicolon\n");
%%


int yywrap(void) {
    return 1;
}


int main() {
    printf("Enter your text: \n");
    yylex();
}