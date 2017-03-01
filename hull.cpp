struct r{
	int x, y;
	r(){}
	r(r a, r b){
		x = b.x-a.x;
		y = b.y-a.y;
	}
	int len(){
		return x*x + x*x;
	}
};

int cp(r a, r b){
	return a.x*b.y - a.y*b.x;
}

vector<r> hull(vector<r> p){
	int n = (int) p.size();
	
	int _x = 1e4, _y = 1e4;

	vector<r> p(n);
	for(int i = 0; i < n; i++){
		cin >> p[i].x >> p[i].y;
		if(p[i].x < _x || (p[i].x == _x && p[i].y < _y)) _x = p[i].x, _y = p[i].y;
	}
	
	sort(p.begin(), p.end(), [&](r a, r b){
		a.x -= _x, a.y -= _y;
		b.x -= _x, b.y -= _y;
		int t = cp(a, b);
		return (t > 0 || (t == 0 && a.len() < b.len()));
	});

	vector<r> t(n);
	int s = 0;

	for(int i = 0; i < n; i++){
		if(s > 0 && (t[s-1].x == p[i].x && t[s-1].y == p[i].y)) continue;
		while(s >= 2){
			r a(t[s-2], t[s-1]);
			r b(t[s-2], p[i]);
			if(cp(a, b) <= 0) s--;
			else break;
		}
		t[s++] = p[i];
	}

	t.resize(s);
	return t;
}
