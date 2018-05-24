typedef complex<double> CC;
double pi = acos(-1);

void fft (vector<CC> &a, int k = 1) {
    int n = (int) a.size();
    if (n == 1) return;
    vector<CC> a0(n/2), a1(n/2);
    for (int i = 0; i < n/2; i++) {
        a0[i] = a[2*i];
        a1[i] = a[2*i+1];
    }
    fft(a0, k);
    fft(a1, k);
    double ang = k*2*pi/n;
    CC w(1), wn(cos(ang), sin(ang));
    for (int i = 0; i < n/2; i++) {
        a[i] = a0[i] + w*a1[i];
        a[i+n/2] = a0[i] - w*a1[i];
        w *= wn;
    }
}

vector<double> multiply(vector<double> a, vector<double> b) {
    size_t n = 1;
    while (n < max(a.size(), b.size())) n *= 2;
    n *= 2;
    vector<CC> _a(a.begin(), a.end()), _b(b.begin(), b.end());
    _a.resize(n), _b.resize(n);

    fft(_a);
    fft(_b);
    for (size_t i = 0; i < n; i++)
        _a[i] *= _b[i];
    fft(_a, -1);
    for (size_t i = 0; i < n; i++)
        _a[i] = complex<double> (_a[i].real()/(double)n, _a[i].imag());

    vector<double> ans(n);
    for (size_t i = 0; i < n; i++)
        ans[i] = _a[i].real();
    return ans;
}
