/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2025-10-28 21:46:14
**************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n;
string A, B;
void solve() {
    cin >> n;
    cin >> A >> B;
    vector<int> cnt1(26,0);
    vector<int> cnt2(26,0);
    for (char c : A) {
        cnt1[int(c-'a')] += 1;
    }
    for (char c : B) {
        cnt2[int(c-'a')] += 1;
    }
    for (int i = 0; i < 26; i++) {
        if (cnt1[i] != cnt2[i]) {
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