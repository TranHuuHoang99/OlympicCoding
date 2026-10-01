/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-10-01 14:47:25
**************************************************************************
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5+10;
int n;
void solve(void) {
    cin >> n;
    int max_val = 0;
    multiset<int> ms;
    for (int i = 1; i <= n; i++) {
        int val;
        cin >> val;
        max_val = max(max_val, val);
        ms.insert(val);
    }
    int ret = -1;
    for (int i = 1; i <= max_val; i++) {
        auto it = ms.lower_bound(i);
        if (it != ms.end()) {
            ret = i;
            ms.erase(it);
        } else {
            break;
        }
    }
    cout << ret << '\n';
}

signed main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}





