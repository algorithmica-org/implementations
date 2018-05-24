const int maxn = 1e6, logn = 20;

int a[maxn], lg[maxn], mx[maxn][logn];

int rmq (int l, int r) {
    int t = lg[r-l+1];
    return max(mx[l][t], mx[r-(1<<t)+1][t]);
}

for (int l = 1; l < logn; l++)
    for (int i = (1<<l); i < maxn; i++)
        lg[i] = l;

for (int i = n-1; i >= 0; i--) {
    mx[i][0] = a[i];
    for (int l = 0; l < logn-1; l++)
        mx[i][l+1] = max(mx[i][l], mx[i+(1<<l)][l]);
}
