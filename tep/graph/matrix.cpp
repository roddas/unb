#include<bits/stdc++.h>

using namespace std;

const int N {6};
int graph[N+1][N+1];

int main(){
	
	graph[1][2] = 2;
	graph[1][3] = 1;
	graph[1][4] = 8;
	graph[2][1] = 5;
	graph[2][4] = 7;
	graph[2][5] = 2;
	graph[3][1] = 3;
	graph[3][4] = 9;
	graph[3][6] = 4;
	graph[4][3] = 1;
	graph[5][2] = 3;
	graph[5][6] = 6;
	graph[6][4] = 5;
	
	for(int i = 1; i <= N;i++){
		for(int j = 1; j <= N; j++){
			cout << graph[i][j] << (j == N ? '\n':' ');
		}
	}
	
	return 0;
}
