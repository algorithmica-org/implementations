vector<int> suffix_array (vector<int> s) {
    s.push_back(0);
    int n = (int) s.size();
    int cnt = 0, cls = 0;
    vector<int> c(n), p(n);
    map< int, vector<int> > t;
    for (int i = 0; i < n; i++)
        t[s[i]].push_back(i);
    for (auto x : t) {
        for (int u : x.second)
            c[u] = cls, p[cnt++] = u;
        cls++;
    }
    for (int l = 1; cls < n; l++) {
        vector< vector<int> > a(cls);
        vector<int> _c(n);
        int d = (1<<l)/2;
        int _cls = cnt = 0;
        for (int i = 0; i < n; i++) {
            int k = (p[i]-d+n)%n;
            a[c[k]].push_back(k);
        }
        for (int i = 0; i < cls; i++) {
            for (size_t j = 0; j < a[i].size(); j++) {
                if (j == 0 || c[(a[i][j]+d)%n] != c[(a[i][j-1]+d)%n]) _cls++;
                _c[a[i][j]] = _cls-1;
                p[cnt++] = a[i][j];
            }
        }
        c = _c;
        cls = _cls;
    }
    return vector<int>(p.begin()+1, p.end());
}
