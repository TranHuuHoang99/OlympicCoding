/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-02-10 14:18:25
**************************************************************************
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5+10;
int n, m;
int A[N];
map<int,int> save;
void solve(void) {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> A[i];
    int ret = 0;
    int sum = 0;
    save[0] = 1;
    bool hasMedian = false;
    for (int i = 1; i <= n; i++) {
        if (A[i] < m) {
            sum--;
        } else if (A[i] > m) {
            sum++;
        }
        if (A[i] == m) {
            hasMedian = true;
        }
        if (hasMedian) {
            ret += save[sum] + save[sum-1];
        } else {
            save[sum]++;
        }
    }
    cout << ret << endl;
}

signed main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}





