#include<bits/stdc++.h>

using namespace std;

int main(){
	stack<int> q;
	
	q.push(1);
	q.push(1*34);
	q.push(134);
	q.push(45);
	
	while(!q.empty()){
		cout << q.top() << " ";
		q.pop();
	}
	cout << endl;
	
	return 0;
}
