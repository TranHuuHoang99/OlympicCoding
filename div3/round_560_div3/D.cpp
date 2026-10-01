/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-10-02 10:04:35
**************************************************************************
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;

int n;
void init(void) {
    
}
void solve(void) {
    cin >> n;
    vector<int> div;
    for (int i = 1; i <= n; i++) {
        int val;
        cin >> val;
        div.push_back(val);
    }
    sort(div.begin(), div.end());
    int ret = div[0] * div[n-1];
    vector<int> actual_div;
    for (int i = 2; i * i <= ret; i++) {
        if (ret % i == 0) {
            actual_div.push_back(i);
            if (i * i != ret) {
                actual_div.push_back(ret / i);
            }
        }
    }
    sort(actual_div.begin(), actual_div.end());
    if (actual_div == div) {
        cout << ret << '\n';
    } else {
        cout << -1 << '\n';
    }
}
signed main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}






