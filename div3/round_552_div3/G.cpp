/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-09-28 22:17:31
**************************************************************************
*/
#include <bits/stdc++.h>
#define int long long
#define pi acos(-1.0)
using namespace std;

const int N = 1e7+5;
int n;
int A[N];
int pos1[N];
int pos2[N];
void solve(void) {
    cin >> n;
    int max_val = 0;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
        max_val = max(max_val, A[i]);
        if (pos1[A[i]] == 0) {
            pos1[A[i]] = i;
        } else if (pos2[A[i]] == 0) {
            pos2[A[i]] = i;
        }
    }
    int ret_max = LLONG_MAX;
    pair<int,int> ret = {-1, -1};
    for (int g = 1; g <= max_val; g++) {
        int first_idx = -1, second_idx = -1;
        int first_val = -1, second_val = -1;
        for (int mul = g; mul <= max_val; mul += g) {
            if (pos1[mul] != 0) {
                if (first_idx == -1) {
                    first_idx = pos1[mul];
                    first_val = mul;
                } else if (second_idx == -1) {
                    second_idx = pos1[mul];
                    second_val = mul;
                }
            }
            if (pos2[mul] != 0 && second_idx == -1) {
                second_idx = pos2[mul];
                second_val = mul;
            }
            if (second_idx != -1) break;
        }
        if (second_idx != -1) {
            int cur_lcm = (first_val * second_val) / g;
            if (ret_max > cur_lcm) {
                ret_max = cur_lcm;
                ret = {first_idx, second_idx};
            }
        }
    }
    if (ret.first > ret.second) swap(ret.first, ret.second);
    cout << ret.first << ' ' << ret.second << '\n';
}
signed main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}





