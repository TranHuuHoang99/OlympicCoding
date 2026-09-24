/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-09-24 22:39:58
**************************************************************************
*/
#include <bits/stdc++.h>
#define int long long
#define pi acos(-1.0)
using namespace std;

const int N = 2e5+10;
int n;
int A[N];
set<int> incs;
set<int> decs;
void solve(void) {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> A[i];
    for (int i = 1; i <= n; i++) {
        auto it_inc = incs.find(A[i]);
        if (it_inc == incs.end()) {
            incs.insert(A[i]);
            continue;
        }
        auto it_decs = decs.find(A[i]);
        if (it_decs == decs.end()) {
            decs.insert(A[i]);
            continue;
        }
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    cout << incs.size() << '\n';
    for (int i : incs) cout << i << ' ';
    cout << '\n';
    cout << decs.size() << '\n';
    for (auto it = decs.rbegin(); it != decs.rend(); it++) cout << *it << ' ';
    cout << '\n';
}
signed main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}





