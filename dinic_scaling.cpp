const int maxc = 1e9, n = 1e3, m = 1e3;

int s, t;
int to[2*m], c[2*m], d[n], p[n];
vector<int> g[n];

int bfs(){
	memset(d, -1, sizeof(d));
	d[s] = 0;
	queue<int> q;
	q.insert(s);
	while(!q.empty()){
		int v = q.front();
		q.pop();
		for(int e : g[v]){
			int u = to[e], w = c[e];
			if(w > 0 && d[u] == -1)
				d[u] = d[v]+1, q.push(u);
		}
	}
	return d[t];
}

int dfs(int v, int minw){
	while(p[v] < (int) g[v].size()){
		int e = g[p[v]];
		int u = to[e], w = c[e];
		if(d[u] > d[v] && w > 0){
			int flow = dfs(0, min(minw, w));
			if(flow > 0){
				c[e] -= flow;
				c[e^1] += flow;
				return flow;
			}
		}
	}
	return false;
}

int dinic(){
	int ans = 0;
	while(bfs(s, t) != -1){
		memset(d, 0, sizeof(d));
		int flow = dfs(0);
		if(flow > 0) ans += flow;
		else break;
	}
	return flow;
}

