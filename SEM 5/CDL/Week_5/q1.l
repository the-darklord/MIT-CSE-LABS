%{
	int vC=0;
	int cC=0;
%}

%%
[aeiouAEIOU] {vC++;}
[b-df-hj-np-tv-zB-DF-HJ-NP-TV-Z] {cC++;}
%%

int yywrap()
{
	return 1;
}

int main()
{
	yyin=fopen("input.txt","r");
	yylex();
	printf("Number of vowels are: %d\n", vC);
	printf("Number of consonants are: %d\n", cC);
	fclose(yyin);
	return 0;
} 
