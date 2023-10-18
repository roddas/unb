#include<bits/stdc++.h>

using namespace std;
using vi = vector<int>;
using edge = pair<int, int>;
const int MAX = {2000010};
bitset<MAX>visited;
vi adj[MAX];
int dfs_num[MAX], dfs_low[MAX];
vi color(MAX);
const int NONE = 0,BLUE = 1, RED = 2;

void dfs_bridge(int u, int p, int & next,vector<edge>& bridges)
{
	dfs_low[u] = dfs_num[u] = next++;
	
	for(auto v : adj[u]){
		if(not dfs_num[v]){
			dfs_bridge(v,u,next,bridges);
			if(dfs_low[v] > dfs_num[u])
				bridges.emplace_back(u,v);
			dfs_low[u] = min (dfs_low[u], dfs_low[v]);
		}else if (v != p)
			dfs_low[u] = min(dfs_low[u], dfs_num[v]);
	}
}
vector<edge> bridges(int N)
{
	memset(dfs_num,0,(N+1) * sizeof(int));
	memset(dfs_low,0,(N+1) * sizeof(int));
	
	vector<edge> bridges;
	
	for(int u = 1, next  = 1; u <= N; u++)
		if(not dfs_num[u])
			dfs_bridge(u,u,next,bridges);
	return bridges;
}

int main()
{
	
	return 0;
}
