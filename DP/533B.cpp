/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-07-16 21:31:16
**************************************************************************
*/
#include <bits/stdc++.h>
#define int long long
#define pi acos(-1.0)
using namespace std;

const int N = 2e5+10;
const int INF = -1e12;
vector<int> adj[N];
int n;
int A[N];
int child[N];
// F is the maximum effiency that we can collect in each node
// with state = 0 is number member of the team that is even
// with state = 1 is number member of the team that is odd
int F[N][2];
void dfs(int u) {
    // base case dont have any member to pick yet, so the number of member is even
    F[u][0] = 0;
    // base case dont have any member
    F[u][1] = LLONG_MIN;
    for (int v : adj[u]) {
        dfs(v);
        int next_numb_even = max(F[u][0] + F[v][0], F[u][1] + F[v][1]);
        int next_numb_odd = max(F[u][0] + F[v][1], F[u][1] + F[v][0]);
        F[u][0] = next_numb_even;
        F[u][1] = next_numb_odd;
    }
    // case pick itself to be a member if current dont have any member
    // or have member which it's number is even
    F[u][1] = max(F[u][1], F[u][0] + A[u]);
}
void solve(void) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int u, val;
        cin >> u >> val;
        if (u != -1) adj[u].push_back(i);
        A[i] = val;
    }
    dfs(1);
    int ret = max(F[1][0], F[1][1]);
    cout << ret << endl;
}
signed main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}





