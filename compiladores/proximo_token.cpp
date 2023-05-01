#include<bits/stdc++.h>

using namespace std;
using token  = char;

token lookahead;

token proximo_token(void);
void erro(void);

int main(void){
	token t = proximo_token();
	cout << t << endl;
	return 0;
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
