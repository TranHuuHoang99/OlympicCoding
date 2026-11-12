/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-11-12 22:42:12
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
    vector<int> arr(n+1);
    for (int i = 1; i <= n; i++) cin >> arr[i];
    int ret = 0;
    for (int i = 1; i <= n; i+=(k+1)) {
        ret += arr[i];
    }
    if (ret % 2 == 1) {
        cout << "Alice\n";
    } else {
        cout << "Bob\n";
    }
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





