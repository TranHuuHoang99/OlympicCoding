/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-11-15 12:44:10
**************************************************************************
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define int long long
#define pi acos(-1.0)
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

const int mod = 998244353;
int arr[12][65][64];
int f[65][65][65];
int get_id(char c) {
    if (c >= 'a' && c <= 'z') return c - 'a';
    if (c >= 'A' && c <= 'Z') return c - 'A' + 26;
    return c - '0' + 52;
}
void solve(void) {
    int n;
    cin >> n;
    string str;
    set<string> check;
    for (int i = 1; i <= n; i++) {
        cin >> str;
        string inv_str = str;
        reverse(inv_str.begin(), inv_str.end());
        if (check.find(str) != check.end() || check.find(inv_str) != check.end())
            continue;
        check.insert(str);
        check.insert(inv_str);
        int len = str.size();
        int s_i = get_id(str[0]);
        int e_i = get_id(str[len-1]);
        arr[len][s_i][e_i] += 1;
        if (str != inv_str) {
            arr[len][e_i][s_i] += 1;
        }
    }
    int ret = 0;
    for (int len = 3; len <= 10; len++) {
        bool valid = false;
        for (int i = 0; i < 62; i++) {
            for (int j = 0; j < 62; j++) {
                if (arr[len][i][j] > 0) {
                    valid = true;
                    break;
                }
            }
            if (valid) break;
        }
        if (!valid) continue;
        for (int i = 0; i < 62; i++) {
            for (int j = i; j < 62; j++) {
                for (int k = j; k < 62; k++) {
                    int sum = 0;
                    for (int c = 0; c < 62; c++) {
                        sum = (sum % mod + (arr[len][c][i] % mod * arr[len][c][j] % mod * arr[len][c][k] % mod) % mod) % mod;
                    }
                    f[i][j][k] = f[i][k][j] = sum;
                    f[j][i][k] = f[j][k][i] = sum;
                    f[k][i][j] = f[k][j][i] = sum;
                }
            }
        }
        for (int i = 0; i < 62; i++) {
            for (int j = 0; j < 62; j++) {
                for (int k = 0; k < 62; k++) {
                    if (f[i][j][k] == 0) continue;
                    for (int c = 0; c < 62; c++) {
                        if (f[i][j][k] == 0 || f[i][j][c] == 0) continue;
                        int sum = (f[i][j][k] % mod * f[i][j][c] % mod) % mod;
                        if (f[i][k][c] == 0) continue;
                        sum = (sum % mod * f[i][k][c] % mod) % mod;
                        if (f[j][k][c] == 0) continue;
                        sum = (sum % mod * f[j][k][c] % mod) % mod;
                        ret = (ret % mod + sum % mod) % mod;
                    }
                }
            }
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





