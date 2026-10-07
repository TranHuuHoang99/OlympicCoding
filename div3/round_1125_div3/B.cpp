/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-10-07 22:00:25
**************************************************************************
*/
#include <bits/stdc++.h>
#define int long long
#define pi acos(-1.0)
using namespace std;

int n;
string cmd_str;
void solve(void) {
    cin >> n;
    cin >> cmd_str;
    vector<bool> printed_docs(n, false);
    stack<int> st;
    for (int i = 0; i < n; i++) {
        if (cmd_str[i] == '1') {
            st.push(i);
        } else if (cmd_str[i] == '2') {
            if (!st.empty()) {
                printed_docs[st.top()] = true;
                st.pop();
            } else {
                printed_docs[i] = true;
            }
        } else {
            printed_docs[i] = true;
        }
    }
    vector<int> ret;
    for (int i = 0; i < n; i++) {
        if (!printed_docs[i]) ret.push_back(i);
    }
    cout << ret.size() << '\n';
    for (int r : ret) cout << r + 1 << ' ';
    cout << '\n';
}
signed main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}





