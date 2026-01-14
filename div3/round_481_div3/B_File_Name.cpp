/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2025-12-24 14:49:25
**************************************************************************
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;

int n;
string str;
void solve(void) {
    cin >> n;
    cin >> str;
    vector<int> save;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (str[i] == 'x') {
            cnt++;
        }else {
            if (cnt >= 3) save.push_back(cnt);
            cnt = 0;
        }
    }
    if (cnt >= 3) save.push_back(cnt);
    int ret = 0;
    for (int s : save) {
        ret += s - 2;
    }
    cout << ret << endl;
}

signed main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}