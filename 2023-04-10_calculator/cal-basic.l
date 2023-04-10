%{
#include"cal-basic.tab.h"
#include<stdlib.h>
%}

%%
[0-9]+		{yylval = atoi(yytext); return(Number);}
"+"		{return(Plus);}
"-"		{return(Minus);}
"="		{return(Equal);}
[ \t\n]+ 	{;}
.		{printf("Unexpected Input %c\n", yytext[0]);}

%%



