const int k = 26;

struct vertex{
	vertex* to[k] = {NULL};
	vertex* go[k] = {NULL};
	vertex *link = NULL;
	vertex *p;
	int pch;
	int bad = -1;
	vertex(int _pch, vertex *_p){ pch = _pch, p = _p; }
};

vertex *root = new vertex('#', NULL);

vertex* go(vertex *v, int c);

vertex* link(vertex *v){
	if(v->link) return v->link;
	if(v == root || v->p == root) return root;
	return v->link = go(link(v->p), v->pch);
}

vertex* go(vertex *v, int c){
	if(v->to[c]) return v->to[c];
	if(v->go[c]) return v->go[c];
	if(v == root) return root;
	return v->go[c] = go(link(v), c);
}
