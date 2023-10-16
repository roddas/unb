#include<bits/stdc++.h>

using namespace std;

int main(){
	queue<int> q;
	
	q.push(1);
	q.push(1*34);
	q.push(134);
	q.push(45);
	
	cout << q.front() << endl;
	cout << q.back() << endl;
	
	while(!q.empty()){
		cout << q.front() << " ";
		q.pop();
	}
	cout << endl;
	
	return 0;
}
