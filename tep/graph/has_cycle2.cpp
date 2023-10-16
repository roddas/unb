#include<bits/stdc++.h>

using namespace std;

const int MAX = {2000010};
bitset<MAX>visited;
vector<int> adj[MAX];

void dfs(int u, function<void(int)>process){
	
	if(visited[u])
		return;
		
	visited[u] = true;
	process(u);
	
	for(auto v: adj[u])
		dfs(v,process);	
}
bool has_cycle2(int N){
	
	visited.reset();
	
	for(int u = 1; u <= N; u++)
		if(not visited[u])
		{
			vector<int> cs;
			size_t edges = 0;
			
			dfs(u,[&](int u){
				cs.emplace_back(u);
				for(const auto& v : adj[u])
					edges += (visited[v] ? 0 : 1);
			});
			
			if(edges >= cs.size())
				return true;
		}
	return false;
}


int main()
{
	
	return 0;
}
