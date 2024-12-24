/*
 ******************************************************************************************
 *      * AUTHOR : hoangprodn
 *      * CREATED: 24.12.2024 20:08:56
 ******************************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 2e5+1;
int A[N];
int n, x;

void solve(void) {
	cin >> n >> x;
	for (int i = 0; i < n; i++) cin >> A[i];
	sort(A,A+n);
	int ret = 0;
	int left = 0;
	int right = n-1;
	while (left <= right) {
	 	if (A[left] + A[right] <= x) left++;
	 	ret++;
	 	right--;
	}
	cout << ret << endl;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	solve();

	return 0;
}
