#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 1e5+10;
int A[N];
int n;

void solve(void) {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> A[i];
	int ret = n-1;
	stack<int> st;
	for (int i = 0; i < n; i++) {
		while (!st.empty() && A[i] > A[st.top()]) {
			int temp = st.top();
			st.pop();
			if (!st.empty() && A[temp] < A[st.top()]) ret++;
		}
		st.push(i);
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


