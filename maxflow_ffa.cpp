const int maxn = 1e5, inf = 1e9;

struct edge {
    int to, cap;
};

vector<int> g[maxn];
vector<edge> e;
bool used[maxn];

void add_edge (int u, int v, int w) {
    g[u].push_back(e.size());
    e.push_back({v, w});
    g[v].push_back(e.size());
    e.push_back({u, 0});
}

int dfs (int v, int t, int flow) {
    if (v == t) return flow;
    used[v] = 1;
    for (int _e : g[v]) {
        int u = e[_e].to, w = e[_e].cap;
        if (!used[u] && w > 0) {
            if (int d = dfs(u, t, min(flow, w))) {
                e[_e].cap -= d;
                e[_e^1].cap += d;
                return d;
            }
        }
    }
    return 0;
}

int maxflow (int s, int t) {
    int flow = 0;
    while (int d = dfs(s, t, inf))
        flow += d, memset(used, 0, sizeof(used));
    return flow;
}
