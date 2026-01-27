/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-01-27 18:58:59
**************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n, k;
string str;
int cnt[30];
void solve(void) {
    cin >> n >> k;
    cin >> str;
    for (char c : str) {
        cnt[c-'a']++;
    }
    for (int i = 0; i < 26; i++) {
        k = max(k, 0);
        int min_val = min(k, cnt[i]);
        cnt[i] -= min_val;
        k -= min_val;
    }
    string ret = "";
    for (int i = n-1; i >= 0; i--) {
        int idx = int(str[i]-'a');
        if (cnt[idx] > 0) {
            cnt[idx]--;
            ret += str[i];
        }
    }
    reverse(ret.begin(), ret.end());
    cout << ret << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}





