const int inf = 1e9;

vector<int> dijkstra(int s) {
    set< pair<int, int> > q;
    q.insert({0, s});
    vector<int> d(n, inf);
    d[root] = 0;
    while (q.size()) {
        int v = q.begin()->second;
        q.erase(q.begin());
        for (auto e : g[v]) {
            int u = e.first, w = e.second;
            if (d[u] > d[v] + w) {
                q.erase({d[u], u});
                d[u] = d[v] + w;
                q.insert({d[u], u});
            }
        }
    }
    return d;
}
