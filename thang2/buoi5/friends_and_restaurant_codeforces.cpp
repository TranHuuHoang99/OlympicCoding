/*
 ******************************************************************************************
 *      * AUTHOR : hoangprodn
 *      * CREATED: 24.12.2024 20:49:51
 ******************************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 1e5+1;
ll A[N], B[N], update[N];
int n;

void solve(void) {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> A[i];
	for (int i = 0; i < n; i++) cin >> B[i];	
	for (int i = 0; i < n; i++) update[i] = B[i]-A[i];
	sort(update,update+n);
	int ret = 0;
	int left = 0;
	int right = n-1;
	while (left < right) {
	 	if (update[left]+update[right] < 0) {
	 	 	left++;
	 	 	continue;
	 	}
	 	ret++;
	 	left++;
	 	right--;
	}
	cout << ret << endl;
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
