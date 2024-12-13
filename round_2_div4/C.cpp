/*
 ******************************************************************************************
 *      * AUTHOR : hoangprodn
 *      * CREATED: 13.12.2024 22:00:53
 ******************************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 50+1;
int A[N];

void solve(void) {
	int n;
	cin >> n;
	memset(A,0,sizeof(A));
	for (int i = 1; i <= n; i++) cin >> A[i];
	int ret1 = 0, ret2 = 0;
	int cnt1 = 0, cnt2 = 0;
	for (int i = 1; i <= n; i+=2) {
		ret1 += int(A[i]%2 == 0);
		cnt1++;
	}
	for (int i = 2; i <= n; i+=2) {
	 	ret2 += int(A[i]%2 == 0);
	 	cnt2++;
	}
	if ((ret1 == 0 || ret1 == cnt1) && (ret2 == 0 || ret2 == cnt2)) {
	 	cout << "yes" << endl;
	} else {
	 	cout << "no" << endl;
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

#ifdef HOANGPRODN_DEBUG
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
#endif // HOANGPRODN_DEBUG

	int t;
	cin >> t;
	while (t--) {
	 	solve();
	}

	return 0;
}
