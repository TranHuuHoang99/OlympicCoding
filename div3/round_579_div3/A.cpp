/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-10-24 10:21:20
**************************************************************************
*/
#include <bits/stdc++.h>
#define int long long
#define pi acos(-1.0)
using namespace std;

void solve(void) {
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    int start_pos = -1;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if (arr[i] == 1) start_pos = i;
    }
    bool ret_left = true;
    bool ret_right = true;
    for (int i = 0; i < n; i++) {
        ret_left &= (arr[(start_pos-i+n)%n] == i+1);
        ret_right &= (arr[(start_pos+i)%n] == i+1);
    }
    if (ret_left || ret_right) {
        cout << "yes\n";
    } else {
        cout << "no\n";
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





