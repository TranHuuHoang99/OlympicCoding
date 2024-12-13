/*
 ******************************************************************************************
 *      * AUTHOR : hoangprodn
 *      * CREATED: 13.12.2024 12:48:20
 ******************************************************************************************
*/
#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 1e5+10;
int n, m, q;
int v[N], h[N];
int update1[N], update2[N], update3[N], update4[N];

void solve(void) {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> v[i];
	for (int i = 1; i <= n; i++) cin >> h[i];
	h[0] = INT32_MAX;
	h[n+1] = INT32_MAX;
	v[0] = 0;
	v[n+1] = m;
	for (int i = 1; i <= n; i++) {
	 	update1[i] = update1[i-1] + h[i];
	}
	stack<int> st;
	st.push(0);
	for (int i = 1; i <= n; i++) {
	 	while (!st.empty() && h[st.top()] < h[i]) st.pop();
	 	update2[i] = update2[st.top()] + (v[i]-v[st.top()]-1) * h[i] - (update1[i-1]-update1[st.top()]);
	 	st.push(i);
	}
	while (!st.empty()) st.pop();
	st.push(n+1);
	for (int i = n; i >= 1; i--) {
	 	update3[i] = update3[i+1] + h[i];
	}
	for (int i = n; i >= 1; i--) {
	 	while (!st.empty() && h[i] > h[st.top()]) st.pop();
	 	update4[i] = update4[st.top()] + (v[st.top()]-v[i]-1) * h[i] - (update3[i+1]-update3[st.top()]);
	 	st.push(i);
	}
	cin >> q;
	while (q--) {
	 	int k;
	 	cin >> k;
	 	int max_left = 0;
	 	int left = 0;
	 	int right = n;
	 	while (left <= right) {
	 	 	int mid = (left+right)/2;
	 	 	if (update2[mid] < k) {
	 	 	 	max_left = mid;
	 	 	 	left = mid + 1;
	 	 	} else {
	 	 	 	right = mid - 1;
	 	 	}
	 	}
	 	int min_right = n+1;
	 	left = max_left + 1;
	 	right = n+1;
	 	while (left <= right) {
	 	 	int mid = (left+right)/2;
	 	 	if (update4[mid] < k) {
	 	 	 	min_right = mid;
	 	 	 	right = mid - 1;
	 	 	} else {
	 	 	 	left = mid + 1;
	 	 	}
	 	}
	 	cout << max_left + n + 1 - min_right << endl;
	}
}

int32_t main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

#ifdef HOANGPRODN_DEBUG
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
#endif // HOANGPRODN_DEBUG
	
	solve();

	return 0;
}
