/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-03-30 21:02:34
**************************************************************************
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, m;
void solve(void) {
    cin >> n >> m;
    vector<bool> save(m+10, true);
    for (int i = 1; i <= n; i++) {
        int left, right;
        cin >> left >> right;
        for (int id = left; id <= right; id++) save[id] = false;
    }
    vector<int> ret;
    for (int i = 1; i <= m; i++) if (save[i]) ret.push_back(i);
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




 