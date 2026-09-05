/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-09-05 13:18:12
**************************************************************************
*/
#include <bits/stdc++.h>
#define int long long
#define pi acos(-1.0)
using namespace std;

const int N = 1e3+10;
int n;
int A[N];
int ret[25][25];
void solve(void) {
    cin >> n;
    for (int i = 1; i <= n * n; i++) {
        int val;
        cin >> val;
        A[val]++;
    }
    for (int i = 1; i <= n/2; i++) {
        for (int j = 1; j <= n/2; j++) {
            int val = -1;
            for (int k = 1; k <= 1e3; k++) {
                if (A[k] >= 4) {
                    val = k;
                    A[k] -= 4;
                    break;
                }
            }
            if (val == -1) {
                cout << "NO\n";
                return;
            }
            ret[i][j] = val;
            ret[n-i+1][j] = val;
            ret[i][n-j+1] = val;
            ret[n-i+1][n-j+1] = val;
        }
    }
    if (n % 2 == 1) {
        int mid = n/2+1;
        for (int j = 1; j <= n/2; j++) {
            int val = -1;
            for (int k = 1; k <= 1e3; k++) {
                if (A[k] >= 2) {
                    val = k;
                    A[k] -= 2;
                    break;
                }
            }
            if (val == -1) {
                cout << "NO\n";
                return;
            }
            ret[mid][j] = ret[mid][n-j+1] = val;
        }
        for (int i = 1; i <= n/2; i++) {
            int val = -1;
            for (int k = 1; k <= 1e3; k++) {
                if (A[k] >= 2) {
                    val = k;
                    A[k] -= 2;
                    break;
                }
            }
            if (val == -1) {
                cout << "NO\n";
                return;
            }
            ret[i][mid] = ret[n-i+1][mid] = val;
        }
        int val = -1;
        for (int k = 1; k <= 1e3; k++) {
            if (A[k] >= 1) {
                val = k;
                A[k] -= 1;
                break;
            }
        }
        ret[mid][mid] = val;
    }
    for (int k = 1; k <= 1e3; k++) {
        if (A[k] > 0) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << ret[i][j] << ' ';
        }
        cout << '\n';
    }
}
signed main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}





