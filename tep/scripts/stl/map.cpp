#include<bits/stdc++.h>

using namespace std;

int main(){
	map<char,int>m;
	
	string s = "hello";
	
	for(auto c : s){
		m[c]++;
	}
	for(auto const & [key,value]:m){
		cout << "Letra " << key << ": " << value << endl;
	}
	
	return 0;
}
