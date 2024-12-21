/*
 ******************************************************************************************
 *      * AUTHOR : hoangprodn
 *      * CREATED: 22.12.2024 13:29:31
 ******************************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N =1e5+1;
pair<double,double> A[N];
int n;
double k;

double func(double t) {
 	double min_val = 1000000.000000f;
 	double max_val = 0.000000f;
 	for (int i = 0; i < n; i++) {
 	 	double speed = A[i].first;
 	 	double distance = A[i].second;
 	 	min_val = min(min_val, speed * t + distance);
 	 	max_val = max(max_val, speed * t + distance);
 	}
 	return max_val - min_val;
}

void solve(void) {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
	 	cin >> A[i].first >> A[i].second;
	}
	double left = 0.000000f;
	double right = k;
	for (int i = 1; i <= 1000; i++) {
	 	double u = (left*2 + right) / 3.000000f;
	 	double v = (left + right*2) / 3.000000f;
		if (func(u) > func(v)) {
		 	left = u;
		} else {
		 	right = v;
		}
	}
	cout << fixed << setprecision(6) << func(left) << endl;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	solve();

	return 0;
}
