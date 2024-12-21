/*
 ******************************************************************************************
 *      * AUTHOR : hoangprodn
 *      * CREATED: 21.12.2024 12:57:50
 ******************************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

double a, h;

double performance(double mid) {
 	if (mid * 3 >= h) return 100.0f;
 	if (mid * 6 >= h) {
 	 	double temp = (100.0f - a) / (h/3.0f - h/6.0f);
 	 	return a + temp * (mid - h/6.0f);
 	}
 	double temp = a / (h/6.0f);
 	return temp * mid;
}

void solve(void) {
	cin >> a >> h;
	double left = 0.0f;
	double right = h;
	for (int i = 1; i <= 100; i++) {
	 	double u = (left*2 + right) / 3.0f;
	 	double v = (left + right*2) / 3.0f;
	 	if ((h-u) * performance(u) > (h-v) * performance(v)) {
			right = v;
	 	} else {
	 	 	left = u;
	 	}
	}
	cout << fixed << setprecision(8) << (h-left) * performance(left) << endl;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

#ifdef HOANGPRODN_DEBUG
	freopen("input.inp", "r", stdin);
	freopen("output.out", "w", stdout);
#endif

#ifdef HOANGPRODN_DEBUG
	int test_time;
	cin >> test_time;
	while (test_time--) {
#endif
	solve();
#ifdef HOANGPRODN_DEBUG
	}
#endif

	return 0;
}















