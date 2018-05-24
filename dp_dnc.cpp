#include <bits/stdc++.h>
using namespace std;

// CF 321E
// dp[n][k] = min( s[n][r] + dp[r][k-1] );

const int maxn = 4005, inf = 1e9;

int c[maxn][maxn], s[maxn][maxn], dp[maxn][maxn];

void f (int l, int r, int _l, int _r, int k) {
    if (l > r) return;
    int t = (l+r)/2; 
    int w = _l;
        for (int i = max(t, _l); i <= _r; i++) {
        int val = c[t][i] + dp[i+1][k-1];
        if (val < dp[t][k]) dp[t][k] = val, w = i;
    }
    f(l, t-1, _l, w, k);
    f(t+1, r, w, _r, k);
}

int main () {
    int n, k;
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char t = getchar();
            while (t < '0' || t > '9') t = getchar();
            s[i][j+1] = t-'0';
            s[i][j+1] += s[i][j];
        }
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j <= k; j++)
            dp[i][j] = inf;

    for (int i = 0; i < n; i++)
        for (int j = i+1; j < n; j++)
            c[i][j] = c[i][j-1] + s[j][j] - s[j][i];

    for (int i = 0; i < n; i++)
        dp[i][1] = c[i][n-1];

    for (int i = 2; i <= k; i++)
        f(0, n-1, 0, n-1, i);

    cout << dp[0][k];

    return 0;
}
