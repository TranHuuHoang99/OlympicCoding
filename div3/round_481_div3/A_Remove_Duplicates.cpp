/*
****************************************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2025-12-31 10:45:22
****************************************************************************************************
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e3+10;
int n;
int A[N];
bool visited[N];
void solve(void) {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> A[i];
    vector<int> ret;
    for (int i = n; i >= 1; i--) {
        if (visited[A[i]]) continue;
        ret.push_back(A[i]);
        visited[A[i]] = true;
    }
    cout << ret.size() << endl;
    reverse(ret.begin(), ret.end());
    for (int r : ret) cout << r << ' ';
    cout << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}





