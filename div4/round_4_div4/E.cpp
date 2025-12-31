/*
 ******************************************************************************************
 *      * AUTHOR : hoangprodn
 *      * CREATED: 01.01.2025 14:49:10
 ******************************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 2e5+1;
int update[N];
int n, s;

int valid(int left, int right) {
 	return update[right] - update[left-1];
}

void solve(void) {
	memset(update,0,sizeof(update));
	cin >> n >> s;
	for (int i = 1; i <= n; i++) {
	 	int temp;
	 	cin >> temp;
	 	update[i] = temp;
	 	update[i] += update[i-1];
	}
	int ret = INT32_MAX;
	for (int i = 1; i <= n; i++) {
	 	int left = i;
	 	int right = n;
	 	int idx = -1;
	 	while (left <= right) {
	 	 	int mid = (left+right)/2;
	 	 	if (valid(i,mid) <= s) {
	 	 	 	idx = mid;
	 	 	 	left = mid + 1;
	 	 	} else {
				right = mid - 1;
	 		}
	 	}
	 	if (idx == -1 || valid(i,idx) != s) continue;
	 	ret = min(ret, n - (idx-i+1));
	}
	cout << (ret == INT32_MAX ? -1 : ret) << endl;
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
