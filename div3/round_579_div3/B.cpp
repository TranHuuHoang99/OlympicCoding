/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-10-28 13:59:27
**************************************************************************
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(void) {
    int n;
    cin >> n;
    int m = 4 * n;
    vector<int> arr(m);
    for (int i = 0; i < m; i++) cin >> arr[i];
    sort(arr.begin(), arr.end());
    int fixed_area = arr[0] * arr[m-1];
    int left = 0;
    int right = m-1;
    while (left < right) {
        if (arr[left] != arr[left+1] || arr[right] != arr[right-1] || arr[left] * arr[right] != fixed_area) {
            cout << "no\n";
            return;
        }
        left += 2;
        right -= 2;
    }
    cout << "yes\n";
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






