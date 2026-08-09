/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-08-09 13:55:11
**************************************************************************
*/
#include <bits/stdc++.h>
#define int long long
#define pi acos(-1.0)
using namespace std;

int n, k;
void solve(void) {
    cin >> n >> k;
    int bit_cnt = __builtin_popcountll(n);
    if (k < bit_cnt || n < k) {
        cout << "NO\n";
        return;
    }
    priority_queue<int> pq;
    for (int i = 0; i <= 30; i++) {
        if (n & (1 << i)) {
            pq.push((1 << i));
        }
    }
    while (!pq.empty() && pq.size() < k) {
        int val = pq.top();
        pq.pop();
        pq.push(val / 2);
        pq.push(val / 2);
    }
    cout << "YES\n";
    while (!pq.empty()) {
        cout << pq.top() << ' ';
        pq.pop();
    }
    cout << '\n';
}
signed main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}





