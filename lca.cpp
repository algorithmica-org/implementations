const int maxn = 1e6, logn = 22;

vector<int> g[maxn];
int tin[maxn], tout[maxn];
int up[maxn][logn];
int t = 0;

void dfs (int v) {
    for (int l = 1; l < logn; l++)
        up[v][l] = up[up[v][l-1]][l-1];
    tin[v] = t++;
    for (int u : g[v]) {
        up[u][0] = v;
        dfs(u);
    }
    tout[v] = t++;
}

int a (int v, int u) {
    return tin[v] <= tin[u] && tin[u] <= tout[v];
}

int lca (int v, int u) {
    if (a(v, u)) return v;
    if (a(u, v)) return u;
    for (int l = logn-1; l >= 0; l--)
        if ( !a(up[v][l], u) )
            v = up[v][l];
    return up[v][0];
}
