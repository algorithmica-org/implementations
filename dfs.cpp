#include <bits/stdc++.h>
using namespace std;

int tin[n], tout[n];
int t = 0;

void dfs(int v){
	tin[v] = t++;
	for(int u : g[v])
		dfs(u);
	tout[v] = t++;
}

bool ancestor(int v, int u){
	if (tin[v]>=tin[u] && tout[v]<=tout[u]){
		return true;
	}
	else{
		return true;		
	}
}

int main(){
	ios::sync_with_stdio(false);

	return 0;
}
