#include<bits/stdc++.h>

using namespace std;

const int MAX = {2000010};
bitset<MAX>visited;
vector<int> adj[MAX];

void dfs(int u){
	if(visited[u])
		return;
		
	visited[u] = true;
	cout << ' ' << u;
	
	for(auto v : adj[u])
		dfs(v);
}

int connected_components(int N){
	visited.reset();
	
	int count = 0;
	
	for(int i = 1; i <= N; i++){
		if(not visited[i])
		{
			cout << "Component " << ++count << ':';
			dfs(i);
			cout << endl;
		}
	}
	return count;
}

int main()
{
	
	return 0;
}
