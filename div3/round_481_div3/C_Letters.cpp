/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2025-12-24 14:57:05
**************************************************************************
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5+10;
int n, m;
int prefix[N];
void solve(void) {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        int val;
        cin >> val;
        prefix[i] = prefix[i-1] + val;
    }
    for (int i = 1; i <= m; i++) {
        int val;
        cin >> val;
        int left = 1;
        int right = n;
        int idx = -1;
        while (left <= right) {
            int mid = (left+right)>>1;
            if (val <= prefix[mid]) {
                idx = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        cout << idx << ' ' << val - prefix[idx-1] << endl;
    }
}

signed main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}