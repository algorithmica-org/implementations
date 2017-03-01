struct node{
	int pos, size = 1;
	node *l = NULL, *r = NULL;
	node(int _pos){ pos = _pos; }
};

int size(node *v) { return (v) ? v->size : 0; }

void upd(node *v) { v->size = 1 + size(v->l) + size(v->r); }

node* merge(node *l, node *r){
	if(!l) return r;
	if(!r) return l;
	if(rand() % (size(l) + size(r)) < size(l)){
		l->r = merge(l->r, r);
		upd(l);
		return l;
	}
	else{
		r->l = merge(l, r->l);
		upd(r);
		return r;
	}
}

typedef pair<node*, node*> Pair;

Pair split(node *p, int x){
	if(!p) return {NULL, NULL};
	if(size(p->l) + 1 <= x){
		Pair q = split(p->r, x-size(p->l)-1);
		p->r = q.first;
		upd(p);
		return {p, q.second};
	}
	else{
		Pair q = split(p->l, x);
		p->l = q.second;
		upd(p);
		return {q.first, p};
	}
}

node *root = NULL;

void insert(int x){
	Pair q = split(root, x);
	node *t = new node(x);
	root = merge(q.first, merge(x, q.second));
}
