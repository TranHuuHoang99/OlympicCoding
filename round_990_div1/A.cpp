/*
 ******************************************************************************************
 *      * AUTHOR : hoangprodn
 *      * CREATED: 04.12.2024 22:26:23
 ******************************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 5e3+1;
int A[2][N];
int n;

void solve(void) {
	cin >> n;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < n; j++) cin >> A[i][j];         	
	}
	int ret = INT32_MIN;
	for (int i = 0; i < n; i++) {
	 	int temp = A[0][i] + A[1][i];
	 	for (int j = 0; j < n; j++) {
	 	 	if (i != j) temp += max(A[0][j], A[1][j]);
	 	}
	 	ret = max(ret, temp);
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
