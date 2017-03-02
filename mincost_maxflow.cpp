#include <bits/stdc++.h>
using namespace std;

const int maxn = 305, inf = 1e9;

int cost[maxn][maxn], cap[maxn][maxn];
int d[maxn], pot[maxn], par[maxn];

int n;

bool dijkstra(int s, int t){
	set< pair<int, int> > q;
	q.insert({0, s});

	for(int i = 0; i < n; i++)
		d[i] = inf;
	d[s] = 0;

	while(!q.empty()){
		int v = q.begin()->second;
		q.erase(q.begin());
		for(int u = 0; u < n; u++){
			int w = cost[v][u] + pot[v] - pot[u];
			if(cap[v][u] && d[u] > d[v] + w){
				q.erase({d[u], u});
				d[u] = d[v] + w;
				par[u] = v;
				q.insert({d[u], u});
			}
		}
	}

	return (d[t] < inf);
}

int mincost(int s, int t){
	int ans = 0;
	while(dijkstra(s, t)){
		memcpy(pot, d, sizeof(d));
		int delta = inf;
		for(int v = t; v != s; v = par[v])
			delta = min(delta, cap[par[v]][v]);
		for(int v = t; v != s; v = par[v]){
			cap[par[v]][v] -= delta;
			cap[v][par[v]] += delta;
			ans += cost[par[v]][v]*delta;
		}
	}
	return ans;
}

int main(){
	cin >> n;

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			int t;
			cin >> t;
			for(int k = 0; k < n; k++)
				if(k != i)
					cost[k][n+j] += t, cost[n+j][k] -= t;
		}
	}

	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			cap[i][n+j] = 1;

	for(int i = 0; i < n; i++)
		cap[2*n][i] = cap[n+i][2*n+1] = 1;

	n = 2*n+2;

	cout << mincost(n-2, n-1);

	return 0;
}
