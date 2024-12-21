/*
 ******************************************************************************************
 *      * AUTHOR : hoangprodn
 *      * CREATED: 22.12.2024 13:53:26
 ******************************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 2e5+10;
double A[N];
double update[N];
int n;

double func(double mid) {
	double ret = 0.0f;
	for (int i = 0; i < n; i++) {
	 	ret = max(ret, abs(A[i] - mid));
	}
	return ret;
}

void solve(void) {
	cin >> n;
	for (int i = 0; i < n; i++) {
	 	cin >> A[i];
	}
	if (n == 1) {
		double ret = 0.0f;
		cout << fixed << setprecision(15) << ret << endl;
		return;
	}
	double left = 0.0f;
	double right = 1000000.0f;
	for (int i = 1; i <= 100; i++) {
		double mid = (left+right) / 2.0f;
		if (func(left) > func(right)) {
		 	left = mid;
		} else {
		 	right = mid;
		}
	}
	update[0] = 0.0f;
	for (int i = 0; i < n; i++) {
		update[i+1] = update[i] + A[i] - left;	
	}
	double ret = 0.0f;
	for (int i = 1; i <= n; i++) ret = max(ret, abs(update[i]));
	cout << fixed << setprecision(15) << ret << endl;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	solve();

	return 0;
}
