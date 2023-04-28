#include<bits/stdc++.h>

using namespace std;

char lookahead;

void reconhecer(char);
char next_char(void);
void erro(void);
void digito(void);

int main(void){
	
	lookahead = next_char();
	//reconhecer(lookahead);
	digito();
	return 0;
}

void reconhecer(char token){
	if(token == lookahead )
		token = next_char();
	else
		erro();
}
char next_char(void){
	return getchar();
}
void erro(void){
	printf("Erro: Caractere inválido\n");
	exit(-1);
}
void digito(void){
	
	if(!isdigit(lookahead))
		erro();
		
	printf("%c",lookahead);
	reconhecer(lookahead);
}
