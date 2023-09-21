#include<stdio.h>
#include<stdlib.h>

/*
Grammar

S-> a | > | ( T )
T-> T,S | S

Remove the left recursion

S-> a | > | ( T )
T -> STprime
Tprime-> ,STprime | e

*/

char str[100];
int curr = 0;

void valid();
void invalid();
void S();
void T();
void Tprime();

void valid(){
	printf("----------------SUCCESS!---------------\n");
	exit(0);
}

void invalid(){
	printf("-----------------ERROR!----------------\n");
	exit(0);
}


void S(){
	if(str[curr] == 'a'){
		curr++;
		return;
	}
	else if(str[curr] == '>'){
		curr++;
		return;
	}
	else if(str[curr] == '('){
		curr++;
		T();
		if(str[curr] == ')'){
			curr++;
			return;
		}
	}
}

void T(){
	S();
	Tprime();
}

void Tprime(){
	if(str[curr] == ','){
		curr++;
		S();
		Tprime();
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