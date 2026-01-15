/*
****************************************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-01-15 20:31:53
****************************************************************************************************
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e3+10;
int a, n, m;
bool rain[N];
int weight[N];
int F[N][N]; // F[i][j] is the total of umb mass
// first array is position on map
// second array is current umb is caring
void solve(void) {
    cin >> a >> n >> m;
    for (int i = 1; i <= n; i++) {
        int left, right;
        cin >> left >> right;
        for (int j = left; j < right; j++) {
            rain[j] = true;
        }
    }
    vector<pair<int,int>> item(a+1, {LLONG_MAX, -1});
    for (int i = 0; i < m; i++) {
        int pos, val;
        cin >> pos >> val;
        weight[i] = val;
        if (item[pos].first > val) {
            item[pos] = {val, i};
        }
    }
    for (int i = 0; i <= a; i++) {
        for (int j = 0; j <= m; j++) {
            F[i][j] = LLONG_MAX;
        }
    }
    // because the begining could be zero so we will set the base (does not have umb) to be 0
    F[0][m] = 0;
    for (int i = 0; i < a; i++) {
        for (int j = 0; j <= m; j++) {
            if (F[i][j] == LLONG_MAX) continue;
            // in case we do not need umb and remove all current umb, so the next pos will take 0 weight
            if (!rain[i]) {
                F[i+1][m] = min(F[i+1][m], F[i][j]);
            }
            // in case we consider to continue caring current umb or leave it
            if (j < m) {
                F[i+1][j] = min(F[i+1][j], F[i][j] + weight[j]);
            }
            // in case we consider to keep the current umb or replace it with the new umb
            if (item[i].first != LLONG_MAX) {
                F[i+1][item[i].second] = min(F[i+1][item[i].second], F[i][j] + item[i].first);
            }
        }
    }
    int ret = LLONG_MAX;
    for (int i = 0; i <= m; i++) {
        ret = min(ret, F[a][i]);
    }
    if (ret == LLONG_MAX) {
        cout << -1 << endl;
    } else {
        cout << ret << endl;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}





