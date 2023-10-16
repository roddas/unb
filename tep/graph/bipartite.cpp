#include<bits/stdc++.h>

using namespace std;

const int MAX = {2000010};
bitset<MAX>visited;
vector<int> adj[MAX];
vector<int> color(MAX);
const int NONE = 0,BLUE = 1, RED = 2;

bool bfs(int s){
	
	queue<int> q;
	q.push(s);
	color[s] = BLUE;
	
	while( not q.empty()){
		auto u = q.front();
		q.pop();
		for(auto v : adj[u]){
			if(color[v] == NONE){
				color[v] = 3 - color[u];
				q.push(v);
			}else if(color[v] == color[u])
				return false;
		}
	}
	return true;
}

bool is_bipartite(int N){
	for(int u = 1; u <= N; u++)
		if(color[u] == NONE and not bfs(u))
			return false;
	return true;
}			

int main()
{
	
	return 0;
}
