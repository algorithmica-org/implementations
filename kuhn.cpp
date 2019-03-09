const int maxn;

vector<int> g[maxn];
int mt[maxn];
bool used[maxn];

bool kuhn (int v) {
    if (used[v]) return 0;
    used[v] = 1;
    for (int u : g[v]) {
        if (mt[u] == -1 || kuhn(mt[u])) {
            mt[u] = v;
            return 1;
        }
    }
    return 0;
}

memset(mt, -1, sizeof(mt));
for (int i = 0; i < n; i++) {
    memset(used, 0, sizeof(mt));
    if (kuhn(i)) cnt++;
}
