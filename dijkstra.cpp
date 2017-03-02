vector<int> dijkstra(int root){
	set< pair<int, int> > q;
	q.insert({0, root});
	vector<int> d(n, inf);
	d[root] = 0;
	while(!q.empty()){
		int v = q.begin()->second;
		q.erase(q.begin());
		for(auto e : g[v]){
			int u = e.first, w = e.second;
			if(d[u] > d[v] + w){
				q.erase({d[u], u});
				d[u] = d[v] + w;
				q.insert({d[u], u});
			}
		}
	}
	return d;
}
