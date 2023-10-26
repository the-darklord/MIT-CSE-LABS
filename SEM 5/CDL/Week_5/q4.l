%{
	int p=0;
    int s=0;
%}

%%
"printf" {p++; fprintf(yyout, "%s","READ");}
"scanf" {s++; fprintf(yyout, "%s","WRITE");}
. {fprintf(yyout, "%s", yytext);}
%%

int yywrap()
{
	return 1;
}

int main()
{
	yyin=fopen("input.txt","r");
    yyout=fopen("output.txt","w+");
	yylex();
	printf("Printf's : %d\nScanf's : %d\n",p,s);
	fclose(yyin);
    fclose(yyout);
	return 0;
} 
