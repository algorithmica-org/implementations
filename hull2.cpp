struct r{
	int x, y;
	r(){}
	r(int _x, int _y){ x = _x, y = _y; }
	r(r a, r b){ x = b.x-a.x, y = b.y-a.y; }
	int len(){ return x*x + y*y; }
};

int cp(r a, r b){ return a.x*b.y - b.x*a.y; }
int dp(r a, r b){ return a.x*b.x + a.y*b.y; }

vector<r> hull(vector<r> p){
	int n = (int) p.size();
	r a = p[0];
	sort(p.begin(), p.end(), [](r a, r b){


	});
}
