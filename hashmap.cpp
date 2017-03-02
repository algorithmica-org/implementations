const int size = (1<<24);
int a[size], b[size];

inline int h(int x){ return (x^179)*7; }

void h_upd(int x, int y){
	int t = h(x);
	int k = t % size;
	while(a[k] != -1 && a[k] != t) k = (k+1) % size;
	a[k] = t, b[k] = y; 
}

int h_get(int x, int y){
	int t = h(x);
	int k = t % size;
	while(a[k] != -1){
		if(a[k] == t) return b[k];
		k = (k+1) % size;
	}
	return 0;
}
