#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5;
vector<int> g[maxn];
bool b[maxn];
int s[maxn];

void sizes(int v, int p) {
    s[v] = 1;
    for (int u : g[v])
        if (!b[u])
            sizes(u, v), s[v] += s[u];
}

int centroid(int v, int p, int n) {
    for (size_t i = 0; i < g[v].size(); i++) {
        int u = g[v][i];
        if (s[u] > n/2)
            return centroid(u, v, n);
    }
    return v;
}

void solve(int v) {

    /* ... */

    b[v] = 1;
    for (int u : g[v]) {
        if (!b[u]) {
            sizes(u, v);
            solve(centroid(u, v, s[u]/2));
        }
    }
}

int main () {

    return 0;
}
