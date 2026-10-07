/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-10-07 22:13:53
**************************************************************************
*/
#include <bits/stdc++.h>
#define int long long
#define pi acos(-1.0)
using namespace std;

int n;
void solve(void) {
    cin >> n;
    vector<int> arr(n+1,0);
    for (int i = 1; i <= n; i++) cin >> arr[i];
    n -= 4;
    vector<int> sum_triads(n+1, 0);
    map<int,int> save;
    for (int i = 1; i <= n; i++) {
        sum_triads[i] = arr[i] + arr[i+2] - arr[i+4];
        save[sum_triads[i]] += 1;
    }
    int ret = 0;
    for (pair<int,int> s : save) {
        ret += (s.second * (s.second - 1)) / 2;
    }
    for (int i = 1; i <= n; i++) {
        if (i+2 <= n && sum_triads[i] == sum_triads[i+2]) {
            ret -= 1;
        }
        if (i+4 <= n && sum_triads[i] == sum_triads[i+4]) {
            ret -= 1;
        }
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





