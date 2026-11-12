/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-11-12 22:02:44
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
    string str;
    cin >> str;
    vector<bool> used(27, false);
    for (int i = 0; i < n/2; i++) {
        if (str[i] != str[n-i-1]) {
            int left = min(str[i], str[n-i-1]) - 'a';
            int right = max(str[i], str[n-i-1]) - 'a';
            for (int j = left+1; j <= right; j++) used[j] = true;
        }
    }
    int ret = 0;
    for (int i = 0; i < 26; i++) {
        if (used[i]) ret++;
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





