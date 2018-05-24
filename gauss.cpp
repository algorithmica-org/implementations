typedef vector< vector<double> > matrix;

vector<double> gauss (matrix a) {
    int n = (int) a.size();
    for (int i = 0; i < n; i++) {
        int best = i;
        for (int j = i+1; j < n; j++)
            if (a[j][i] > a[best][i])
                best = j;
        swap(a[best], a[i]);
        for (int j = n; j >= i; j--)
            a[i][j] /= a[i][i];
        for (int j = 0; j < n; j++)
            if (j != i)
                for (int k = n; k >= i; k--)
                    a[j][k] -= a[i][k]*a[j][i];
    }
    vector<double> ans(n);
    for (int i = 0; i < n; i++)
        ans[i] = a[i][n] / a[i][i];
    return ans;
}
