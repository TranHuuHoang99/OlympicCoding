/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-03-29 20:52:21
**************************************************************************
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, L, F;
void solve(void) {
    cin >> n >> L >> F;
    map<string,int> save;
    for (int i = 1; i <= n; i++) {
        string temp;
        cin >> temp;
        save[temp.substr(L-F)]++;
    }
    int ret = 0;
    for (auto it : save) ret += (it.second / 2);
    cout << ret << endl;
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





