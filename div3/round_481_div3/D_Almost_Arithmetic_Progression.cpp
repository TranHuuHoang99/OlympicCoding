/*
****************************************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2025-12-31 12:54:14
****************************************************************************************************
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e5+10;
int n;
int A[N];
void solve(void) {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> A[i];
    if (n <= 2) {
        cout << 0 << endl;
        return;
    }
    int ret = INT32_MAX;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            int temp1 = A[1] + i;
            int temp2 = A[2] + j;
            int cnt = abs(i) + abs(j);
            int prev = temp2;
            int diff = temp2 - temp1;
            for (int idx = 3; idx <= n; idx++) {
                int next = prev + diff;
                int range = abs(next - A[idx]);
                if (range == 1) {
                    cnt++;
                } else if (range > 1) {
                    cnt = INT32_MAX;
                    break;
                }
                prev = next;
            }
            ret = min(ret, cnt);
        }
    }
    if (ret == INT32_MAX) {
        cout << -1 << endl;
    } else {
        cout << ret << endl;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}





