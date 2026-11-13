/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-11-13 16:13:26
**************************************************************************
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;


void solve(void) {
    int n, k;
    cin >> n >> k;
    map<int,int> cnt_save;
    vector<int> arr(n+1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        cnt_save[arr[i]] += 1;
    }
    vector<int> diff;
    for (int i = 1; i <= n; i++) {
        if (arr[i] != arr[i-1]) diff.push_back(arr[i]);
    }
    if (diff.size() == 1) {
        cout << 1 << '\n';
        return;
    }
    vector<int> temp_arr;
    for (int d : diff) temp_arr.push_back(cnt_save[d]);
    sort(temp_arr.begin(), temp_arr.end());
    int cnt_sz = n;
    int idx = -1;
    int inc = 1;
    int ret = 0;
    while (cnt_sz > k) {
        auto it = lower_bound(temp_arr.begin(), temp_arr.end(), inc);
        inc++;
        if (it == temp_arr.end()) break;
        idx = it - temp_arr.begin();
        cnt_sz -= (temp_arr.size() - idx);
        if (cnt_sz == k) ret++;
    }
    if (idx == -1) {
        cout << ret << '\n';
        return;
    }
    int n_inc = temp_arr.size() - idx;
    while (cnt_sz < k) {
        cnt_sz += n_inc;
    }
    if (cnt_sz == k) ret++;
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






