#include<bits/stdc++.h>

using namespace std;
//using token  = char;
using token_t = pair<int,int>;

char lookahead;
const int NUM {256};

void fator(void);
char proximo_token(void);
void erro(void);
void reconhecer(char);
void expr(void);
void resto(void);
void resto(void);
void digito(void);

int main(void){
	
	
	return 0;
}
void fator(void){
	auto [token,valor] = lookahead;
	
	if(token == '('){
		reconhecer('(');
		expr();
		reconhecer('(');
	}else if(token == NUM){
		reconhecer((char)NUM);
		cout << valor;
	}else{
		erro();
	}
}
void erro(void){
	cerr << "\nErro de sintaxe! lookahead = " << lookahead << '\n';
	exit(-1);
}
void reconhecer(char t){
	if(lookahead == t)
		lookahead = proximo_token();
	else
		erro();
}
void resto(void){
	if(lookahead == '+' or lookahead == '-'){
		auto c = lookahead;
		reconhecer(c);
		digito();
		cout.put(c);
		resto();
	}
}
void expr(void){
	digito();
	resto();
}
void digito(void){
	if(isdigit(lookahead)){
		cout.put(lookahead);
		reconhecer(lookahead);
	}else{
		erro();
	}
}
char proximo_token(void)
{
	auto t = cin.get();
	return (char)t;	
}
