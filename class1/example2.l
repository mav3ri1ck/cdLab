%{

#undef yywrap
#define yywrap() 1

%}

%%

[\n] {
	printf("Hello World\n");	
}

	
%%

main()
{
	yylex(); //calling the rules section
}
