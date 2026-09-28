/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-09-28 23:38:34
**************************************************************************
*/
#include <bits/stdc++.h>
#define int long long
#define pi acos(-1.0)
using namespace std;

int f(int x) {
    x += 1;
    while (x % 10 == 0) x /= 10;
    return x;
}
void solve(void) {
    int n;
    cin >> n;
    set<int> save;
    while (save.find(n) == save.end()) {
        save.insert(n);
        n = f(n);
    }
    cout << save.size() << '\n';
}
signed main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}





