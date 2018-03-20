struct segtree {
    int lb, rb;
    int sum = 0;
    segtree *l = 0, *r = 0;
    segtree (int _lb, int _rb) {
        lb = _lb, rb = _rb;
    }
    void extend () {
        int t = (lb + rb) / 2;
        if (!l) {
            l = new segtree(lb, t);
            r = new segtree(t+1, rb);
        }
    }
    void add (int k, int x) {
        sum += x;
        if (lb != rb) {
            extend();
            int t = (lb + rb) / 2;
            if (k <= t) l->add(k, x);
            else r->add(k, x);
        }
    }
    int get_sum (int lq, int rq) {
        if (lb >= lq && rb <= rq) return sum;
        if (lb > rq || rb < lq) return 0;
        extend();
        return l->get_sum(lq, rq) + r->get_sum(lq, rq);
    }
};
