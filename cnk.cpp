int t[maxn];

int bp (int a, int n) {
    int ans = 1;
    while (n) {
        if (n&1) ans = ans*a % mod;
        a = a*a % mod;
        n >>= 1;
    }
    return ans;
}

int inv (int x) {
    return bp(x, mod-2);
}

int c (int n, int k) {
    return t[n]*inv(t[k]) % mod * inv(t[n-k]) % mod;
}

int d (int n, int k) {
    return c(n+k-1, k-1);
}

t[0] = 1;
for (int i = 1; i < maxn; i++)
    t[i] = i*t[i-1] % mod;
