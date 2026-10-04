/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-10-04 13:12:52
**************************************************************************
*/
#include <bits/stdc++.h>
#define int long long
#define pi acos(-1.0)
using namespace std;

int n;
void solve(void) {
    cin >> n;
    vector<int> arr(3, 0);
    for (int i = 1; i <= n; i++) {
        int val;
        cin >> val;
        arr[val%3] += 1;
    }
    int ret = arr[0];
    int diff = min(arr[1], arr[2]);
    ret += diff;
    arr[1] -= diff;
    arr[2] -= diff;
    while (arr[1] >= 3) {
        arr[1] -= 3;
        ret++;
    }
    while (arr[2] >= 3) {
        arr[2] -= 3;
        ret++;
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





