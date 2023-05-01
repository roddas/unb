#include<bits/stdc++.h>

using namespace std;
using token  = char;

token lookahead;

token proximo_token(void);
void erro(void);
void reconhecer(token);
void expr(void);
void digito(void);
void resto(void);

int main(void){
	lookahead = proximo_token();
	expr();
	cout << endl;
	return 0;
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
void digito(void){
	if(isdigit(lookahead)){
		cout.put(lookahead);
		reconhecer(lookahead);
	}else{
		erro();
	}
}
token proximo_token(void)
{
	auto t = cin.get();
	return (token)t;	
}
void erro(void){
	cerr << "\nErro de sintaxe! lookahead = " << lookahead << '\n';
	exit(-1);
}
void reconhecer(token t){
	if(lookahead == t)
		lookahead = proximo_token();
	else
		erro();
}
void expr(void){
	digito();
	resto();
}
