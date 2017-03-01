#include <bits/stdc++.h>
using namespace std;

int k = 26;

struct vertex{
	vertex *to[26] = {NULL};
	vertex *link = NULL;
	int len = 0;
	bool used = false;
};

int ans = 0;

void dfs(vertex *v){
	if(!v || v->used) return;
	v->used = true;
	if(v->link) ans += v->len - v->link->len;
	for(int i = 0; i < k; i++)
		dfs(v->to[i]);
}

int main(){
	ios::sync_with_stdio(false);

	string s;
	cin >> s;

	vertex *root = new vertex, *cur = root;

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
			for(int i = 0; i < k; i++)
				clone->to[i] = u->to[i];
			clone->link = u->link;
			clone->len = v->len+1;
			while(v && v->to[c] == u)
				v->to[c] = clone, v = v->link;
			cur->link = u->link = clone;
		}
	}

	dfs(root);
	cout << ans;

	return 0;
}
