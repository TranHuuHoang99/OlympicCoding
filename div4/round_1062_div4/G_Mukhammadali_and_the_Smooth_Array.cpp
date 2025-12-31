/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2025-10-30 21:57:55
**************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll N = 8e3+10;
int n;
ll A[N], C[N];
ll F[N];
void solve() {
    memset(F, 0, sizeof(F));
    cin >> n;
    ll sum = 0;
    for (int i = 1; i <= n; i++) cin >> A[i];
    for (int i = 1; i <= n; i++) {
        cin >> C[i];
        sum += C[i];
    }
    for (int i = 0; i <= n; i++) F[i] = LLONG_MIN;
    F[0] = 0;
    for (int i = 0; i <= n; i++) {
        for (int j = i+1; j <= n; j++) {
            if (F[i] == LLONG_MIN) continue;
            if (A[j] >= A[i]) {
                F[j] = max(F[j], F[i] + C[j]);
            }
        }
    }
    ll max_val = LLONG_MIN;
    for (int i = 1; i <= n; i++) max_val = max(max_val, F[i]);
    cout << sum - max_val << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) solve();
    return 0;
}