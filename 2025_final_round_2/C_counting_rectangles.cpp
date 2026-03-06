/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-03-02 21:26:50
**************************************************************************
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, m;
vector<vector<int>> A;
vector<int> save;
void solve(void) {
    cin >> n >> m;
    A.assign(n+10, vector<int>(m+1,0));
    save.assign(30,0);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> A[i][j];
        }
    }
    int ret = 0;
    if (n <= m) {
        for (int i = 1; i <= n; i++) {
            for (int j = i+1; j <= n; j++) {
                fill(save.begin(), save.end(), 0);
                for (int k = 1; k <= m; k++) {
                    int sumCol = A[i][k] + A[j][k];
                    int remain = 20 - sumCol;
                    if (2 <= remain && remain <= 18) {
                        ret += save[remain];
                    }
                    save[sumCol]++;
                }
            }
        }
    } else {
        for (int i = 1; i <= m; i++) {
            for (int j = i+1; j <= m; j++) {
                fill(save.begin(), save.end(), 0);
                for (int k = 1; k <= n; k++) {
                    int sumRow = A[k][i] + A[k][j];
                    int remain = 20 - sumRow;
                    if (2 <= remain && remain <= 18) {
                        ret += save[remain];
                    }
                    save[sumRow]++;
                }
            }
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





