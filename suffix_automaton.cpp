#include <bits/stdc++.h>
using namespace std;

const int k = 26;

struct vertex{
	vertex *to[k] = {0};
	vertex *link = 0;
	int len = 0;
};

vertex *root = new vertex, *cur = root;

void build(string s){
	for(char _c : s){
		int c = (int) (_c-'a');
		vertex *v = cur;
		cur = new vertex;
		cur->len = v->len+1;
		while(v && !v->to[c])
			v->to[c] = cur, v = v->link;
		if(!v) cur->link = root;
		else if(v->to[c]->len == v->len+1) cur->link = v->to[c];
		else{
			vertex *u = v->to[c];
			vertex *clone = new vertex;
			memcpy(clone->to, u->to, sizeof(u->to));
			clone->link = u->link;
			clone->len = v->len+1;
			while(v && v->to[c] == u)
				v->to[c] = clone, v = v->link;
			cur->link = u->link = clone;
		}
	}
}
