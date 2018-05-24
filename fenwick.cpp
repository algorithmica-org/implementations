struct fenwick {
    int n;
    vector<int> t;
    fenwick (int _n) {
        n = _n;
        t.assign(n, 0);
    }
    int sum (int r) {
        int ans = 0;
        while (r >= 0) {
            ans += t[r];
            r = (r & (r+1)) - 1;
        }
        return ans;
    }
    int sum (int l, int r) {
        return sum(r) - sum(l-1);
    }
    void add (int k, int x) {
        while (k < n) {
            t[k] += x;
            k = k | (k+1);
        }
    }
};
