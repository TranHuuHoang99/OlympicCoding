/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-02-17 21:37:28
**************************************************************************
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5+10;
int n, m;
int A[N];
int cnt_greater(int target) {
    int ret = 0;
    int add = 0;
    int sum = n;
    vector<int> save(n*2+10, 0);
    save[sum] = 1;
    for (int i = 1; i <= n; i++) {
        if (A[i] < target) {
            sum--;
            add -= save[sum];
        } else {
            add += save[sum];
            sum++;
        }
        ret += add;
        save[sum]++;
    }
    return ret;
}
void solve(void) {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> A[i];
    cout << cnt_greater(m) - cnt_greater(m+1) << endl;
}

signed main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}





