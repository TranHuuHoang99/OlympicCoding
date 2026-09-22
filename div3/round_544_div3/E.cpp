/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-09-22 14:39:20
**************************************************************************
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 5e3+10;
int n, k;
vector<int> A;
int F[N][N];
void solve(void) {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        int val;
        cin >> val;
        A.push_back(val);
    }
    sort(A.begin(), A.end());
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            F[i][j] = LLONG_MIN;
        }
    }
    F[0][0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            if (F[i][j] == LLONG_MIN) continue;
            // if we skip current student
            F[i+1][j] = max(F[i+1][j], F[i][j]);
            // if we choose this student to be the lowest skill range from A[i] -> A[i]+5
            auto it = upper_bound(A.begin()+i, A.end(), A[i] + 5);
            int idx = it - A.begin();
            int numb = idx - i;
            F[idx][j+1] = max(F[idx][j+1], F[i][j] + numb);
        }
    }
    int ret = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            ret = max(ret, F[i][j]);
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





