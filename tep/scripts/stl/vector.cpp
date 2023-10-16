#include<bits/stdc++.h>

using namespace std;

int main(){
	vector<int>a; //empty vector
	vector<int>b(5); // b = 0 0 0 0 0
	vector<int>c(5,1); // c = 1 1 1 1 1
	vector<int>d(c); // d = c
	vector<int>e{1,3}; //e = 1 3
	vector<int>v; 
	
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.pop_back();
	cout << v.back() << endl;
	
	auto it = v.begin();
	v.erase(it);
	cout << v.front() << endl;
	
	auto found = find(v.begin(),v.end(), 2);
	if(found != v.end())
		cout << *found << endl;
		
	cout << v.size() << " " << v.empty() << endl;
	return 0;
}
