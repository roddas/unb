#include<bits/stdc++.h>

using namespace std;

string fibonacci(int n){
	if(n <= 0)
		return "";
	if(n == 1)
		return "b";
	if(n == 2)
		return "a";
	return fibonacci(n-1) + fibonacci(n-2);
}

int main()
{
	int n;
	cin >> n;
	cout << fibonacci(n) << endl;
	return 0;
}
