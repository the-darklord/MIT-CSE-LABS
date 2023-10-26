%{	
	#include<stdio.h>
%}

%%
"//"[A-Za-z" "]+\n {fprintf(yyout,"%s",yytext);}
"/*"[A-Za-z" "\n]+"*/" {fprintf(yyout,"%s",yytext);}
[A-Z] {fprintf(yyout,"%c",yytext[0]+32);}
. {fprintf(yyout,"%s",yytext);}
%%

int yywrap(){
	return 1;
}

int main(){
	yyin = fopen("input.txt","r");
	yyout = fopen("output.txt","w");
	yylex();
	fclose(yyin);
	fclose(yyout);
}