/*
****************************************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-01-14 11:03:54
****************************************************************************************************
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(void) {
    string str;
    cin >> str;
    int len = str.size();
    int ret = INT32_MAX;
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) {
            if (i == j) continue;
            int cnt = 0;
            string temp = str;
            for (int k = i; k < len-1; k++) {
                swap(temp[k], temp[k+1]);
                cnt++;
            }
            for (int k = j - (j>i); k < len-2; k++) {
                swap(temp[k], temp[k+1]);
                cnt++;
            }
            int pos = -1;
            for (int k = 0; k < len; k++) {
                if (temp[k] != '0') {
                    pos = k;
                    break;
                }
            }
            for (int k = pos; k > 0; k--) {
                swap(temp[k], temp[k-1]);
                cnt++;
            }
            int val = atoll(temp.c_str());
            if (val % 25 == 0) {
                ret = min(ret, cnt);
            }
        }
    }
    if (ret == INT32_MAX) {
        cout << -1 << endl;
    } else {
        cout << ret << endl;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}





