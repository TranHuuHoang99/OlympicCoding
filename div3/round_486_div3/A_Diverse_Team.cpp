/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-01-09 15:01:26
**************************************************************************
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, k;
bool visited[110];
void solve(void) {
    cin >> n >> k;
    vector<int> ret;
    for (int i = 1; i <= n; i++) {
        int val;
        cin >> val;
        if (!visited[val] && ret.size() < k) {
            ret.push_back(i);
            visited[val] = true;
        }
    }
    if (ret.size() < k) {
        cout << "NO" << endl;
    } else {
        
        cout << "YES" << endl;
        for (int r : ret) cout << r << ' ';
        cout << endl;
    }
}

signed main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}