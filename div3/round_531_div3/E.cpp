/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-08-16 18:01:49
**************************************************************************
*/
#include <bits/stdc++.h>
#define int long long
#define pi acos(-1.0)
using namespace std;

const int MOD = 998244353;
const int N = 2e5+10;
int n;
int A[N];
int F[N];
map<int,pair<int,int>> save;
void solve(void) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
        if (save[A[i]].first == 0) {
            save[A[i]] = {i, i};
        } else {
            save[A[i]].second = i;
        }
    }
    int ret = 1;
    pair<int, int> sample = save[A[1]];
    for (int i = 2; i <= n; i++) {
        auto [u, v] = save[A[i]];
        if (u > sample.second) {
            ret = ((ret % MOD) * 2) % MOD;
            sample = save[A[i]];
        } else {
            sample.second = max(sample.second, v);
        }
    }
    cout << ret << '\n';
}
signed main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}





