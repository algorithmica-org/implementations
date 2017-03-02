// untested

const int k = 26;

struct vertex{
	vertex *to[k] = {0}, *go[k] = {0};
	vertex *link = 0, *p;
	int pch;
	vertex(int _pch, vertex *_p){ pch = _pch, p = _p; }
};

vertex *root = new vertex(-1, 0);

vertex* go(vertex *v, int c);

vertex* link(vertex *v){
	if(!v->link){
		if(v == root || v->p == root) v->link = root;
		else v->link = go(link(v->p), v->pch);
	}
	return v->link;
}

vertex* go(vertex *v, int c){
	if(!v->go[c]){
		if(v->to[c]) v->go[c] = v->to[c];
		else if(v == root) v->go[c] = root;
		else v->go[c] = go(link(v), c);
	}
	return v->to[c];
}

void add_string(string s){
	vertex *v = root;
	for(char _c : s){
		int c = int(_c-'a');
		if(!v->to[c]) v->to[c] = new vertex(c, v);
		v = v->to[c];
	}
}
