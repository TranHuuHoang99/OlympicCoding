/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-11-16 23:52:32
**************************************************************************
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define int long long
#define pi acos(-1.0)
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

void solve(void) {
    int n, k;
    cin >> n >> k;
    string str;
    cin >> str;
    if (n == k) {
        cout << str << '\n';
        return;
    }
    vector<bool> rm_idx(n, false);
    stack<int> st;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (!st.empty() && str[i] == ')') {
            rm_idx[st.top()] = true;
            st.pop();
            rm_idx[i] = true;
            cnt += 2;
            if (cnt == n - k) break;
            continue;
        }
        st.push(i);
    }
    string ret = "";
    for (int i = 0; i < n; i++) {
        if (rm_idx[i]) continue;
        ret += str[i];
    }
    cout << ret << '\n';
}
signed main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}





