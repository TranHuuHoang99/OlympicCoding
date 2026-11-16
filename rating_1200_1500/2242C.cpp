/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-11-16 23:02:47
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
    vector<int> arr(n+1, 0);
    map<int,int> cnt;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        cnt[arr[i]] += 1;
    }
    vector<int> diff;
    for (int i = 1; i <= n; i++) {
        if (arr[i] != arr[i-1]) diff.push_back(arr[i]);
    }
    map<int,int> same_len;
    for (int d : diff) {
        same_len[cnt[d]] += 1;
    }
    int ret = 0;
    int cur_diff = diff.size();
    int cur_len = n;
    for (auto [len, numb] : same_len) {
        int reduce = len - 1;
        if (cur_len - reduce * cur_diff <= k && (k - cur_len + reduce * cur_diff) % cur_diff == 0) {
            ret += 1;
        }
        cur_diff -= numb;
        cur_len -= len * numb;
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





