/*
 ******************************************************************************************
 *      * AUTHOR : hoangprodn
 *      * CREATED: 22.12.2024 13:53:26
 ******************************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 2e5+1;
double A[N];
double update[N];
int n;

double f(double mid) {
 	for (int i = 1; i <= n; i++) update[i] = A[i]-mid;
 	double ret = 0.0f;
 	double min_val = 0.0f;
	double max_val = 0.0f;
	double sum = 0.0f;
	for (int i = 1; i <= n; i++) {
	 	sum += update[i];
	 	ret = max(ret, sum - min_val);
	 	ret = max(ret, max_val - sum);
	 	min_val = min(min_val, sum);
	 	max_val = max(max_val, sum);
	}
	min_val = 0.0f;
	max_val = 0.0f;
	sum = 0.0f;
	for (int i = n; i >= 1; i--) {
	 	sum += update[i];
	 	ret = max(ret, sum - min_val);
	 	ret = max(ret, max_val - sum);
	 	min_val = min(min_val, sum);
	 	max_val = max(max_val, sum);
	}
	return ret;
}

void solve(void) {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> A[i];
	double left = -20000.0f;
	double right = 20000.0f;
	double ret = 0.0f;
	for (int i = 1; i <= 200; i++) {
	 	double u = (left*2+right)/3.0f;
	 	double v = (left+right*2)/3.0f;
	 	double fu = f(u);
	 	double fv = f(v);
	 	if (fu >= fv) {
	 	 	ret = fu;
	 	 	left = u;
	 	} else {
	 	 	ret = fv;
	 	 	right = v;
	 	}
	}
	cout << fixed << setprecision(12) << ret << endl;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	solve();

	return 0;
}
