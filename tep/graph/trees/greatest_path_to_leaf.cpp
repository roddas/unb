#include<bits/stdc++.h>

using namespace std;
const int MAX = 300;
vector<int>adj[MAX];

void dfs_path(int, int, vector<int>& );
vector<int> number_nodes(int , int );

int main()
{
	return 0;
}
void dfs_path(int u, int p, vector<int>& tl){
	for(auto v: adj[u]){
		if(v == p){
			continue;
		}
		dfs_path(v,u,tl);
		tl[u] = max(tl[u], 1 + tl[v]);
	}	
}

vector<int> to_leaf(int u, int N){
	vector<int> tl(N+1, 0);
	dfs_path(u,0,tl);
	return tl;
}

