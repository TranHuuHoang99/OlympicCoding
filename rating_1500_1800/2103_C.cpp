/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-04-22 09:14:12
**************************************************************************
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5+10;
int n, k;
int save[N];
int prefix[N], suffix[N];
int prefix_min[N], suffix_min[N];
void solve(void) {
    cin >> n >> k;
    for (int i = 0; i <= n+5; i++) {
        prefix[i] = suffix[i] = 0;
        prefix_min[i] = suffix_min[i] = 2e6;
    }
    for (int i = 1; i <= n; i++) {
        int temp;
        cin >> temp;
        save[i] = (temp <= k) ? 1 : -1;
    }
    for (int i = 1; i <= n; i++) {
        prefix[i] = prefix[i-1] + save[i];
        prefix_min[i] = min(prefix_min[i-1], prefix[i]);
    }
    for (int i = n; i >= 1; i--) {
        suffix[i] = suffix[i+1] + save[i];
        suffix_min[i] = min(suffix_min[i+1], suffix[i]);
    }
    // check left and right
    int left_idx = 2e6;
    int right_idx = INT32_MIN;
    for (int i = 1; i <= n; i++) {
        if (prefix[i] >= 0) {
            left_idx = i;
            break;
        }
    }
    for (int i = n; i >= 1; i--) {
        if (suffix[i] >= 0) {
            right_idx = i;
            break;
        }
    }
    if (left_idx + 1 < right_idx) {
        cout << "YES" << endl;
        return;
    }
    // check left and mid
    for (int i = 1; i <= n-2; i++) {
        if (prefix[i] < 0) continue;
        if (suffix[i+1] >= suffix_min[i+2]) {
            cout << "YES" << endl;
            return;
        }
    }
    // check mid and right
    for (int i = n; i > 2; i--) {
        if (suffix[i] < 0) continue;
        if (prefix[i-1] >= prefix_min[i-2]) {
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
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





