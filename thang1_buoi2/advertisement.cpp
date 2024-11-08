#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 2e5+1;
ll A[N];
int n;

void solve(void) {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> A[i];
	stack<int> st;
	ll ret = LLONG_MIN;
	for (int i = 0; i < n; i++) {
		while (!st.empty() && A[i] <= A[st.top()]) {
			int idx = st.top();
			st.pop();
			int width = st.empty() ? i : i - st.top() - 1;
			ret = max(ret, A[idx] * 1ll * width);
		}
		st.push(i);
	}
	while (!st.empty()) {
		int idx = st.top();
		st.pop();
		int width = st.empty() ? n : n - st.top() - 1;
		ret = max(ret, A[idx] * 1ll * width);
	}

	cout << ret << endl;
}
  
int32_t main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
	solve();
	
    return 0;
}



