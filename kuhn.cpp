#include <bits/stdc++.h>
using namespace std;

int n;

vector< vector<int> > g(n);
vector<int> m(n, -1);
vector<bool> used(n);

bool kuhn(int v){
	if(used[v]) return false;
	used[v] = true;
	for(int u : g[v]){
		if(m[u] == -1 || kuhn(m[u])){
			m[u] = v;
			return true;
		}
	}
	return false;
}


int main(){

	int cnt = 0;

	for(int i = 0; i < n; i++){
		used.assign(n, false);
		if(kuhn(i)) cnt++;
	}

	cout << cnt;

	return 0;
}
