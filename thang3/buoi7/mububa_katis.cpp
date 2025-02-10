/*
 ******************************************************************************************
 *      * AUTHOR : hoangprodn
 *      * CREATED: 10.02.2025 20:51:32
 ******************************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 3e3+5;
ll sum[N], A[N];
int pos[N][N];
int dp[N][N];
int n;

void solve(void) {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> A[i];
    for (int i = 1; i <= n; i++) {
        sum[i] = sum[i-1] + A[i];
    }
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            pos[i][j] = -1;
            dp[i][j] = -1;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            int left = j;
            int right = n;
            int idx = -1;
            while (left <= right) {
                int mid = (left+right) / 2;
                if (sum[mid] - sum[j] >= sum[j] - sum[i-1]) {
                    idx = mid;
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
            if (idx != -1) pos[i][j] = idx;
        }
    }
    dp[1][1] = 1;
    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= i; j++) {
            if (dp[i][j] == -1) continue;
            dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
            int temp = pos[dp[i][j]][i];
            if (temp != -1) {
                dp[temp][j+1] = max(dp[temp][j+1], i+1);
            }
        }
    }
    int ret = -1;
    for (int i = 1; i <= n; i++) {
        if (dp[n][i] != -1) {
            ret = i;
        }
    }   
    cout << ret << endl;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    solve();

    return 0;
}

