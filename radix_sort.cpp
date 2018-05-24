const int c = (1<<16);

void csort (vector<int> &a) {
    int n = (int) a.size();
    vector<int> b[c];
    for (int i = 0; i < n; i++)
        b[a[i]%c].push_back(a[i]);
    int k = 0;
    for (int i = 0; i < c; i++) {
        for (size_t j = 0; j < b[i].size(); j++)
            a[k++] = b[i][j];
        b[i].clear();
    }
    for (int i = 0; i < n; i++)
        b[a[i]/c].push_back(a[i]);
    k = 0;
    for (int i = 0; i < c; i++)
        for (size_t j = 0; j < b[i].size(); j++)
            a[k++] = b[i][j];
}
