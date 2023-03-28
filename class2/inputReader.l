%{

%}

%%


%%


int main() {
	char fname[100];
	printf("Enter filename: );
	scanf("%s", fname);
	yyin = fopen(fname, "r+");
	yylex();
}

int yywrap(void) {
	return 1;
}
