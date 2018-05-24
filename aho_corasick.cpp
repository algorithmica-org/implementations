const int k = 26;

struct Vertex {
    Vertex *to[k] = {0}, *go[k] = {0};
    Vertex *link = 0, *p;
    int pch;
    Vertex (int _pch, Vertex *_p) { pch = _pch, p = _p; }
};

Vertex *root = new Vertex(-1, 0);

Vertex* go (Vertex *v, int c);

Vertex* link (Vertex *v) {
    if (!v->link) {
        if (v == root || v->p == root) v->link = root;
        else v->link = go(link(v->p), v->pch);
    }
    return v->link;
}

Vertex* go (Vertex *v, int c) {
    if (!v->go[c]) {
        if (v->to[c]) v->go[c] = v->to[c];
        else if (v == root) v->go[c] = root;
        else v->go[c] = go(link(v), c);
    }
    return v->go[c];
}

void add_string (string s) {
    Vertex *v = root;
    for (char _c : s) {
        int c = int(_c-'a');
        if (!v->to[c]) v->to[c] = new Vertex(c, v);
        v = v->to[c];
    }
}
