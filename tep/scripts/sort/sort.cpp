#include<bits/stdc++.h>

using namespace std;

void print_array(vector<int> v){
	for(size_t a = 0; a < v.size();a++){
		cout << v[a] << (a+1 == v.size() ? "\n" : " ");
	}
}

int main(){
	vector<int> numbers{ 1,2,3,34,67,34,322,3,3,12,3,-966,43,34,34,235,45,45,-564,6};
	
	print_array(numbers);
	sort(numbers.begin(),numbers.end());
	print_array(numbers);
	sort(numbers.begin(),numbers.end(),greater<int>());
	print_array(numbers);
	
	return 0;
}
