vector<int> compress(vector<int> a){
	set<int> s;
	map<int, int> m;
	for(int x : a) s.insert(x);
	int cnt = 0;
	for(int x : s) m[x] = cnt++;
	for(size_t i = 0; i < a.size(); i++)
		a[i] = m[a[i]];
	return a;
}
