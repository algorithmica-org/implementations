const int inf = 1e9;

int n, m;

struct edge{
	int cost, cap, to;
};

vector<edge> _e;
vector< vector<int> > g;
vector<int> d, pot, prev;

bool dijkstra(int s, int t){
	set< pair<int, int> > q;
	q.insert({0, root});

	d.assign(n, inf);
	d[root] = 0;

	while(!q.empty()){
		int v = q.begin()->second;
		q.erase(q.begin());
		for(int e : g[v]){
			int u = _e[e].to, w = _e[e].cost + pot[v] - pot[u];
			if(_e[e].cap > 0 && d[u] > d[v] + w){
				q.erase({d[u], u});
				d[u] = d[v] + w;
				prev[u] = e^1;
				q.insert({d[u], u});
			}
		}
	}

	return (d[t] < inf);
}

int mincost(int s, int t){
	int ans = 0;
	while(dijkstra(s, t)){
		pot = d;
		int delta = inf;
		for(int v = t; v != s; v = prev[v].to)
			delta = min(delta, _e[prev[v]^1].cap);
		for(int v = t; v != s; v = prev[v].to){
			_e[prev[v]] += delta;
			_e[prev[v]^1] += delta;
			ans += _e[prev[v]^1].cost*delta;
		}
	}
	return ans;
}
