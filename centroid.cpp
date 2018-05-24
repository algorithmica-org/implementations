#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5;
vector<int> g[maxn];
bool used[maxn];
int s[maxn];

void size (int v, int p = -1) {
    s[v] = 1;
    for (int u : g[v])
        if (u != p && !used[u])
            size(u, v), s[v] += s[u];
}

int centroid (int v, int p, int n) {
    for (int u : g[v])
        if (u != p && s[u] > n/2)
            return centroid(u, v, n);
    return v;
}

void solve (int v) {
    sizes(v);

    /* ... */

    used[v] = 1;
    for (int u : g[v])
        if (!used[u])
            solve(centroid(u, v, s[u]));
}

int main () {

    return 0;
}
