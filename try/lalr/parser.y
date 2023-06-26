%{
#include<stdio.h>
#include<stdlib.h>
int yylex();
void yyerror(char *);
%}
%token PLUS TIMES LPAREN RPAREN ID
%left PLUS TIMES



%%
S : E               { printf("Valid Expression\n"); exit(0);}
E : E PLUS T
  | T               
  ;
T : T TIMES F
  | F               
  ;
F : LPAREN E RPAREN 
  | ID              
  ;
%%


void yyerror(char *s) {
    printf("Error: %s\n", s);
}
int main() {
    yyparse();
    return 0;
}
