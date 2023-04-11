%{
	int vtr = 0;
	int ctr = 0;
%}

%%
[ \t\n ]	{ECHO;}
[aeiouAEIOU]	{vtr++;}
[a-zA-Z]	{ctr++;}
%%

int main() {
	printf("Enter a string: ");
	yylex();
	printf("No. of vowels are %d\n", vtr);
	printf("No. of consonants are %d\n", ctr);
}

int yywrap(void) {
	return 1;
}
