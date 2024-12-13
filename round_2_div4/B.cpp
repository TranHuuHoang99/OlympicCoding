/*
 ******************************************************************************************
 *      * AUTHOR : hoangprodn
 *      * CREATED: 13.12.2024 21:48:08
 ******************************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 2e5+1;
int A[N];

void solve(void) {
	int n;
	cin >> n;
	memset(A,0,sizeof(A));
	int ret = -1;
	for (int i = 0; i < n; i++) {
	 	int temp;
	 	cin >> temp;
	 	A[temp]++;
	 	if (A[temp] >= 3) {
	 	 	ret = temp;
	 	}
	}
	cout << (ret == -1 ? -1 : ret) << endl;
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
