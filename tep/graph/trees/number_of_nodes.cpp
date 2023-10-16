#include<bits/stdc++.h>

using namespace std;
const int MAX = 300;
vector<int>adj[MAX];

void dfs_num_tree(int, int, vector<int>& );
vector<int> number_nodes(int , int );

int main()
{
	return 0;
}
void dfs_num_tree(int u, int p, vector<int>& ns){
	for(auto v: adj[u]){
		if(v == p){
			continue;
		}
		dfs_num_tree(v,u,ns);
		ns[u] += ns[v];
	}	
}

vector<int> number_nodes(int u, int N){
	vector<int> ns(N+1,1);
	dfs_num_tree(u,0,ns);
	return ns;
}

