/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-11-15 15:40:25
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
    int n, x;
    cin >> n >> x;
    vector<int> a(n+1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a.begin()+1, a.end());
    vector<int> pref(n+1, 0);
    for (int i = 1; i <= n; i++) {
        pref[i] = pref[i-1] + a[i];
    }
    auto it = lower_bound(pref.begin()+1, pref.end(), x);
    if (it == pref.end() || *it > x) {
        it--;
    }
    int idx = it - pref.begin();
    int ret = 0;
    for (int i = idx; i >= 1; i--) {
        int get_val = (x - pref[i]) / i;
        ret += (get_val + 1);
    }
    cout << ret << '\n';
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





