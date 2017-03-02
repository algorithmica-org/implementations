struct node{
	int key, size = 1;
	node *l = 0, *r = 0;
	node(int _key){ key = _key; }
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
	if(!p) return {0, 0};
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

node *root = 0;

void insert(int x){
	Pair q = split(root, x);
	node *t = new node(x);
	root = merge(q.first, merge(x, q.second));
}
