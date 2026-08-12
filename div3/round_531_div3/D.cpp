/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-08-16 13:14:26
**************************************************************************
*/
#include <bits/stdc++.h>
#define int long long
#define pi acos(-1.0)
using namespace std;

int n;
string str;
int cnt[3] = {0, 0, 0};
void solve(void) {
    cin >> n;
    cin >> str;
    for (int i = 0; i < n; i++) {
        cnt[str[i] - '0']++;
    }
    int len = n / 3;
    for (int i = 0; i < n && cnt[0] < len; i++) {
        int cur = str[i] - '0';
        if (cnt[cur] > len && cur != 0) {
            cnt[cur]--;
            cnt[0]++;
            str[i] = '0';
        }
    }
    for (int i = n-1; i >= 0 && cnt[2] < len; i--) {
        int cur = str[i] - '0';
        if (cnt[cur] > len && cur != 2) {
            cnt[cur]--;
            cnt[2]++;
            str[i] = '2';
        }
    }
    for (int i = 0; i < n && cnt[1] < len; i++) {
        if (str[i] == '2' && cnt[2] > len) {
            cnt[2]--;
            cnt[1]++;
            str[i] = '1';
        }
    }
    for (int i = n-1; i >= 0 && cnt[1] < len; i--) {
        if (str[i] == '0' && cnt[0] > len) {
            cnt[0]--;
            cnt[1]++;
            str[i] = '1';
        }
    }
    cout << str << '\n';
}
signed main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}





