/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-02-08 21:53:13
**************************************************************************
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(void) {
    int n;
    cin >> n;
    vector<int> ret;
    for (int i = 1; i <= n; i++) {
        int val;
        cin >> val;
        if (val == 1) {
            ret.push_back(val);
        } else {
            ret.back() = val;
        }
    }
    cout << ret.size() << endl;
    for (int r : ret) cout << r << ' ';
    cout << endl;
}

signed main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}





