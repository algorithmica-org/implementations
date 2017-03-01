#include <bits/stdc++.h>
using namespace std;

vector< vector<int> > g;
vector< vector<int> > up;
vector<int> tin, tout;
int logn, n, t;

void dfs(int v){
	tin[v] = t++;
	for(int i = 1; i <= logn; i++)
		up[v][i] = up[up[v][i-1]][i-1];
	for(size_t i = 0; i < g[v].size(); i++){
		int u = g[v][i];
		up[u][0] = v;
		dfs(u);
	}
	tout[v] = t++;
}

int lca(int v, int u){
	if(tin[v] <= tin[u] && tin[u] <= tout[v])
		return v;
	for(int i = logn; i >= 0; i--){
		int z = up[v][i];
		if(!(tin[z] <= tin[u] && tin[u] <= tout[z]))
			return lca(z, u);
	}
	return up[v][0];
}

pair<int, int> intersect(pair<int, int> a, pair<int, int> b){
	
}

int main(){

	return 0;
}
