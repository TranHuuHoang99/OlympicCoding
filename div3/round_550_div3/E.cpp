/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-09-24 23:10:07
**************************************************************************
*/
#include <bits/stdc++.h>
#define int long long
#define pi acos(-1.0)
using namespace std;

int n;
string s, t;
void solve(void) {
    cin >> n;
    cin >> s;
    cin >> t;
    vector<int> arr_s(n, 0);
    vector<int> arr_t(n, 0);
    vector<int> dist(n, 0);
    for (int i = 0; i < n; i++) {
        arr_s[i] = s[i] - 'a';
        arr_t[i] = t[i] - 'a';
    }
    int mem = 0;
    for (int i = n-1; i >= 0; i--) {
        int val = (arr_t[i] + arr_s[i] + mem);
        if (val >= 26) {
            val %= 26;
            mem = 1;
        } else {
            mem = 0;
        }
        dist[i] = val;
    }
    int rem = mem;
    for (int i = 0; i < n; i++) {
        int n_rem = dist[i] % 2;
        dist[i] = ((rem % 2 * 26 + dist[i]) - (rem % 2 * 26 + dist[i]) % 2) / 2;
        rem = n_rem;
    }
    string ret = "";
    for (int i = 0; i < n; i++) {
        ret += char(dist[i] + 'a');
    }
    cout << ret << '\n';
}
signed main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}





