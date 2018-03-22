struct hashmap {
    const int size = (1<<24);
    int a[size] = {-1}, b[size];

    inline int h (int x) { return (x^179)*7; }

    void add (int x, int y) {
        int t = h(x);
        int k = t % size;
        while (a[k] != -1 && a[k] != t)
            k = (k+1) % size;
        a[k] = t, b[k] = y; 
    }

    int get (int x, int y) {
        int t = h(x);
        for (int k = t % size; a[k] != -1; k = (k+1) % size) {
            if (a[k] == t)
                return b[k];
        return -1;
    }
};
