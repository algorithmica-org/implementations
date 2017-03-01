vector<bool> prime(n+1, true);

for(int i = 2; i <= n; i++)
	if(prime[i])
		for(int j = 2; j*i <= n; j++)
			prime[i*j] = false;
