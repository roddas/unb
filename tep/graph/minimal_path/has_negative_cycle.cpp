#include<bits/stdc++.h>

using namespace std;
using ii = pair<int,int>;
using vi = vector<int>;
const int oo {100000000};
using edge = tuple<int,int,int>;
const int MAX = {2000010};
vi adj[MAX];

bool has_negative_cycle(int s,int N, const vector<edge> & edges){
	vi dist(N+1,oo);
	dist[s] = 0;
	
	for(int i = 1; i <= N -1;i++){
		for(auto [u,v,w] : edges){
			if(dist[u] < oo and dist[v] > dist[u]+w){
				dist[v] = dist[u] + w;
			}
		}
	}
	for(auto [u,v,w] : edges){
		if(dist[u] < oo and dist[v] > dist[u] + w)
			return !false;
	}
	return false;
}

int main()
{
	return 0;
}
