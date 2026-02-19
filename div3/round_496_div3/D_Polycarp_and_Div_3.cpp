/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-02-08 23:08:21
**************************************************************************
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5+10;
string str;
// F[i][j][k] is the maximum cut, when we have i digits, j remain, k: state (0 is not cut, 1 is already cut)
int F[N][3][2];
void solve(void) {
    cin >> str;
    int n = str.size();
    str = " " + str;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= 2; j++) {
            for (int k = 0; k <= 1; k++) {
                F[i][j][k] = INT32_MIN;
            }
        }
    }
    for (int i = 0; i <= 1; i++) F[0][0][i] = 0;
    for (int i = 0; i < n; i++) {
        int val = (int)(str[i+1]-'0');
        for (int j = 0; j <= 2; j++) {
            for (int k = 0; k <= 1; k++) {
                if (F[i][j][k] == INT32_MIN) continue;
                if (k == 0) { // current digit is not cut
                    int n_remain = (j + val % 3) % 3;
                    // case not cut the next digit
                    F[i+1][n_remain][0] = max(F[i+1][n_remain][0], F[i][j][k]);
                    // case cut the next digit
                    F[i+1][n_remain][1] = max(F[i+1][n_remain][1], F[i][j][k] + (int)(n_remain == 0));
                } else { // current digit is cut
                    int n_remain = val % 3;
                    // case not cut the next digit
                    F[i+1][n_remain][0] = max(F[i+1][n_remain][0], F[i][j][k]);
                    // case cut the next digit
                    F[i+1][n_remain][1] = max(F[i+1][n_remain][1], F[i][j][k] + (int)(n_remain == 0));
                }
            }
        }
    }
    int ret = INT32_MIN;
    for (int remain = 0; remain <= 2; remain++) {
        for (int state = 0; state <= 1; state++) {
            ret = max(ret, F[n][remain][state]);
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





