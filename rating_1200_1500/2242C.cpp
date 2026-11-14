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
    vector<int> arr(n+1);
    map<int,int> save_cnt;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        save_cnt[arr[i]] += 1;
    }
    vector<int> diff;
    for (int i = 1; i <= n; i++) {
        if (arr[i] != arr[i-1]) diff.push_back(arr[i]);
    }
    map<int,vector<int>> same_numb;
    for (int d : diff) {
        int numb = save_cnt[d];
        same_numb[numb].push_back(d);
    }
    int ret = 0;
    int sum_survive = n;
    int rem_blocks = diff.size();
    for (auto& [sz, vec] : same_numb) {
        int x = sz - 1;
        int rem_len = sum_survive - x * rem_blocks;
        if (rem_len <= k && (k - rem_len) % rem_blocks == 0) {
            ret += 1;
        }
        sum_survive -= sz * vec.size();
        rem_blocks -= vec.size();
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






