/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-02-08 22:18:40
**************************************************************************
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;

string str1, str2;
void solve(void) {
    cin >> str1 >> str2;
    if (str1.size() > str2.size()) {
        swap(str1, str2);
    }
    int len1 = str1.size();
    int len2 = str2.size();
    reverse(str1.begin(), str1.end());
    reverse(str2.begin(), str2.end());
    int cnt = 0;
    for (int i = 0; i < str1.size(); i++) {
        if (str1[i] == str2[i]) {
            cnt++;
        } else {
            break;
        }
    }
    int ret = len1 + len2 - 2 * (cnt);
    cout << ret << endl;
}

signed main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}





