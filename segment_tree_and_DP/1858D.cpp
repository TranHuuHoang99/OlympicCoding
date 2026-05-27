/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-05-27 15:40:08
**************************************************************************
*/
#include <bits/stdc++.h>
#define int long long
#define pi acos(-1.0)
using namespace std;

const int N = 3e3+10;
int n, m;
string str;
void solve(void) {
    str.clear();
    cin >> n >> m;
    cin >> str;
    str = " " + str;
    vector<int> temp(n+10, 0);
    for (int i = 1; i <= n; i++) {
        temp[i] = temp[i-1] + (int)(str[i] == '1');
    }
    auto get1 = [&] (int left, int right) -> int {
        return temp[right] - temp[left-1];
    };
    auto get0 = [&] (int left, int right) -> int {
        int all = right - left + 1;
        return all - get1(left, right);
    };
    vector<vector<int>> F_prefix(n+10, vector<int>(m+10, 0));
    vector<vector<int>> F_suffix(n+10, vector<int>(m+10, 0));
    for (int left = 1; left <= n; left++) {
        for (int right = left; right <= n; right++) {
            int cost0 = get0(left, right);
            if (cost0 <= m) {
                F_prefix[right][cost0] = max(F_prefix[right][cost0], right - left + 1);
                F_suffix[left][cost0] = max(F_suffix[left][cost0], right - left + 1);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            F_prefix[i][j] = max(F_prefix[i][j], F_prefix[i-1][j]);
            if (j > 0) {
                F_prefix[i][j] = max(F_prefix[i][j], F_prefix[i][j-1]);
            }
        }
    }
    for (int i = n; i >= 1; i--) {
        for (int j = 0; j <= m; j++) {
            F_suffix[i][j] = max(F_suffix[i][j], F_suffix[i+1][j]);
            if (j > 0) {
                F_suffix[i][j] = max(F_suffix[i][j], F_suffix[i][j-1]);
            }
        }
    }
    // max length of all char 1 we can get
    vector<int> F(n+10, -1ll);
    F[0] = F_prefix[n][m];
    for (int left = 1; left <= n; left++) {
        for (int right = left; right <= n; right++) {
            int cost1 = get1(left, right);
            if (cost1 <= m) {
                int length_all0 = right - left + 1;
                int cost0 = m - cost1;
                int max_length_all1 = max(F_prefix[left-1][cost0], F_suffix[right+1][cost0]);
                F[length_all0] = max(F[length_all0], max_length_all1);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        int ret = 0;
        for (int length0 = 0; length0 <= n; length0++) {
            if (F[length0] != -1) {
                ret = max(ret, i * length0 + F[length0]);
            }
        }
        cout << ret << ' ';
    }
    cout << endl;
}
signed main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}





