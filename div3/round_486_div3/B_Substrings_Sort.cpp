/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-01-12 08:55:51
**************************************************************************
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;

int n;
bool cmp(const string& a, const string& b) {
    return a.size() < b.size();
}
void solve(void) {
    cin >> n;
    vector<string> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    sort(A.begin(), A.end(), cmp);
    for (int i = 0; i < n-1; i++) {
        bool isValid = false;
        string str1 = A[i];
        string str2 = A[i+1];
        for (int j = 0; j <= str2.size()-str1.size(); j++) {
            if (str1 == str2.substr(j, str1.size())) {
                isValid = true;
                break;
            }
        }
        if (!isValid) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
    for (string str : A) cout << str << endl;
}

signed main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}