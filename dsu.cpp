int _p[maxn], s[maxn];

int p (int v) { return (_p[v] == v) ? v : _p[v] = p(_p[v]); }

void unite (int a, int b) {
    a = p(a), b = p(b);
    if (s[a] > s[b]) swap(a, b);
    s[b] += s[a];
    _p[a] = b;
}

for (int i = 0; i < n; i++)
    _p[i] = i;
