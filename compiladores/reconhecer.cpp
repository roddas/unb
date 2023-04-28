#include<bits/stdc++.h>

using namespace std;

char lookahead;

void reconhecer(char);

int main(void){
	
	return 0;
}

void reconhecer(char token){
	if(lookahead == token)
		lookahead = next_char();
	else
		erro();
}
