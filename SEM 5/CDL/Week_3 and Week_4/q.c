#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define FILEINPUT "input.txt"
struct token
{
    char lexeme[64];
    int row, col;
    int index;
    char returnType[20];
    char dataType[20];
    char tokenType[20];
    int argc;
    char type[20];
};

struct ListElement{
    struct token tkn;
    struct ListElement* next;
};

struct ListElement *TABLE[30];

void Initialize(){
    for(int i=0;i<30;i++){
        TABLE[i] = NULL;
    }
}

int hash(char* str){
    int sum = 0;
    for(int i=0;i<strlen(str);i++){
        sum += str[i];
    }
    return sum % 30;
}

int search(char* str){
    int val = hash(str);
    if(TABLE[val] == NULL)
        return 0;
    else{
        struct ListElement* cur = TABLE[val];
        while(cur){
            if(strcmp(cur->tkn.lexeme,str) == 0)
                return 1;
        }
    }
    return 0;
}

void display(){
    printf("SL.NO\tLEX_NAME\tRET_TYPE\tDAT_TYPE\tTOK_TYPE\tARGC\n");
    for(int i=0;i<30;i++){
        if(TABLE[i] == NULL)
            continue;
        else{
            struct ListElement * ele= TABLE[i];
            while(ele){
                printf("%d\t%s\t\t%s\t\t%s\t\t%s\t\t%d\n",ele->tkn.index,ele->tkn.lexeme,ele->tkn.returnType,ele->tkn.dataType,ele->tkn.tokenType,ele->tkn.argc);
                ele = ele->next; 
            }   
        }
    }
}

void insert(struct token tk){
    if(search(tk.lexeme)==1){
        return; 
    }
    int val = hash(tk.lexeme);
    struct ListElement* cur =(struct ListElement*)malloc(sizeof(struct ListElement));
    cur->tkn = tk;
    cur->next = NULL;
    if(TABLE[val]==NULL){
        TABLE[val] = cur;
    }
    else{
        struct ListElement * ele= TABLE[val];
        while(ele->next!=NULL){
            ele = ele->next; 
       }
    ele->next = cur;
    }
}
static int row = 1, col = 1;
char buf[024];
const char specialsymbols[] = {'?', ';', ':', ','};
const char *Keywords[] = {"const", "char", "int","float", "return", "for", "while", "do", "switch", "if", "else", "unsigned", "case", "break"};
const char *ReturnTypes[] = {"int","float","char","void"};
const char arithmeticsymbols[] = {'*','+','-','/'};
int isKeyword(const char *str)
{
    for (int i = 0; i < sizeof(Keywords) / sizeof(char *); i++)
    {
        if (strcmp(str, Keywords[i]) == 0)
            return 1;
    }
    return 0;
}

