#include<bits/stdc++.h>

using namespace std;

void print(const string as[],int N){
	for(int i = 0; i < N;i++){
		cout << as[i] << (i+1 == N ? "\n": ", ");
	}
	cout << "======================================" << endl;
}

//Primeira forma: Não diferencia maiúsculas de minúsculas
bool compare(const string &a,const string &b){
	string x,y;
	
	auto to_lower = [](char c){return tolower(c);};
	
	transform(a.begin(),a.end(),back_inserter(x),to_lower);
	return x < y;
}

//Terceria forma: primeiro por tamanho, depoix lexicográfico
struct Compare {
	bool operator()(const string &a,const string &b){
		int N = a.size(), M = b.size();
		return N != M ? N < M : a < b;
	}
};

int main(){
	
	string as [] {"verde","amarelo","Vermelho","Branco","Preto", "azul"};
	int N = 6;
	
	
	
	// Ordenação lexicográfica
	cout << "Ordenação lexicográfica" << endl;
	sort(as, as + N);
	print(as, N);
	
	cout << "Ordenação lexicográfica inversa" << endl;
	sort(as, as + N,greater<string>());
	print(as, N);
	
	cout << "Ordenação case-insensitive" << endl;
	sort(as, as + N,compare);
	print(as, N);
	
	cout << "Ordenação por tamanho, depois lexicográfica" << endl;
	sort(as, as + N,Compare());
	print(as, N);
	
	sort(as, as +N, [](const string &a, const string &b){
		auto x = islower(a[0]), y = islower(b[0]);
		return x == y ? a < b : (x ? true: false);
	});
	print(as, N);
	
	return 0;
}
