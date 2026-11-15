/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-11-15 14:34:43
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
    set<int> rm_set;
    stack<int> st;
    int rm_max = n - k;
    for (int i = 0; i < n; i++) {
        if (str[i] == ')' && !st.empty() && rm_set.size() < rm_max) {
            rm_set.insert(st.top());
            st.pop();
            rm_set.insert(i);
            continue;
        }
        st.push(i);
    }
    string ret = "";
    for (int i = 0; i < n; i++) {
        auto it = rm_set.find(i);
        if (it != rm_set.end()) continue;
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





