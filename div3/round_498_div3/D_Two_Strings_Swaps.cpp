/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-03-18 21:05:25
**************************************************************************
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;

int n;
string str1, str2;
void solve(void) {
    cin >> n;
    cin >> str1;
    cin >> str2;
    int ret = 0;
    for (int i = 0; i < n/2; i++) {
        map<char,int> save;
        save[str1[i]]++;
        save[str1[n-i-1]]++;
        save[str2[i]]++;
        save[str2[n-i-1]]++;
        if (save.size() == 4) {
            ret += 2;
        } else if (save.size() == 3) {
            ret += 1 + (int)(str1[i] == str1[n-i-1]);
        } else if (save.size() == 2) {
            ret += (int)(save[str1[i]] != 2);
        }
    }
    if (n % 2 == 1) {
        if (str1[n/2] != str2[n/2]) ret++;
    }
    cout << ret << endl;
}

signed main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}