int isReturnType(const char *str)
{
    for (int i = 0; i < sizeof(ReturnTypes) / sizeof(char *); i++)
    {
        if (strcmp(str, ReturnTypes[i]) == 0)
            return 1;
    }
    return 0;
}
int charBelongsTo(int c, const char *arr)
{
    int len;
    if (arr == specialsymbols)
        len = sizeof(specialsymbols) / sizeof(char);
    else if (arr == arithmeticsymbols)
        len = sizeof(arithmeticsymbols) / sizeof(char);
    for (int i = 0; i < len; i++)
    {
        if (c == arr[i])
            return 1;
    }
    return 0;
}
void fillToken(struct token *tkn, char c, int row, int col, char *type)
{
    tkn->row = row;
    tkn->col = col;
    strcpy(tkn->type, type);
    tkn->lexeme[0] = c;
    tkn->lexeme[1] = '\0';
}
void newLine()
{
    printf("\n");
    ++row;
    col = 1;
}
struct token getNextToken(FILE *fin)
{
    int c;
    struct token tkn = {.row = -1};
    int gotToken = 0;
    while (!gotToken && (c = fgetc(fin)) != EOF)
    {
        if (charBelongsTo(c, specialsymbols))
        {
            switch(c){
                case ';':
                
                    fillToken(&tkn, c, row, col, ";");
                    break;
                case ':':
                
                    fillToken(&tkn, c, row, col, ":");
                    break;
                case '?':
                
                    fillToken(&tkn, c, row, col, "?");
                    break;
                case ',':
                
                    fillToken(&tkn, c, row, col, ",");
                    break;
                default : break;
                
            }
            // fillToken(&tkn, c, row, col,"SS");
            gotToken = 1;
            ++col;
        }
        else if (charBelongsTo(c, arithmeticsymbols))

        { 
            switch(c){
                case '+':
                
                    fillToken(&tkn, c, row, col, "+");
                    break;
                case '-':
                
                    fillToken(&tkn, c, row, col, "-");
                    break;
                case '*':
                
                    fillToken(&tkn, c, row, col, "*");
                    break;
                case '/':
                
                    fillToken(&tkn, c, row, col, "/");
                    break;
                default : break;
                
            }
            // fillToken(&tkn, c, row, col, "ArithmeticOperator");
            gotToken = 1;
            ++col;
        }
        else if (c == '(')
        {
            fillToken(&tkn, c, row, col, "(");
            gotToken = 1;
            ++col;
        }
        else if (c == ')')
        {
            fillToken(&tkn, c, row, col, ")");
            gotToken = 1;
            ++col;
        }
        else if (c == '{')
        {
            fillToken(&tkn, c, row, col, "{");
            gotToken = 1;
            ++col;
        }
        else if (c == '}')
        {
            fillToken(&tkn, c, row, col, "}");
            gotToken = 1;
            ++col;
        }
        else if (c == '+')
        {
            int d = fgetc(fin);
            if (d != '+')
            {
                fillToken(&tkn, c, row, col, "+");
                gotToken = 1;
                ++col;
                fseek(fin, -1, SEEK_CUR);
            }
            else
            {
                fillToken(&tkn, c, row, col, "++");
                strcpy(tkn.lexeme, "++");
                gotToken = 1;
                col += 2;
            }
        }
        else if (c == '-')
        {
            int d = fgetc(fin);
            if (d != '-')
            {
                fillToken(&tkn, c, row, col, "-");
                gotToken = 1;
                ++col;
                fseek(fin, -1, SEEK_CUR);
            }
            else
            {
                fillToken(&tkn, c, row, col, "--");
                strcpy(tkn.lexeme, "--");
                gotToken = 1;
                col += 2;
            }
        }
        else if (c == '=')
        {
            int d = fgetc(fin);
            if (d != '=')
            {
                fillToken(&tkn, c, row, col, "=");
                gotToken = 1;
                ++col;
                fseek(fin, -1, SEEK_CUR);
            }
            else
            {
                fillToken(&tkn, c, row, col, "==");
                strcpy(tkn.lexeme, "==");
                gotToken = 1;
                col += 2;
            }
        }
        else if (isdigit(c))
        {
            tkn.row = row;
            tkn.col = col++;
            tkn.lexeme[0] = c;
            int k = 1;
            while ((c = fgetc(fin)) != EOF && isdigit(c))
            {
                tkn.lexeme[k++] = c;
                col++;
            }
            tkn.lexeme[k] = '\0';
            strcpy(tkn.type, "Number");
            gotToken = 1;
            fseek(fin, -1, SEEK_CUR);
        }
        else if (c == '#')
        {
            while ((c = fgetc(fin)) != EOF && c != '\n')
                ;
            newLine();
        }
        else if (c == '\n')
        {
            newLine();
            c = fgetc(fin);
            if (c == '#')
            {
                while ((c = fgetc(fin)) != EOF && c != '\n')
                    ;
                newLine();
            }
            else if (c != EOF)
                fseek(fin, -1, SEEK_CUR);
        }
        else if (isspace(c))
            ++col;
        else if (isalpha(c) || c == '_')
        {
            tkn.row = row;
            tkn.col = col++;
            tkn.lexeme[0] = c;
            int k = 1;
            while ((c = fgetc(fin)) != EOF && isalnum(c))
            {
                tkn.lexeme[k++] = c;
                ++col;
            }
            tkn.lexeme[k] = '\0';
            if (isKeyword(tkn.lexeme))
                strcpy(tkn.type, "Keyword");
            else
                strcpy(tkn.type, "Identifier");
            gotToken = 1;
            fseek(fin, -1, SEEK_CUR);
        }
        else if (c == '/')
        {
            int d = fgetc(fin);
            ++col;
            if (d == '/')
            {
                while ((c = fgetc(fin)) != EOF && c != '\n')
                    ++col;
                if (c == '\n')
                    newLine();
            }
            else if (d == '*')
            {
                do
                {
                    if (d == '\n')
                        newLine();
                    while ((c == fgetc(fin)) != EOF && c != '*')
                    {
                        ++col;
                        if (c == '\n')
                            newLine();
                    }
                    ++col;
                } while ((d == fgetc(fin)) != EOF && d != '/' && (++col));
                ++col;
            }
            else
            {
                fillToken(&tkn, c, row, --col, "/");
                gotToken = 1;
                fseek(fin, -1, SEEK_CUR);
            }
        }
        else if (c == '"')
        {
            tkn.row = row;
            tkn.col = col;
            strcpy(tkn.type, "StringLiteral");
            int k = 1;
            tkn.lexeme[0] = '"';
            while ((c = fgetc(fin)) != EOF && c != '"')
            {
                tkn.lexeme[k++] = c;
                ++col;
            }
            tkn.lexeme[k] = '"';
            gotToken = 1;
        }
        else if (c == '<' || c == '>' || c == '!')
        {
            switch(c){
                case '>':
                
                    fillToken(&tkn, c, row, col, ">");
                    break;
                case '<':
                
                    fillToken(&tkn, c, row, col, "<");
                    break;
                case '!':
                
                    fillToken(&tkn, c, row, col, "!");
                    break;
                default : break;
                
            }
            // fillToken(&tkn, c, row, col, "RelationalOperator");
            ++col;
            int d = fgetc(fin);
            if (d == '=')
            {
                ++col;
                strcat(tkn.lexeme, "=");
            }
            else
            {
                if (c == '!')
                    strcpy(tkn.type, "!=");
                fseek(fin, -1, SEEK_CUR);
            }
            gotToken = 1;
        }
        else if (c == '&' || c == '|')
        {
            int d = fgetc(fin);
            if (c == d)
            {
                tkn.lexeme[0] = tkn.lexeme[1] = c;
                tkn.lexeme[2] = '\0';
                tkn.row = row;
                tkn.col = col;
                ++col;
                gotToken = 1;
                switch(c){
                case '&':
                
                    fillToken(&tkn, c, row, col, "&&");
                    break;
                case '|':
                
                    fillToken(&tkn, c, row, col, "||");
                    break;
                default : break;
                
            }
                // strcpy(tkn.type, "LogicalOperator");
            }
            else
                fseek(fin, -1, SEEK_CUR);
            ++col;
        }
        else
            ++col;
    }
    return tkn;
}

