%{
	int wC=0;
	int cC=0;
    int lC=0;
    int bC=0;
%}

%%
[a-zA-Z]+ {wC++; cC += yyleng;}
\n {lC++;cC++;}
\t {bC++;cC++;}
" " {bC++;cC++;}
. {cC++;}
%%

int yywrap()
{
	return 1;
}

int main()
{
	yyin=fopen("input.txt","r");
	yylex();
	printf("Character : %d\nWords : %d\nBlanks : %d\nLines : %d\n",cC,wC,bC,lC);
	fclose(yyin);
	return 0;
} 
