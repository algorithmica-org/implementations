const int k = 26;

struct Vertex {
    Vertex *to[k] = {0};
    Vertex *link = 0;
    int len = 0;
};

Vertex *root = new Vertex, *cur = root;

void add_string (string s) {
    for (char _c : s) {
        int c = (int) (_c-'a');
        Vertex *v = cur;
        cur = new Vertex;
        cur->len = v->len+1;
        while (v && !v->to[c])
            v->to[c] = cur, v = v->link;
        if (!v) cur->link = root;
        else if (v->to[c]->len == v->len+1) cur->link = v->to[c];
        else {
            Vertex *u = v->to[c];
            Vertex *clone = new Vertex;
            memcpy(clone->to, u->to, sizeof(u->to));
            clone->link = u->link;
            clone->len = v->len+1;
            while (v && v->to[c] == u)
                v->to[c] = clone, v = v->link;
            cur->link = u->link = clone;
        }
    }
}
