const int maxn = 1e5;
int t[2*maxn];

int n;

void build () {
    for (int i = n-1; i > 0; i--)
        t[i] = max(t[i<<1], t[i<<1|1]);
}

void upd (int k, int x) {
    k += n;
    t[k] = x;
    while (k > 1) {
        t[k>>1] = max(t[k], t[k^1]);
        k >>= 1;
    }
}

int rmq (int l, int r) {
    int ans = 0;
    l += n, r += n;
    while (l <= r) {
        if (l&1)
            ans = max(ans, t[l++]);
        if (!(r&1))
            ans = max(ans, t[r--]);
        l >>= 1, r >>= 1;
    }
    return ans;
}
