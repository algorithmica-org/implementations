#include <bits/stdc++.h>
using namespace std;

// computes number of cube colorings with k colors

int binpow(int a, int n){
	int ans = 1;
	while(n){
		if(n&1) ans *= a;
		a *= a;
		n >>= 1;
	}
	return ans;
}

const int k = 3, n = 6;

vector<int> multiply(vector<int> a, vector<int> b){
	vector<int> ans(n);
	for(int i = 0; i < n; i++)
		ans[i] = a[b[i]];
	return ans;
}

int cycles(vector<int> a){
	vector<bool> used(n, 0);
	int ans = 0;
	for(int i = 0; i < n; i++){
		if(!used[i]){
			ans++;
			int p = i;
			while(!used[p]){
				used[p] = 1;
				p = a[p];
			}
		}
	}
	return ans;
}

int main() {

	set< vector<int> > s;
	s.insert({0, 1, 2, 3, 4, 5});
	vector<int> p1 = {0, 1, 3, 4, 5, 2}, p2 = {2, 4, 1, 3, 0, 5};
	for(int l = 0; l < 6; l++){
		set< vector<int> > t = s;;
		for(auto it = t.begin(); it != t.end(); ++it)
			s.insert(multiply(*it, p1)), s.insert(multiply(*it, p2));
	}

	int ans = 0;

	for(auto it = s.begin(); it != s.end(); ++it)
		ans += binpow(k, cycles(*it));

	cout << ans / (int) s.size();

	return 0;
}
