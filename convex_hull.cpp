vector< pair<int, int> > main(){
	ios::sync_with_stdio(false);

	long long n;
	cin >> n;
	vector<long long> x(n), y(n);

	long long p = 0;
	for(long long i = 0; i < n; i++){
		cin >> x[i] >> y[i];
		if(y[i] < y[p] || (y[i] == y[p] && x[i] < x[p]))
			p = i;
	}

	vector< pair<long double, long long> > a;
	for(long long i = 0; i < n; i++)
		if(i != p)
			a.push_back({atan2(y[i]-y[p], x[i]-x[p]), i}); 
	sort(a.begin(), a.end());

	vector<long long> hull;
	hull.push_back(p);
	
	for(long long i = 0; i < n-1; i++){
		long long l = a[i].second;
		cerr << l << endl;
		while(hull.size() > 1){
			long long k = hull[hull.size()-2], m = hull[hull.size()-1];
			if( (x[m]-x[k]) * (y[l]-y[k]) - (x[l]-x[k]) * (y[m]-y[k]) <= 0 ) 
				hull.pop_back();
			else
				break;
		}
		hull.push_back(l);
	}

	n = (long long) hull.size();
	long double P = 0, S = 0;
	for(long long i = 0; i < n; i++){
		cerr << i << endl;
		long long j = (i+1) % n;
		long long k = hull[i], l = hull[j];
		P += hypot(x[l]-x[k], y[l]-y[k]);
		S += x[k]*y[l] - x[l]*y[k];
	}

	cout << fixed;
	cout.precision(20);
	cout << P << endl;
	cout << fabs(S)/2 << endl;

	return 0;
}
