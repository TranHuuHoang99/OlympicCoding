/*
 ******************************************************************************************
 *      * AUTHOR : hoangprodn
 *      * CREATED: 02.12.2024 13:34:35
 ******************************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 1e6+1;
int A[N];
int n;

void solve(void) {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> A[i];
	int ret = INT32_MIN;
	stack<int> st;
	for (int i = 0; i < n; i++) {
	 	while (!st.empty() && A[i] <= A[st.top()]) {
	 	 	int idx = st.top();
	 	 	st.pop();
	 	 	int width = st.empty() ? i : i - st.top() - 1;
	 	 	if (width >= A[idx]) ret = max(ret, min(width, A[idx]));
	 	}
	 	st.push(i);
	}
	while (!st.empty()) {
	 	int idx = st.top();
	 	st.pop();
	 	int width = st.empty() ? n : n - st.top() - 1;
	 	if (width >= A[idx]) ret = max(ret, min(width, A[idx]));
	}

	if (ret == INT32_MIN) {
	 	cout << 0 << endl;
	 	return;
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

	solve();

	return 0;
}
