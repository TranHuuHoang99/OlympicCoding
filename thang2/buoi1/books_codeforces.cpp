/*
 ******************************************************************************************
 *      * AUTHOR : hoangprodn
 *      * CREATED: 03.12.2024 19:17:34
 ******************************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 1e5+1;
ll A[N];
int n;
ll t;

void solve(void) {
	cin >> n >> t;
	for (int i = 0; i < n; i++) cin >> A[i];
	int ret = INT32_MIN;
	ll sum = 0;
	int j = 0;
	for (int i = 0; i < n; i++) {
	 	sum += A[i];
	 	while (sum > t) {
	 	 	sum -= A[j];
	 	 	j++;
		}
		ret = max(ret, i - j + 1);
	}
	cout << ret << endl;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

#ifdef HOANGPRODN_DEBUG
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
#endif // HOANGPRODN_DEBUG
                   
	solve();

	return 0;
}
