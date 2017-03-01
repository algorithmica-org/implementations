const int mod = 1e9+7, maxn;

int t[maxn];

int binpow(int a, int n){
	int ans = 1;
	while(n){
		if(n&1) ans = ans*a % mod;
		a = a*a % mod;
		n >>= 1;
	}
	return ans;
}

int inv(int x){
	return binpow(x, mod-2);
}

int c_n_k(int n, int k){
	return t[n]*inv(t[k]) % mod * inv(t[n-k]) % mod;
}

t[0] = 1;
for(int i = 1; i < maxn; i++)
	t[i] = i*t[i-1] % mod;
