struct hashmap {
    const int size = (1<<24);
    int a[size] = {-1}, b[size];

    static inline int h (int x) { return (x^179)*7; }

    void add (int x, int y) {
        int k = h(x) % size;
        while (a[k] != -1 && a[k] != x)
            k = (k+1) % size;
        a[k] = x, b[k] = y; 
    }

    int get (int x) {
        for (int k = h(x) % size; a[k] != -1; k = (k+1) % size)
            if (a[k] == x)
                return b[k];
        return -1;
    }
};
