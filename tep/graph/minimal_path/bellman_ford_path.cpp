#include<bits/stdc++.h>

using namespace std;
using ii = pair<int,int>;
using vi = vector<int>;
const int oo {100000000};
using edge = tuple<int,int,int>;
const int MAX = {2000010};

vi adj[MAX];

pair<vi,vi> bellman_ford(int s, int N,const vector<edge>& edges){
	vi dist(N+1,oo), pred(N+1, oo);
	dist[s] = 0;
	pred[s] = s;
	
	for(int i = 1; i <= N - 1;i++){
		for(auto [u,v,w] : edges){
			if(dist[u] < oo and dist[v] > dist[u] + w){
				dist[v] = dist[u]+w;
				pred[v] = u;
			}
		}
	}
	return {dist, pred};
}

vector<ii> path(int s, int u, const vector<int>& pred){
	vector<ii>p;
	int v = u;
	
	do{
		p.emplace_back(pred[v], v);
		v = pred[v];
	}while(v != s);
	
	reverse(p.begin(), p.end());
	return p;
}
int main()
{
	return 0;
}
