/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-09-28 13:35:23
**************************************************************************
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5+10;
int n, k;
int A[N];
int pos[N];
int l_pos[N], r_pos[N];
bool visited[N];
int ret[N];
void solve(void) {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
        pos[A[i]] = i;
        l_pos[i] = i-1;
        r_pos[i] = i+1;
    }
    int team = 1;
    for (int val = n; val >= 1; val--) {
        int idx = pos[val];
        if (visited[idx]) continue;
        int left_bound = idx;
        for (int i = 0; i < k; i++) {
            if (l_pos[left_bound] >= 1) {
                left_bound = l_pos[left_bound];
            } else {
                break;
            }
        }
        int right_bound = idx;
        for (int i = 0; i < k; i++) {
            if (r_pos[right_bound] <= n) {
                right_bound = r_pos[right_bound];
            } else {
                break;
            }
        }
        int cur = left_bound;
        while (cur <= right_bound) {
            ret[cur] = team;
            visited[cur] = true;
            cur = r_pos[cur];
        }
        int prev_left_most = l_pos[left_bound];
        int next_right_most = r_pos[right_bound];
        if (prev_left_most >= 1) {
            r_pos[prev_left_most] = next_right_most;
        }
        if (next_right_most <= n) {
            l_pos[next_right_most] = prev_left_most;
        }
        team = 3 - team;
    }
    for (int i = 1; i <= n; i++) cout << ret[i];
    cout << '\n';
}
signed main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}