void printToken(struct token* tkn,int* index){
    if(strcmp(tkn->type,"Identifier") == 0 ){
        char id[10];
        if(search(tkn->lexeme) == 0){
            tkn->index = *index;
            (*index)++;
        }
        else{
            struct ListElement* cur = TABLE[hash(tkn->lexeme)];
            while(cur){
                if(strcmp(cur->tkn.lexeme,tkn->lexeme) == 0){
                    tkn->index = cur->tkn.index;
                    break;
                }
                cur = cur->next;
            }
        }
        sprintf(id,"id%d",tkn->index);
        printf("<%s,%d,%d>",id,tkn->row,tkn->col);
        return;
    }
    printf("<%s,%d,%d>",tkn->lexeme,tkn->row,tkn->col);
}

void insertToST(struct token tkn,char* type,char* recTypetkn,int argc){
    if(strcmp(tkn.type,"Identifier") == 0){
        if(strcmp(type,"VAR") == 0){
            tkn.argc = 0;
            strcpy(tkn.returnType,"-");
            strcpy(tkn.tokenType,type);
            strcpy(tkn.dataType,recTypetkn);
            insert(tkn);
        }
        else{
            tkn.argc = argc;
            strcpy(tkn.returnType,recTypetkn);
            strcpy(tkn.tokenType,type);
            strcpy(tkn.dataType,"-");
            insert(tkn);
        }
    }
}

int main(){
    FILE* fp;
    fp = fopen("input.txt","r");
    if(fp == NULL){
        printf("ERROR\n");
        exit(0);
    }
    char recTypetkn[20];
    struct token prevtkn;
    struct token curtkn;
    int index = 1;
    int argc = 0;
    char id[10];
    Initialize();
    while((curtkn = getNextToken(fp)).row != -1){
        
        printToken(&curtkn,&index);

        //Symbol Table
        if(isReturnType(curtkn.lexeme)){
            strcpy(recTypetkn,curtkn.lexeme);
        }
        if(strcmp(prevtkn.type,"Identifier") == 0){
            if(strcmp(curtkn.lexeme,"(") == 0){
                if(strcmp((curtkn = getNextToken(fp)).lexeme,")")==0){
                    printToken(&curtkn,&index);
                    argc = 0;
                }
                else{
                    printToken(&curtkn,&index);
                    argc = 1;
                    while(strcmp((curtkn = getNextToken(fp)).lexeme,")")!=0){
                        printToken(&curtkn,&index);
                        if(isReturnType(curtkn.lexeme)){
                            strcpy(recTypetkn,curtkn.lexeme);
                        }
                        insertToST(curtkn,"VAR",recTypetkn,0);
                        if(strcmp(curtkn.lexeme,",") == 0){
                            argc++;
                        }
                    }
                }
                insertToST(prevtkn,"FUNC",recTypetkn,argc);
            }
            else{
                insertToST(prevtkn,"VAR",recTypetkn,0);
            }
        }
        prevtkn = curtkn;
    }
    printf("\n");
    display();
}