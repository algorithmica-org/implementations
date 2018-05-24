// untested and not very memory-efficient

struct Node {
    int key, size = 1;
    Node *l = 0, *r = 0;
    Node (int _key) { key = _key; }
};

int size (Node *v) { return v ? v->size : 0; }

void upd (Node *v) { v->size = 1 + size(v->l) + size(v->r); }

Node* copy (Node *v) { return v ? new Node(*v) : 0; }

Node* merge (Node *l, Node *r) {
    l = copy(l), r = copy(r);
    if (!l) return r;
    if (!r) return l;
    if (rand() % (size(l) + size(r)) < size(l)) {
        l->r = merge(l->r, r);
        upd(l);
        return l;
    }
    else {
        r->l = merge(l, r->l);
        upd(r);
        return r;
    }
}

typedef pair<Node*, Node*> Pair;

Pair split (Node *p, int x) {
    p = copy(p);
    if (!p) return {0, 0};
    if (size(p->l) + 1 <= x) {
        Pair q = split(p->r, x-size(p->l)-1);
        p->r = q.first;
        upd(p);
        return {p, q.second};
    }
    else {
        Pair q = split(p->l, x);
        p->l = q.second;
        upd(p);
        return {q.first, p};
    }
}

Node *root = 0;

void insert (int x) {
    Pair q = split(root, x);
    Node *t = new Node(x);
    root = merge(q.first, merge(t, q.second));
}
