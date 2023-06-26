%{
#include<stdio.h>
%}


%%
[a-z]+  ECHO;
.|\n    ;
%%

int yywrap(void) {
    return 1;
}

int main() {
    printf("Enter text: \n");
    yylex();
}