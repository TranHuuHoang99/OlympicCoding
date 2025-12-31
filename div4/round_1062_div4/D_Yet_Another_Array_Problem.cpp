/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2025-10-28 22:05:36
**************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n;
void solve() {
    cin >> n;
    vector<ll> A(n);
    for (int i = 0; i < n; i++) cin >> A[i];
    ll common = A[0];
    for (int i = 1; i < n; i++) {
        common = gcd(common, A[i]);
    }
    if (common == 1) {
        cout << 2 << endl;
    } else {
        for (ll x = 2; x <= 1e18; x++) {
            if (gcd(x, common) == 1) {
                cout << x << endl;
                break;
            }
        }
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