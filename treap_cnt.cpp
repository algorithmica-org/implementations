#include <bits/stdc++.h>
using namespace std;

const int inf = 1e9;

struct treap{
	int min, val, priority;
	int size = 1;
	treap *l = NULL, *r = NULL;
	treap(int x){
		min = val = x;
		priority = rand();
	}
};

int size(treap *p){
	return (p == NULL) ? 0 : p->size;
}

int min(treap *p){
	return (p == NULL) ? inf : p->min;
}

void upd(treap *p){
	p->size = 1 + size(p->l) + size(p->r);
	p->min = min(p->val, min(min(p->l), min(p->r)));
}

pair<treap*, treap*> split(treap* p, int x){
	if(p == NULL) return {NULL, NULL};
	if(size(p->l)+1 <= x){
		pair<treap*, treap*> q = split(p->r, x - size(p->l) - 1);
		p->r = q.first;
		upd(p);
		return {p, q.second};
	}
	else{
		pair<treap*, treap*> q = split(p->l, x);
		p->l = q.second;
		upd(p);
		return {q.first, p};
	}
}

treap* merge(treap *l, treap *r){
	if(l == NULL) return r;
	if(r == NULL) return l;
	if(l->priority > r->priority){
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

void insert(treap *&p, int x, int val){
	treap *t = new treap(val);
	pair<treap*, treap*> q = split(p, x);
	p = merge(q.first, merge(t, q.second));
}

int rmq(treap *&p, int l, int r){
	pair<treap*, treap*> q1 = split(p, l-1);
	pair<treap*, treap*> q2 = split(q1.second, r-l+1);
	int ans = q2.first->min;
	p = merge(q1.first, merge(q2.first, q2.second));
	return ans;
}

int main(){
	ios::sync_with_stdio(false);

	treap *p = NULL;

	int n;
	cin >> n;

	for(int i = 0; i < n; i++){
		char type;
		cin >> type;
		if(type == '?'){
			int l, r;
			cin >> l >> r;
			cout << rmq(p, l, r) << endl;
		}
		else{
			int k, x;
			cin >> k >> x;
			insert(p, k, x);
		}
	}
	
	return 0;
}
