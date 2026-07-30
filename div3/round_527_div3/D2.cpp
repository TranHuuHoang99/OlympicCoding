/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-08-01 21:37:22
**************************************************************************
*/
#include <bits/stdc++.h>
#define int long long
#define pi acos(-1.0)
using namespace std;

const int N = 2e5+10;
int n;
int A[N];
void solve(void) {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> A[i];
    stack<int> st;
    int max_val = -1;
    for (int i = 1; i <= n; i++) {
        bool can_skip = false;
        while (!st.empty() && st.top() == A[i]) {
            max_val = max(max_val, st.top());
            st.pop();
            if (st.empty()) {
                can_skip = true;
            } else {
                can_skip = A[i] <= st.top();
            }
        }
        if (!can_skip) st.push(A[i]);
    }
    if (st.size() <= 1) {
        if (st.empty()) {
            cout << "YES\n";
        } else {
            if (st.top() < max_val) {
                cout << "NO\n";
            } else {
                cout << "YES\n";
            }
        }
    } else {
        cout << "NO\n";
    }
}
signed main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}





