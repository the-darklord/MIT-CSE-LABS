%{
    #include <stdio.h>
    #include <stdlib.h>
    int yylex();
    int yyerror();
    extern FILE* yyin;
%}

%token INT CHAR ID NUMBER MAIN
%token FBL FBR CBL CBR SBL SBR
%token COMMA SEMICOLON
%token ASSIGN
%token IF ELSE
%token EQUAL NOTEQUAL LE GE LT GT
%token PLUS MINUS STAR DIV MOD
%token WHILE FOR

%%
    program : MAIN FBL FBR CBL declarations statementList CBR ;
    declarations : dataType identifierList SEMICOLON declarations | ;
    dataType : INT | CHAR ;
    identifierList : ID | ID COMMA identifierList | ID SBL NUMBER SBR COMMA identifierList | ID SBL NUMBER SBR ;
    statementList : statement statementList | ;
    statement : assignStat SEMICOLON | decisionStat | loopingStat ;
    assignStat : ID ASSIGN expn ;
    expn : simpleExpn eprime ;
    eprime : relop simpleExpn | ;
    simpleExpn : term sePrime ;
    sePrime : addOp term sePrime | ;
    term : factor tPrime ;
    tPrime : mulOp factor tPrime | ;
    factor : ID | NUMBER ;
    decisionStat : IF FBL expn FBR CBL statementList CBR dPrime ;
    dPrime : ELSE CBL statementList CBR | ;
    loopingStat : WHILE FBL expn FBR CBL statementList CBR | FOR FBL assignStat SEMICOLON expn SEMICOLON assignStat FBR CBL statementList CBR ;
    relop : EQUAL | NOTEQUAL | LE | GE | LT | GT ;
    addOp : PLUS | MINUS ;
    mulOp : STAR | DIV | MOD ;
%%

int yyerror(char* msg)
{
    printf("Error !!!\n%s\n",msg);
    exit(1);
}

void main(int argc, char** argv)
{
    yyin = fopen(argv[1],"r");
    if(!yyin)
    {
        yyerror("File Error\n");
    }
    do
    {
        if(yyparse())
        {
            printf("\n Failed\n");
        }
    }while(!feof(yyin));
    printf("\n Success\n");
}