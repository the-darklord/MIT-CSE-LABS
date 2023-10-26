%{
	unsigned int num;
%}

%%
[0-9]+ {num=atol(yytext);printf("%X\n",num);}
. {}
%%

int yywrap()
{
	return 1;
}

int main()
{
	yyin=fopen("input.txt","r");
	yylex();
	fclose(yyin);
	return 0;
} 
