/*
****************************************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2025-12-31 15:04:29
****************************************************************************************************
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, w;
void solve(void) {
    int min_val = 0;
    int max_val = 0;
    cin >> n >> w;
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        int val;
        cin >> val;
        sum += val;
        min_val = min(min_val, sum);
        max_val = max(max_val, sum);
    }
    int ret = w - max_val + min_val + 1;
    if (max_val > w || min_val < (-1ll * w) || ret > (w+1) || ret < 0) {
        cout << 0 << endl;
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





