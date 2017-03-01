#include <bits/stdc++.h>
using namespace std;

/* van Emde Boas tree */

vector<int> ans;

const int base = 2;

struct node{
	int p, q;
	vector<node*> a;
	vector<int> b;
	node(int _p){
		p = _p;
		q = 1<<(p/2);
		if(p > base) a.assign(q, NULL);
		else b.assign(1<<base, 0);
	}
	void insert(int x){
		if(p == base) b[x]++;
		else{
			int k = x/q;
			if(!a[k]) a[k] = new node(p/2);
			a[k]->insert(x%q);
		}
	}
	bool check(int x){
		if(p == base) return b[x] > 0;
		else{
			int k = x/q;
			if(!a[k]) return false;
			return a[k]->check(x%q);
		}
	}
	void traverse(int l){
		if(p == base)
			for(int i = 0; i < 1<<base; i++)
				for(int j = 0; j < b[i]; j++)
					ans.push_back(l+i);
		else
			for(int i = 0; i < q; i++)
				if(a[i])
					a[i]->traverse(l+i*q);
	}
};

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	clock_t start = clock();

	int n = 3e5;

	while(n--) ans.push_back(rand());

	sort(ans.begin(), ans.end());

	/*
	node root(32);

	int n = 3e5;

	while(n--) root.insert(rand());

	root.traverse(0);
	*/

	cout << double(clock()-start)/CLOCKS_PER_SEC;

	return 0;
}
