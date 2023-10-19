#include<bits/stdc++.h>

using namespace std;
using ii = pair<int,int>;
using edge = tuple<int,int,int>;
const int MAX = {2000010};

vector<int> adj[MAX];

vector<int>bellman_ford(int s, int N,const vector<edge>& edges){
	const int oo {100000000};
	vector<int> dist(N+1,oo);
	dist[s] = 0;
	
	for(int i = 1; i<=N+1;i++){
		for(auto [u,v,w] : edges){
			if(dist[u] < oo and dist[v] > dist[u] + w){
				dist[v] = dist[u]+w;
			}
		}
	}
	return dist;
}

int main()
{
	return 0;
}
