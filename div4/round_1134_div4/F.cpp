/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-11-12 23:17:51
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
    vector<int> arr(n+1, 0);
    for (int i = 1; i <= n; i++) cin >> arr[i];
    vector<int> ret(n+1, 0);
    for (int i = 1; i <= n; i++) {
        int pos = arr[i] + n - i + 1;
        if (pos < 1 || pos > n || ret[pos] != 0) {
            cout << -1 << '\n';
            return;
        }
        ret[pos] = i;
    }
    for (int i = 1; i <= n; i++) cout << ret[i] << ' ';
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





