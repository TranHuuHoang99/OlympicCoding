/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-03-22 20:28:45
**************************************************************************
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 21;
const int M = (1ll << 15)+1;
int A[N][N];
map<int,int> F[N][N];
int n, m, k;
int half;
int ret = 0;
void calSourceToDes(int i, int j, int val, int cnt) {
    val ^= A[i][j];
    if (cnt == half) {
        F[i][j][val]++;
        return;
    }
    if (i + 1 <= n) calSourceToDes(i+1, j, val, cnt+1);
    if (j + 1 <= m) calSourceToDes(i, j+1, val, cnt+1);
}
void calDesToSource(int i, int j, int val, int cnt) {
    if (cnt == (n+m-2-half)) {
        if (F[i][j].count(k^val)) {
            ret += F[i][j][k^val];
        }
        return;
    }
    if (i - 1 >= 1) calDesToSource(i-1, j, val ^ A[i][j], cnt+1);
    if (j - 1 >= 1) calDesToSource(i, j-1, val ^ A[i][j], cnt+1);
}
void solve(void) {
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> A[i][j];
        }
    }
    half = (n+m-2)/2;
    calSourceToDes(1, 1, 0, 0);
    calDesToSource(n, m, 0, 0);
    cout << ret << endl;
}

signed main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}





