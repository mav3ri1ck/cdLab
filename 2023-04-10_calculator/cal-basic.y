%{ 
#include<stdio.h> 
#include<stdlib.h>
int yylex(void);
int yyerror(char* s);
%}


%token Plus Minus Multiply Divide Number Equal
%start input
%left Plus Minus Multiply Divide


%%
input : 
      | input line	{printf("The result is %d\n\n", $2);}
       
line : Equal
     | Exp Equal
     ;
Exp : Number
    | Exp Plus Exp {$$ = $1 + $3;}
    | Exp Minus Exp {$$ = $1 - $3;}
    | Exp Multiply Exp {$$ = $1 * $3;}
    | Exp Divide Exp { 
	if($3 != 0) {
		$$ = $1 / $3;
	} else {
		printf("Unable to divide by zero\n");
		exit(0);
	}
      }
	
%%

int yyerror(char* s) {printf("Galtiii!!\n");};

int yywrap() {return 1;}

int main(void) {
	yyparse();
}



