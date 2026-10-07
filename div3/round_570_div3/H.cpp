/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-10-20 21:32:26
**************************************************************************
*/
#include <bits/stdc++.h>
#define int long long
#define pi acos(-1.0)
using namespace std;

const int N = 105;
int n, k;
string str;
/*
    f[i][j] is the total number of different subsequence with i length
    , created from the first j character from original string
*/
int f[N][N];
/*
    pos[i][j: 1 -> 26] is last position of character j after we checking the current index
*/
int pos[N][27];
void solve(void) {
    cin >> n >> k;
    cin >> str;
    str = " " + str;
    for (int j = 0; j < 26; j++) pos[n][j] = 0;
    for (int i = n-1; i >= 0; i--) {
        for (int j = 0; j < 26; j++) {
            pos[i][j] = pos[i+1][j];
        }
        pos[i][str[i+1]-'a'] = i+1;
    }
    // empty is still a valid subsequence
    f[0][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int len = 0; len <= i; len++) {
            if (f[i][len] == 0) continue;
            for (int j = 0; j < 26; j++) {
                int n_pos = pos[i][j];
                if (n_pos > 0) f[n_pos][len+1] += f[i][len];
            }
        }
    }
    int ret = 0;
    for (int len = n; len >= 0; len--) {
        int total_valid_substr = 0;
        if (len == 0) {
            total_valid_substr = f[0][0];
        } else {
            for (int i = 1; i <= n; i++) total_valid_substr += f[i][len];
        }
        int diff = min(total_valid_substr, k);
        ret += diff * (n - len);
        k -= diff;
        if (k == 0) {
            cout << ret << '\n';
            return;
        }
    }
    cout << -1 << '\n';
}
signed main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}





