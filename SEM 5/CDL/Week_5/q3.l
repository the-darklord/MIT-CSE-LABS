%{
	int pI=0;
	int nI=0;
    int pF=0;
    int nF=0;
%}

%%
[+]?[0-9]+ {pI++;}
[-][0-9]+ {nI++;}
[+]?[0-9]*"."[0-9]+ {pF++;}
[-][0-9]*"."[0-9]+ {nF++;}
%%

int yywrap()
{
	return 1;
}

int main()
{
	yyin=fopen("input.txt","r");
	yylex();
	printf("+ve Int : %d\n-ve Int : %d\n+ve Float : %d\n-ve Float : %d\n",pI,nI,pF,nF);
	fclose(yyin);
	return 0;
} 
