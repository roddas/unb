#include<bits/stdc++.h>

using namespace std;

char lookahead;

void reconhecer(char);
char next_char(void);

int main(void){
	
	return 0;
}

void reconhecer(char token){
	if(lookahead == token)
		lookahead = next_char();
	else
		erro();
}
char next_char(void){
	return getchar();
}
