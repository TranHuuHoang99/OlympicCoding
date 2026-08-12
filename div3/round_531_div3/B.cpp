/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-08-13 22:10:35
**************************************************************************
*/
#include <bits/stdc++.h>
#define int long long
#define pi acos(-1.0)
using namespace std;

const int N = 5e3+10;
int A[N];
int ret[N];
int n, k;
map<int,vector<int>> save;
void solve(void) {
    cin >> n >> k;
    int max_val = 0;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
        save[A[i]].push_back(i);
        max_val = max(max_val, (int)save[A[i]].size());
    }
    if (max_val > k || n < k) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    int cur = 0;
    for (pair<int,vector<int>> s : save) {
        for (int idx : s.second) {
            ret[idx] = cur % k + 1;
            cur++;
            cur %= k;
        }
    }
    for (int i = 1; i <= n; i++) cout << ret[i] << ' ';
    cout << '\n';
}
signed main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}





