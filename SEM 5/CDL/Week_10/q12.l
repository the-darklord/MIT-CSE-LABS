%{
    #include "q12.tab.h"
%}

%%
\n {}
"int" {return INT;}
"char" {return CHAR;}
"main" {return MAIN;}
"(" {return FBL;}
")" {return FBR;}
"{" {return CBL;}
"}" {return CBR;}
"[" {return SBL;}
"]" {return SBR;}
"=" {return ASSIGN;}
"if" {return IF;}
"else" {return ELSE;}
"==" {return EQUAL;}
"!=" {return NOTEQUAL;}
"<=" {return LE;}
">=" {return GE;}
"<" {return LT;}
">" {return GT;}
"+" {return PLUS;}
"-" {return MINUS;}
"*" {return STAR;}
"/" {return DIV;}
"%" {return MOD;}
"while" {return WHILE;}
"for" {return FOR;}
[0-9]+ {return NUMBER;}
[a-zA-Z_]+ {return ID;}
";" {return SEMICOLON;}
"," {return COMMA;}
%%

int yywrap()
{
    return 1;
}