#include <bits/stdc++.h>
using namespace std;

const double eps = 1e-9;

struct r{
	double x, y;
	r(){}
	r(double _x, double _y){ x = _x, y = _y; }
};

r operator+(r a, r b){ return r(a.x+b.x, a.y+b.y); }
r operator-(r a, r b){ return r(a.x-b.x, a.y-b.y); }

istream& operator>>(istream &in, r &p){ 
	in >> p.x >> p.y;
	return in;
}

ostream& operator<<(ostream &out, r &p){ 
	out << p.x << " " << p.y << "\n";
	return out;            
}

double cp(r a, r b){ return a.x*b.y - b.x*a.y; }
double dp(r a, r b){ return a.x*b.x + a.y*b.y; }

struct l{
	double a, b, c;
	l(r p, r q){
		// ax1 + by1 + c = 0
		// ax2 + by2 + c = 0
		// y = (y2-y1)/(x2-x1)*x + y1-(y2-y1)/(x2-x1)*x1
		// (x2-x1)y - (y2-y1)x - (x2-x1)y1 + (y2-y1)x1 = 0
		a = -(q.y-p.y);
		b = q.x-p.x;
		c = -(a*p.x + b*p.y);
	}
};

r intersect(l p, l q){
	// a1 b1 = -c1
	// a2 b2 = -c2
	cerr << p.a << " " << p.b << " " << p.c << endl;
	cerr << q.a << " " << q.b << " " << q.c << endl;
	if(abs(p.a) < eps) swap(p, q);
	p.c *= -1, q.c *= -1;
	p.c /= p.a, p.b /= p.a, p.a = 1;
	q.b -= q.a*p.b, q.c -= q.a*p.c;
	q.c /= q.b, q.b = 1;
	p.c -= p.b*q.c;
	return r(p.c, q.c);
}

bool inside(l p, r q){
	return p.a*q.x + p.b*q.y + p.c > 0;
}

int main(){
	int n;
	cin >> n;

	r p;
	cin >> p;
	n--;

	vector<l> t(n);

	for(int i = 0; i < n; i++){
		r q;
		cin >> q;
		t[i] = l(q, p);
		p = q;
	}

	sort(t.begin(), t.end(), [](l a, l b){

	});


	return 0;
}
