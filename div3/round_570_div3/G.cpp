/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-10-21 22:18:13
**************************************************************************
*/
#include <bits/stdc++.h>
#define int long long
#define pi acos(-1.0)
using namespace std;

void solve(void) {
    int n;
    cin >> n;
    vector<int> cnt_types(n+1, 0);
    vector<int> cnt_gives(n+1, 0);
    for (int i = 1; i <= n; i++) {
        int type, state;
        cin >> type >> state;
        cnt_types[type] += 1;
        if (state == 1) {
            cnt_gives[type] += 1;
        }
    }
    vector<vector<int>> most_gives(n+1);
    for (int type = 1; type <= n; type++) {
        if (cnt_types[type] > 0) {
            most_gives[cnt_types[type]].push_back(cnt_gives[type]);
        }
    }
    priority_queue<int> pq;
    int ret_numb = 0;
    int ret_give = 0;
    for (int len = n; len >= 1; len--) {
        for (int gives : most_gives[len]) {
            pq.push(gives);
        }
        if (!pq.empty()) {
            int max_val = pq.top();
            pq.pop();
            ret_numb += len;
            ret_give += min(len, max_val);
        }
    }
    cout << ret_numb << ' ' << ret_give << '\n';
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





