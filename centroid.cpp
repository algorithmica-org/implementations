#include <bits/stdc++.h>
using namespace std;
vector< vector<int> > g;
vector<int> s;
int n;

void sizes(int v){
	for(size_t i = 0; i < g[v].size(); i++){
		int u = g[v][i];
		sizes(u);
		s[v] += s[u];
	}
}

int centroid(int v){
	for(size_t i = 0; i < g[v].size(); i++){
		int u = g[v][i];
		if(s[u] > n/2)
			return centroid(u);
	}
	return v;
}

int main(){
	
	cin >> n;

	g.resize(n);
	s.assign(n, 1);

	for(int i = 1; i < n; i++){
		int p;
		cin >> p;
		g[p].push_back(i);
	}

	sizes(0);
	cout << centroid(0);

	return 0;
}
