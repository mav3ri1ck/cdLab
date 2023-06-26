%{
int num_lines = 0, num_chars = 0;
%}


%%
\n  ++num_lines; ++num_chars;
.   ++num_chars;
%%

int yywrap(void) {
    return 1;

}


int main() {
    printf("Enter input as line:\n");
    yylex();
    printf("Number of lines: %d\n", num_lines);
    printf("Number of characters: %d\n", num_chars);
}