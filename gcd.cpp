int gcd (int a, int b, int &x, int &y) {
    if (a == 0) {
        x = 0, y = 1;
        return b;
    }
    int _x, _y, d = gcd(b%a, a, _x, _y);
    x = _y-(b/a)*_x, y = _y;
    return d;
}
