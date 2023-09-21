#include<stdio.h>
#include<stdlib.h>

/*
Grammar
S-> UVW
U-> (S) | aSb | d
V-> aV | e
W-> cW | e
*/

char str[100];
int curr = 0;

void valid();
void invalid();
void S();
void U();
void V();
void W();


void valid(){
	printf("----------------SUCCESS!---------------\n");
	exit(0);
}

void invalid(){
	printf("-----------------ERROR!----------------\n");
	exit(0);
}

void S(){
	U();
	V();
	W();
}

void U(){
	if(str[curr] == '('){
		curr++;
		S();
		if(str[curr] == ')'){
			curr++;
			return;
		}
	}
	else if(str[curr] == 'a'){
		curr++;
		S();
		if(str[curr] == 'b'){
			curr++;
			return;
		}
	}
	else if(str[curr] == 'd'){
		curr++;
		return;
	}
}

void V(){
	if(str[curr] == 'a'){
		curr++;
		V();
	}
}

void W(){
	if(str[curr] == 'c'){
		curr++;
		W();
	}
}

int main(){
	printf("Enter String: ");
	scanf("%s", str);
	S();
	if(str[curr] == '$')
		valid();
	else
		invalid();
}


/*

(d)ac

*/