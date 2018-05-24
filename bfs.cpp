vector<int> bfs (int s) {
    vector<int> d(n, -1);
    d[s] = 0;
    queue<int> q;
    q.push(s);
    while (q.size()) {
        int v = q.front();
        q.pop();
        for (int u : g[v])
            if (d[u] == -1)
                d[u] = d[v]+1, q.push(u);
    }
    return d;
}
