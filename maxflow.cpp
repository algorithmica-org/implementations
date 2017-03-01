#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;
int n, m;
vector< vector<int> > c;

int flow(int s, int t){
	queue<int> q;
	vector<int> p(n, -1);
	p[s] = s;
	q.push(s);
	while(!q.empty()){
		int v = q.front();
		if(v == t)
			break;
		q.pop();
		for(int u = 0; u < n; u++)
			if(p[u] == -1 && c[v][u] > 0)
				p[u] = v, q.push(u);
	}
	if(p[t] == -1)
		return 0;
	int cmin = inf;
	for(int v = t; v != s; v = p[v])
		cmin = min(cmin, c[p[v]][v]);
	for(int v = t; v != s; v = p[v])
		c[p[v]][v] -= cmin, c[v][p[v]] += cmin;
	return cmin + flow(s, t);
}

int main(){
	cin >> n >> m;

	c.assign(n, vector<int> (n, 0));

	for(int i = 0; i < m; i++){
		int u, v, w;
		cin >> u >> v >> w;
		u--, v--;
		c[u][v]/* = c[v][u]*/ =w;
	}

	cout << flow(0, n-1) << endl;

	return 0;
}
