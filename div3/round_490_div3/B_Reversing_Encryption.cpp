/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-01-27 16:39:04
**************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n;
string str;
void solve(void) {
    cin >> n >> str;
    vector<int> save;
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            save.push_back(i);
        }
    }
    for (int len : save) {
        reverse(str.begin(), str.begin()+len);
    }
    cout << str << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}





