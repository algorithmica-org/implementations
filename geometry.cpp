struct r{
	int x, y;
	r(){}
	r(int _x, int _y){ x = _x, y = _y; }
};

r operator+(r a, r b){ return r(a.x+b.x, a.y+b.y); }
r operator-(r a, r b){ return r(a.x-b.x, a.y-b.y); }

ostream& operator<<(ostream &out, r &p){ 
	out << p.x << " " << p.y << "\n";
	return out;            
}

istream& operator>>(istream &in, r &p){ 
	in >> p.x >> p.y;
	return in;
}

int cp(r a, r b){ return a.x*b.y - b.x*a.y; }
int dp(r a, r b){ return a.x*b.x + a.y*b.y; }
