/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-09-22 11:12:45
**************************************************************************
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5+10;
int n;
int A[N], B[N];
map<pair<int,int>,int> save;
void solve(void) {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> A[i];
    for (int i = 1; i <= n; i++) cin >> B[i];
    int add = 0;
    for (int i = 1; i <= n; i++) {
        if (A[i] == 0 && B[i] == 0) {
            add++;
            continue;
        }
        if (A[i] == 0) continue;
        int num = -B[i];
        int den = A[i];
        int g = __gcd(abs(num), abs(den));
        num /= g;
        den /= g;
        if (den < 0) {
            num = -num;
            den = -den;
        }
        save[{num, den}] += 1;
    }
    int ret = 0;
    for (auto it : save) {
        ret = max(ret, it.second);
    }
    ret += add;
    cout << ret << '\n';
}

signed main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}





