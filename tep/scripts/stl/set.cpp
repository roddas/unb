#include<bits/stdc++.h>

using namespace std;

int main(){
	set<int> q;
	
	q.insert(1);
	q.insert(1*34);
	q.insert(134);
	q.insert(45);
	q.insert(34);
	
	cout << *q.find(1) << endl;
	cout << q.count(345) << endl;
	cout << q.count(34);
	cout << endl;
	
	return 0;
}
