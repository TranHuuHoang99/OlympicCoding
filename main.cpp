#include <bits/stdc++.h>
#define ll long long

using namespace std;

struct Node {
	ll x, y, val;
};

const ll N = 1e5 * 2 + 1;
Node A[N];
ll dp[N];
ll pr[N];
int n;

bool cmp(Node a, Node b) {
	if (a.y == b.y) return a.x < b.x;
	return a.y < b.y;
}

void solve(void) {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> A[i].x >> A[i].y >> A[i].val;
	}

	sort(A, A+n, cmp);

	for (int i = 0; i < n; i++) {
		ll left = 0;
		ll right = i-1;
		ll idx = -1;
		
		while (left <= right) {
			ll mid = (left + right) >> 1;
			if (A[mid].y < A[i].x) {
				idx = mid;
				left = mid + 1;
			} else {
				right = mid - 1;
			}
		}

		if (idx != -1) {
			dp[i] = pr[idx] + A[i].val;
			pr[i] = max(pr[i-1], dp[i]);
		} else {
			dp[i] = A[i].val;
			pr[i] = max(pr[i-1], dp[i]);
		}
	}

	cout << *max_element(dp, dp+n) << endl;
}
  
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();	

	return 0;
}
