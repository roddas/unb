#include<bits/stdc++.h>

using namespace std;


const int oo = numeric_limits<int>::max();
const int MAX = {2000010};
vector<int> adj[MAX];


vector<int>  bfs(int s, int N){
	vector<int> dist(N+1,oo);
	queue<int> q;
	
	dist[s] = 0;
	q.push(s);
	
	while( not q.empty()){
		auto u = q.front();
		q.pop();
		//processa / visita u
		
		for(auto v : adj[u]){
			if(dist[v] == oo){
				dist[v] = dist[v]+1;
				q.push(v);
			}
		}
	}
	return dist;
}

int main()
{
	return 0;
}
