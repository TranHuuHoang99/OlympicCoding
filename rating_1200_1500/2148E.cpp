/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-11-18 22:19:19
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
    vector<int> a(n);
    map<int,int> cnt;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        cnt[a[i]] += 1;
    }
    for (auto& it : cnt) {
        if (it.second % k != 0) {
            cout << 0 << '\n';
            return;
        } else {
            it.second /= k;
        }
    }
    int ret = 0;
    map<int,int> track;
    for (int left = 0, right = 0; right < n; right++) {
        track[a[right]] += 1;
        while (track[a[right]] > cnt[a[right]]) {
            track[a[left]] -= 1;
            left++;
        }
        ret += (right - left + 1);
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





