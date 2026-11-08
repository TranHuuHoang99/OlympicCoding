/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-11-08 13:41:47
**************************************************************************
*/
#include <bits/stdc++.h>
#define int long long
#define pi acos(-1.0)
using namespace std;

const int N = 2e5+10;
int n, q;
int arr[N];
int payout[N];
int suf_max_payout[N];
int last_val_be_forced[N];
int last_time_be_forced[N];
void solve(void) {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    cin >> q;
    for (int i = 1; i <= q; i++) {
        int type;
        cin >> type;
        if (type == 1) {
            int index, val;
            cin >> index >> val;
            last_time_be_forced[index] = i;
            last_val_be_forced[index] = val;
        } else {
            int val;
            cin >> val;
            payout[i] = val;
        }
    }
    for (int i = q; i >= 1; i--) {
        suf_max_payout[i] = max(suf_max_payout[i+1], payout[i]);
    }
    for (int i = 1; i <= n; i++) {
        int last_time = last_time_be_forced[i];
        int last_val = last_val_be_forced[i];
        if (last_time != 0) {
            arr[i] = max(last_val, suf_max_payout[last_time+1]);
        } else {
            arr[i] = max(arr[i], suf_max_payout[1]);
        }
    }
    for (int i = 1; i <= n; i++) cout << arr[i] << ' ';
    cout << '\n';
}
signed main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}





