/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2025-11-04 22:39:51
**************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n;
string str1, str2;
void solve(void) {
    cin >> n;
    cin >> str1 >> str2;
    for (int i = 0; i < n; i++) {
        if ((str1[i] == 'R' && str2[i] != 'R') || (str1[i] != 'R' && str2[i] == 'R')) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) solve();
    return 0;
}





