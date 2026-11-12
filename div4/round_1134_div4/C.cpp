/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-11-12 21:49:08
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
    int n;
    cin >> n;
    map<int,int> save;
    for (int i = 1; i <= n; i++) {
        int val;
        cin >> val;
        save[val] += 1;
    }
    int ret = save.size();
    for (pair<int,int> p : save) {
        if (p.second > 1) ret += 1;
    }
    cout << ret << '\n';
    vector<int> ret_vec;
    stack<int> ret_st;
    for (auto& p : save) {
        ret_vec.push_back(p.first);
        p.second -= 1;
    }
    for (pair<int,int> p : save) {
        if (p.second > 0) {
            ret_st.push(p.first);
            p.second -= 1;
            for (int i = 1; i <= p.second; i++) ret_vec.push_back(p.first);
        }
    }
    while (!ret_st.empty()) {
        ret_vec.push_back(ret_st.top());
        ret_st.pop();
    }
    for (int r : ret_vec) cout << r << ' ';
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





