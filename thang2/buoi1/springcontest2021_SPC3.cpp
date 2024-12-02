/*
 ******************************************************************************************
 *      * AUTHOR : hoangprodn
 *      * CREATED: 03.12.2024 20:37:41
 ******************************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 2e5+1;
int A[N];
int n, k;

void solve(void) {
	cin >> n >> k;		
	for (int i = 0; i < n; i++) cin >> A[i];
	int cnt = 0;
	int ret = INT32_MIN;
	int j = 0;
	for (int i = 0; i < n; i++) {
	 	if (A[i] == 0) cnt++;
	 	while (cnt > k) {
	 	 	if (A[j] == 0) {
	 	 	 	cnt--;
	 	 	}
	 	 	j++;
	 	}
	 	ret = max(ret, i-j+1);
	}
	cout << ret << endl;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t;
	cin >> t;
	while (t--) {
	 	solve();
	}

	return 0;
}
