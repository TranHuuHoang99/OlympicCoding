/*
 ******************************************************************************************
 *      * AUTHOR : hoangprodn
 *      * CREATED: 20.12.2024 20:09:00
 ******************************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 3e5+10;
double A[N];
double update[N];
int n, k;

bool valid(double mid) {
 	for (int i = 1; i <= n; i++) {
 	 	double temp = A[i] - mid;
 	 	update[i] = update[i-1] + temp;
 	}
 	double min_val = 0.0f;
 	for (int i = k; i <= n; i++) {
 	 	min_val = min(min_val, update[i-k]);
 	 	if (update[i] >= min_val) return true;
 	}
 	return false;
}

void solve(void) {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> A[i];
	double left = 0.0f;
	double right = 1000000.000000f;
	for (int i = 1; i <= 100; i++) {
	 	double mid = (left + right) / 2;
	 	if (valid(mid)) {
	 	 	left = mid;
	 	} else {
	 	 	right = mid;
        }       
	}
	cout << fixed << setprecision(6) << left << endl;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	freopen("rate.inp", "r", stdin);
	freopen("rate.out", "w", stdout);
	
	solve();

	return 0;
}
