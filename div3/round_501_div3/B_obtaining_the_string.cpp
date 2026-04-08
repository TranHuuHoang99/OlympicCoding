/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-03-30 21:16:55
**************************************************************************
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;

int n;
string S, T;
void solve(void) {
    cin >> n;
    cin >> S;
    cin >> T;
    S = " " + S;
    T = " " + T;
    vector<int> ret;
    for (int i = 1; i <= n; i++) {
        if (S[i] == T[i]) continue;
        int idx = -1;
        for (int j = i+1; j <= n; j++) {
            if (S[j] == T[i]) idx = j;
        }
        if (idx == -1) {
            cout << idx << endl;
            return;
        } else {
            char temp = S[idx];
            for (int j = idx; j >= i+1; j--) {
                S[j] = S[j-1];
                ret.push_back(j-1);
            }
            S[i] = temp;
        }
    }
    cout << ret.size() << endl;
    for (int r : ret) cout << r << ' ';
    cout << endl;
}

signed main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}




 