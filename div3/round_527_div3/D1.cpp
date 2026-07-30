/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-08-01 20:05:39
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
    for (int i = 1; i <= n; i++) {
        bool can_next = false;
        while (!st.empty() && st.top() == A[i] % 2) {
            st.pop();
            if (!can_next) can_next = true;
        }
        if (!can_next) st.push(A[i]%2);
    }
    if (st.size() <= 1) {
        cout << "YES\n";
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





