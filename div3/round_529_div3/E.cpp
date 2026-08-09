/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-08-09 20:44:54
**************************************************************************
*/
#include <bits/stdc++.h>
#define int long long
#define pi acos(-1.0)
using namespace std;

const int N = 1e6+10;
int n;
string str;
int pre_pos[N], pre_neg[N];
int suf_pos[N], suf_neg[N];
bool ok_pre[N], ok_suf[N];
void solve(void) {
    cin >> n;
    cin >> str;
    str = " " + str;
    ok_pre[0] = true;
    for (int i = 1; i <= n; i++) {
        pre_pos[i] = pre_pos[i-1] + ((str[i] == '(') ? 1 : 0);
        pre_neg[i] = pre_neg[i-1] + ((str[i] == ')') ? 1 : 0);
        ok_pre[i] = ok_pre[i-1] && (pre_pos[i] >= pre_neg[i]);
    }
    ok_suf[n+1] = true;
    for (int i = n; i >= 1; i--) {
        suf_pos[i] = suf_pos[i+1] + ((str[i] == '(') ? 1 : 0);
        suf_neg[i] = suf_neg[i+1] + ((str[i] == ')') ? 1 : 0);
        ok_suf[i] = ok_suf[i+1] && (suf_neg[i] >= suf_pos[i]);
    }
    int ret = 0;
    for (int i = 1; i <= n; i++) {
        if (!ok_pre[i-1] || !ok_suf[i+1]) continue;
        int pre_val_pos = pre_pos[i-1];
        int pre_val_neg = pre_neg[i-1];
        if (str[i] == '(') {
            pre_val_neg += 1;
        } else {
            pre_val_pos += 1;
        }
        if (pre_val_pos < pre_val_neg) continue;
        int suf_val_pos = suf_pos[i+1];
        int suf_val_neg = suf_neg[i+1];
        int total_pos = pre_val_pos + suf_val_pos;
        int total_neg = pre_val_neg + suf_val_neg;
        if (total_pos == total_neg) ret++;
    }
    cout << ret << '\n';
}
signed main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}





