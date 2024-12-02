#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 2e5+1;
ll A[N];
int ret[N];
int n;

void solve(void) {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> A[i];
	stack<int> st;
	for (int i = 1; i <= n; i++) {
		while (!st.empty() && A[st.top()] >= A[i]) {
			st.pop();
		}
		if (st.empty()) {
			ret[i] = 0;
		} else {
			ret[i] = st.top();
		}
		st.push(i);
	}	
	for (int i = 1; i <= n; i++) cout << ret[i] << ' ';
	cout << endl;
}
  
int32_t main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
	solve();
	
    return 0;
}


