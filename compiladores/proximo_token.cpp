#include<bits/stdc++.h>

using namespace std;
using token  = char;

token proximo_token(void);

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
