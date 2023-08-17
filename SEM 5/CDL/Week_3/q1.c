//Code Incomplete//
//Code Incomplete//
//Code Incomplete//
//Code Incomplete//
//Code Incomplete//


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Token{
	char token_name[10];
	int index;
	unsigned int row,col;
	char type[10];
}Token;

const char *keywords[] = {"for", "if", "else", "while", "do", "break", "continue", "return", "int", "double", "float", "char", "long", "short", "sizeof", "typedef", "switch", "case", "struct", "const", "void", "exit"};

int isKeyword(const char* str)
{
	for(int i = 0;i<sizeof(keywords)/sizeof(char*);i++)
    {
		if(strncmp(str,keywords[i],strlen(keywords[i])) == 0)
        {
		    return 1;
        }
	}
	return 0;
}

int revNum(int n)
{
    int sum=0;
    int rem;
    while(n>0)
    {
        rem=n%10;
        n=n/10;
        sum += 10*rem;
    }
    return sum;
}

void printToken(FILE* fo,Token t){
	unsigned int row,col;
	row = t.row;
	col = t.col;
	putc('<',fo);
	for(int i=0;i<strlen(t.token_name);i++){
		putc(t.token_name[i],fo);
	}	
	putc(',',fo);

	while(row > 0){
		unsigned int digit = row % 10;
		char c = digit + '0';
		putc(c,fo);
		row = row / 10;
	}
	putc(',',fo);
	while(col > 0){
		unsigned int digit = col % 10;
		char c = digit + '0';
		putc(c,fo);
		col = col / 10;
	}
	putc('>',fo);
}

int main(){
	FILE *fp,*fo;
	char c;
	int i=0;
	fp = fopen("test.c","r");
	fo = fopen("res.txt","w");
	if(fp == NULL){
		printf("\nCannot open\n");
	}
	c = getc(fp);
	int lineNo = 1;
	int colNo = 1;
	Token t;	
	char buf[10];
	while(c != EOF){
		if(isKeyword(buf)){
			strcpy(t.token_name,buf);
			t.row = lineNo;
			t.col = colNo;
			printToken(fo,t);
			i = 0;
			buf[i] = '\0'; 
		}
		else if(strcmp("main",buf) == 0){
			buf[i] = '\0'; 
			strcpy(t.token_name,buf);
			t.row = lineNo;
			t.col = colNo;
			printToken(fo,t); 
			i = 0;
			buf[i++] = c;
            buf[i]='\0';
            i=0;
            continue;
		}
		else if(c == ' '){
			colNo++;
			buf[i] = '\0';
			if(buf != "\0"){
				if(strcmp("int",buf) == 0){
					strcpy(t.token_name,buf);
					t.row = lineNo;
					t.col = colNo;
					printToken(fo,t);
					i = 0;
					buf[i] = '\0'; 
				}
				else{
					i = 0;
					strcpy(t.token_name,"id");
					t.row = lineNo;
					t.col = colNo;
					printToken(fo,t);
				}
			}
			i=0;
		}
		else if(c == '\n'){
			lineNo++;
			colNo = 1;
			buf[i] = '\0';
			i= 0;
			putc('\n',fo);
		}
		else if(c == ',' || c ==';'){
			colNo++;
			if(buf != "\0"){
				buf[i] = '\0';
				i = 0;
				strcpy(t.token_name,"id");
				t.row = lineNo;
				t.col = colNo;
				printToken(fo,t);
			}
			buf[i++] = c;
			buf[i] = '\0';
			i = 0;
			strcpy(t.token_name,buf);
			t.row = lineNo;
			t.col = colNo;
			printToken(fo,t);
			i = 0;
			buf[i] = '\0';
		}
		else if(c == '{' || c == '(' || c == '}' || c == ')'){
			colNo++;
			buf[i++] = c;
			buf[i] = '\0';
			i = 0;
			strcpy(t.token_name,buf);
			t.row = lineNo;
			t.col = colNo;
			printToken(fo,t);
            buf[i]='\0';
		}
		else if(c == '+' || c == '-' || c == '*' || c == '/'){
			colNo++;
			buf[i++] = c;
			buf[i] = '\0';
			i=0;
			strcpy(t.token_name,buf);
			t.row = lineNo;
			t.col = colNo;
			printToken(fo,t); 
            buf[i]='\0';
		}
		else if(c == '='){
            if(strlen(buf)!=0)
            {
                buf[i]='\0';
                strcpy(t.token_name,buf);
                t.row = lineNo;
                t.col = colNo;
                printToken(fo,t);
			    i = 0;
            }
			colNo++;
			buf[i++] = c;
			c = getc(fp);
			if(c == '='){
				colNo++;
				buf[i++] = c;
				buf[i] = '\0';
				i = 0;
			}
			else{
				buf[i] = '\0';
				i = 0;	
			}
			strcpy(t.token_name,buf);
			t.row = lineNo;
			t.col = colNo;
			printToken(fo,t);
			i = 0;
			buf[i] = '\0';
			continue;
		}
		else if(c == '<' || c == '>' || c == '!'){\
			colNo++;
			buf[i++] = c;
			c = getc(fp);
			if(c == '='){
				colNo++;
				buf[i++] = c;
				buf[i] = '\0';
				i = 0;
			}
			else{
				buf[i] = '\0';
				i = 0;
			}
			strcpy(t.token_name,buf);
			t.row = lineNo;
			t.col = colNo;
			printToken(fo,t);
			continue;
		}
		else if(c == '&'){
			colNo++;
			buf[i++] = c;
			c = getc(fp);
			if(c == '&'){
				colNo++;
				buf[i++] = c;
				buf[i] = '\0';
				i = 0;
			}
			else{
				buf[i] = '\0';
				i = 0;
			}
			strcpy(t.token_name,buf);
			t.row = lineNo;
			t.col = colNo;
			printToken(fo,t);
			continue;
		}
		else if(c == '|'){
			colNo++;
			buf[i++] = c;
			c = getc(fp);
			if(c == '|'){
				colNo++;
				buf[i++] = c;
				buf[i] = '\0';
				i = 0;
			}
			else{
				buf[i] = '\0';
				i = 0;
			}
			strcpy(t.token_name,buf);
			t.row = lineNo;
			t.col = colNo;
			printToken(fo,t);
			continue;
		}
		else if(c == '!'){
			colNo++;
			buf[i++] = c;
			buf[i] = '\0';
			i = 0;
			strcpy(t.token_name,buf);
			t.row = lineNo;
			t.col = colNo;
			printToken(fo,t);
		}
		else{
			colNo++;
			buf[i++] = c;
		}
		c = getc(fp);
	}
}