/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2025-10-28 21:59:04
**************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n;
void solve() {
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++) cin >> A[i];
    bool isOdd = false;
    bool isEven = false;
    for (int i = 0; i < n; i++) {
        if (A[i] % 2 == 0) {
            isEven = true;
        } else {
            isOdd = true;
        }
    }
    if (isEven && isOdd) {
        sort(A.begin(), A.end());
        for (int r : A) cout << r << ' ';
        cout << endl;
    } else {
        for (int r : A) cout << r << ' ';
        cout << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) solve();
    return 0;
}