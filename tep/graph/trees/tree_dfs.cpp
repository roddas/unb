#include<bits/stdc++.h>

using namespace std;
const int MAX = 300;
vector<int>adj[MAX];

void tree_dfs(int, int);

int main()
{
	return 0;
}
void tree_dfs(int u, int p){
	for(auto v : adj[u])
		if(v != p)
			tree_dfs(v,u);
}
