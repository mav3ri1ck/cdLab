%{
int yywrap(void) {return 1;}
int flag = 0, ln = 1;
%}

%%
"(" 	{flag++;}
")" 	{flag--;}
[\n] {
	if(flag == 0)
		printf("\nThe statement at line no %d has no missing parentheses. \n\n", ln);
	else
		printf("\nError at line number %d\n", ln);
	if(flag > 0)
		printf("The statement has either extra ( or missing )\n\n");
	else if(flag < 0)
		printf("The statement has either extra ) or missing (\n\n");
	flag  = 0;
	ln++;
}
%%

int main() {
	char fname[100];
	printf("Enter the name of the file: ");
	scanf("%s", fname);
	yyin = fopen(fname, "r+");
	yylex();
}
