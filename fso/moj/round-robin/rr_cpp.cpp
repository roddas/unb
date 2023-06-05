#include <stdio.h>
#include<bits/stdc++.h>

using namespace std;
using processo = pair<int,int>;
using fila = queue<processo>;
void round_robin(fila &, int );

int main (int argc, char **argv)
{
	int n,quantum;
	fila fileira;
	
	cin >> n >> quantum;
	
	while(n--){
		processo p;
		cin >> p.first >> p.second;
		p.second *= 1000;
		fileira.push(p);
	}
	round_robin(fileira, quantum);
	
	return EXIT_SUCCESS;
}
void round_robin(fila &fileira, int quantum){
	int total_time = 0;
	
	while(!fileira.empty()){
		
		processo p = fileira.front();
		fileira.pop();
		
		if(p.second > quantum){
			p.second -= quantum;
			total_time += quantum;
			fileira.push(p);
		}else{
			total_time += p.second;
			printf("%d (%d)\n",p.first, total_time);
		}
	}
}

