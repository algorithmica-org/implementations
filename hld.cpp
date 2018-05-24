#include <bits/stdc++.h>
using namespace std;

// Timus 1553 "Caves and Tunnels"
// this implementation is actually bad
// google adamant's blogs how to code it

struct segtree {
    int lb, rb;
    int mx = 0;
    segtree *l, *r;
    segtree (int _lb, int _rb) {
        lb = _lb, rb = _rb;
        if (lb != rb) {
            int t = (lb + rb) / 2;
            l = new segtree(lb, t);
            r = new segtree(t+1, rb);
        }
    }
    void upd (int k, int x) {
        if (lb == rb) mx += x;
        else {
            int t = (lb + rb) / 2;
            if (k <= t) l->upd(k, x);
            else r->upd(k, x);
            mx = max(l->mx, r->mx);
        }
    }
    int get_mx (int lq, int rq) {
        if (lb >= lq && rb <= rq) return mx;
        else if (lb > rq || rb < lq) return 0;
        return max(l->get_mx(lq, rq), r->get_mx(lq, rq));
    }
};

const int maxn = 1e5;
int p[maxn], head[maxn], d[maxn], s[maxn];
int tin[maxn], tout[maxn];
segtree* tree[maxn];
vector<int> g[maxn];
int timer = 0;

void dfs1 (int v) {
    tin[v] = timer++;
    s[v] = 1;
    for (int u : g[v]) {
        if (u != p[v]) {
            d[u] = d[v]+1;
            p[u] = v;
            dfs1(u);
            s[v] += s[u];
        }
    }
    tout[v] = timer++;
}

void dfs2 (int v) {
    if (g[v].empty() || (g[v].size() == 1 && p[v] != -1))
        tree[v] = new segtree(0, d[v] - d[head[v]]);
    else{
        int mx = -1;
        for (int u : g[v])
            if (u != p[v] && (mx == -1 || s[u] > s[mx]))
                mx = u;
        for (int u : g[v])
            if (u != p[v] && u != mx)
                head[u] = u, dfs2(u);
        head[mx] = head[v];
        dfs2(mx);
        tree[v] = tree[mx];
    }
}

int dist (int v) {
    return d[v]-d[head[v]];
}

bool ancestor (int v, int u) {
    return tin[v] <= tin[u] && tin[u] <= tout[v];
}

int query (int v, int u) {
    int ans = 0;
    while (!ancestor(head[v], u)) {
        ans = max(ans, tree[v]->get_mx(0, dist(v)));
        v = p[head[v]];
    }
    while (!ancestor(head[u], v)) {
        ans = max(ans, tree[u]->get_mx(0, dist(u)));
        u = p[head[u]];
    }
    if (dist(u) < dist(v)) swap(u, v);
    ans = max(ans, tree[v]->get_mx(dist(v), dist(u)));
    return ans;
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    head[0] = 0, p[0] = -1, d[0] = 0;
    dfs1(0);
    dfs2(0);
    int q;
    cin >> q;
    while (q--) {
        char type;
        cin >> type;
        if (type == 'I') {
            int v, t;
            cin >> v >> t;
            v--;
            tree[v]->upd(dist(v), t);
        }
        else{
            int u, v;
            cin >> u >> v;
            u--, v--;
            cout << query(u, v) << "\n";
        }
    }

    return 0;
}
