#include <bits/stdc++.h>
using namespace std;

struct hashset{
	int size = 16, used = 0;
	const int k = 7, q = 4;
	int *a;
	hashset(){
		a = new int(size);
		memset(a, -1, size*sizeof(int));
	}
	void rehash(){
		size *= q;
		int *b = new int(size);
		memset(b, -1, size*sizeof(int));
		swap(b, a);
		for(int i = 0; i*q < size; i++)
			if(b[i] != -1)
				insert(b[i]);
		delete[] b;
	}
	void insert(int x){
		int t = (x*k) & (size-1);
		while(a[t] != -1 && a[t] != x) t = (t+1) & (size-1);
		if(a[t] != -1) a[t] = x, used++;
		if(used*q > size) rehash();
	}
	bool find(int x){
		int t = (x*k) & (size-1);
		while(a[t] != -1){
			if(a[t] == x) return 1;
			t = (t+1) & (size-1);
		}
		return 0;
	}
};

const int size = (1<<20), k = 7, r = 179;

int h(int x){ return (x^r)*k % size; }
