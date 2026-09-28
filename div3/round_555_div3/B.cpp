/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-09-29 09:40:15
**************************************************************************
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;

int n;
string str;
char repl[10];
void solve(void) {
    cin >> n;
    cin >> str;
    for (int i = 1; i <= 9; i++) {
        cin >> repl[i];
    }
    string temp = str;
    for (int i = 0; i < n; i++) {
        int idx = temp[i] - '0';
        if (temp[i] <= repl[idx]) {
            temp[i] = repl[idx];
        } else {
            if (temp != str) {
                cout << temp << '\n';
                return;
            }
            temp = str;
        }
    }
    cout << temp << '\n';
}

signed main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}





