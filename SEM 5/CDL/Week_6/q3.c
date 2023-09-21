#include<stdio.h>
#include<stdlib.h>

/*
Grammar
S-> aAcBe
A-> Ab | b
B-> d

Remove left recursion

S-> aAcBe
A-> bAprime
Aprime-> bAprime | e
B-> d
	
*/

char str[100];
int curr = 0;

void valid();
void invalid();
void S();
void A();
void Aprime();
void B();

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
		A();
		if(str[curr] == 'c'){
			curr++;
			B();
			if(str[curr] == 'e'){
				curr++;
				return;
			}
		}
	}
}

void A(){
	if(str[curr] == 'b'){
		curr++;
		Aprime();
	}
}

void Aprime(){
	if(str[curr] == 'b'){
		curr++;
		Aprime();
	}
}

void B(){
	if(str[curr] == 'd'){
		curr++;
		return;
	}
	else{
		invalid();
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
S-> aAcBe
A-> bAprime
Aprime-> bAprime | e
B-> d


abbcde

*/