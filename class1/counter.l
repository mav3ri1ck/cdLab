%{
int num_words = 0;
%}

%%
\n	++num_words;
" "	++num_words;
.	 ;


%%

int main(){
yylex();
printf("Total number of words: %d\n", num_words);


}
