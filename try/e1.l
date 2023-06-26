%{
#include<stdio.h>
%}

%%
begin   printf("Started");
end     printf("Stopped");
hi     printf("Hello");
%%

int yywrap(void) {
    return 1;
}

int main(){
    printf("Enter words\n");
    yylex();
}