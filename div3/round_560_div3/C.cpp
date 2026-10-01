/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-10-01 14:59:20
**************************************************************************
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5+10;
int n;
string str;
bool isDeleted[N];
void solve(void) {
    cin >> n >> str;
    if (n == 1) {
        cout << n << '\n';
        return;
    }
    int left = 0;
    int right = 1;
    while (right < n) {
        while (str[left] == str[right]) {
            isDeleted[right++] = true;
        }
        left = right+1;
        right += 2;
    }
    string ret = "";
    for (int i = 0; i < n; i++) {
        if (!isDeleted[i]) ret += str[i];
    }
    if (ret.size() % 2 == 1) {
        ret.pop_back();
    }
    cout << n - ret.size() << '\n';
    cout << ret << '\n';
}

signed main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}





