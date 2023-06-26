%{
#include"y.tab.h"
#include<stdio.h>

int yywrap(void){return 1;}
%}


%%
[ \t\n]              /* Ignore whitespace */
"+"                  return PLUS;
"*"                  return TIMES;
"("                  return LPAREN;
")"                  return RPAREN;
"id"                 return ID;
.                    /* Ignore unrecognized characters */
%%

