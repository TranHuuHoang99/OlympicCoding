#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 2e5+10;
int D[N];
pair<int,int> A[N];
int n;

void solve(void) {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> D[i];
	for (int i = 1; i <= n; i++) {
	 	cin >> A[i].first >> A[i].second;
	}
	int val = 0;
	stack<int> st;
	for (int i = 1; i <= n; i++) {
	 	if (D[i] == -1) {
	 	 	st.push(i);
	 	} else {
	 	 	val += D[i];
	 	}
	 	while (val < A[i].first) {
	 	 	if (st.empty()) {
	 	 	 	cout << -1 << endl;
	 	 	 	return;
	 	 	}
	 	 	val++;
	 	 	D[st.top()] = 1;
	 	 	st.pop();
	 	}
	 	while (val + st.size() > A[i].second) {
	 	 	if (st.empty()) {
	 	 	 	cout << -1 << endl;
	 	 	 	return;
	 	 	}
	 	 	D[st.top()] = 0;
			st.pop();
	 	}
	}
	for (int i = 1; i <= n; i++) cout << max(0, D[i]) << ' ';
	cout << endl;
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
	for (int i = 1; i <= t; i++) {
	 	solve();
	}

	return 0;
}
 