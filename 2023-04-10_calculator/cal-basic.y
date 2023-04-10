%{ 
#include<stdio.h> 
int yylex(void);
int yyerror(char* s);
%}


%token Plus Minus Number Equal
%start input
%left Plus Minus


%%
input : 
      | input line	{printf("The result is %d", $2);}
line : Equal
     | Exp Equal
     ;
Exp : Number
    | Exp Plus Exp {$$ = $1 + $3;}
    | Exp Minus Exp {$$ = $1 - $3;}

%%

int yyerror(char* s) {printf("Galtiii!!\n");};

int yywrap() {return 1;}

int main(void) {
	yyparse();
}



