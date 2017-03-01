#include <bits/stdc++.h>
using namespace std;

const int k = 26;

struct vertex{
	vertex *to[k] = {NULL};
	vertex *link = NULL;
	int len = 0;
	vertex() {}
	vertex(vertex *v){
		for(int i = 0; i < k; i++)
			to[i] = v->to[i];
		link = v->link;
	}
};

int main(){
	ios::sync_with_stdio(false);

	vertex *root = new vertex(), *cur = root;

	int n;
	string s;
	cin >> n >> s;

	for(int i = 0; i < n; i++){
		int c = (int) (s[i] - 'a');
		vertex *v = cur;
		cur = new vertex;
		cur->len = v->len + 1;
		while(v != NULL && !v->to[c]){
			v->to[c] = cur;
			v = v->link;
		}
		if(v == NULL) cur->link = root;
		else{
			if(v->to[c]->len == v->len+1) cur->link = v->to[c];
			else{
				vertex *copy = new vertex(v->to[c]);
				copy->len = v->len + 1;
				cur->link = copy;
				for(vertex *u = v->link; u != NULL && u->to[c] == v->to[c]; u = u->link)
					u->to[c] = copy;
				v->to[c] = copy;
			}
		}
	}

	return 0;
}
