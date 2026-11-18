/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-11-18 21:27:28
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
    int n, m, k;
    cin >> n >> m >> k;
    string str;
    cin >> str;
    str = " " + str;
    str[0] = 'L';
    str += 'L';
    vector<int> swim_len(n+10, 2e5+10);
    vector<bool> ret(n+10, false);
    ret[0] = true;
    swim_len[0] = 0;
    for (int i = 0; i <= n+1; i++) {
        if (ret[i] == false) continue;
        if (str[i] == 'L') {
            for (int j = i+1; j <= min(i+m, n+1); j++) {
                if (str[j] == 'W' || str[j] == 'L') {
                    ret[j] = true;
                    swim_len[j] = min(swim_len[j], swim_len[i]);
                }
            }
        } else if (str[i] == 'W') {
            if (swim_len[i] + 1 <= k && str[i+1] != 'C') {
                ret[i+1] = true;
                swim_len[i+1] = min(swim_len[i+1], swim_len[i] + 1);
            }
        }
    }
    if (ret[n+1]) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
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





