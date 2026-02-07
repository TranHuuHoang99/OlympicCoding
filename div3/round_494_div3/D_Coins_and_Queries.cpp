/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-01-31 12:29:50
**************************************************************************
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;

map<int,int> save;
int n, q;
void solve(void) {
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        int val;
        cin >> val;
        save[val]++;
    }
    for (int query = 1; query <= q; query++) {
        int val;
        cin >> val;
        map<int,int> temp = save;
        int ret = 0;
        for (int bit = 30; bit >= 0; bit--) {
            int base = (1 << bit);
            if (temp.find(base) == temp.end()) continue;
            if (val < base) continue;
            int min_val = min(val / base, temp[base]);
            val -= min_val * base;
            ret += min_val;
        }
        if (val != 0) {
            cout << -1 << endl;
        } else {
            cout << ret << endl;
        }
    }
}

signed main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}





