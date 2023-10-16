#include<bits/stdc++.h>

using namespace std;

const int MAX = {2000010};
bitset<MAX>visited;
vector<int> adj[MAX];

void dfs(int u){
	if(visited[u])
		return;
	
	// processa / visita u
	visited[u] = true;
	
	for(auto v : adj[u])
		dfs(v);
}

int main()
{
	
	return 0;
}
