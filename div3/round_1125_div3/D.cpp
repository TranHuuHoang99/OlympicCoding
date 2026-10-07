/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-10-07 22:42:44
**************************************************************************
*/
#include <bits/stdc++.h>
#define int long long
#define pi acos(-1.0)
using namespace std;

struct node_lab {
    int a, b, c;
    int sum;
};
const int N = 2e5+10;
int n, k;
int get_numb_ops(const node_lab& lab, int bound_val) {
    if (lab.sum >= bound_val) return 0;
    int diff = bound_val - lab.sum;
    int a = lab.a;
    int b = lab.b;
    int c = lab.c;
    if (a == b && b == c) return -1;
    if ((b > c) || (a > c) || (a > b)) return diff;
    if (c > b && b > a) return diff + 2 * min(c - b + 1, b - a + 1);
    return diff + 2;
}
bool check_valid(int bound_val, const vector<node_lab>& labs) {
    __int128_t total_ops = 0;
    for (const node_lab& lab : labs) {
        int ops = get_numb_ops(lab, bound_val);
        if (ops == -1) return false;
        total_ops += ops;
        if (total_ops > k) return false;
    }
    return total_ops <= k;
}
void solve(void) {
    cin >> n >> k;
    vector<node_lab> labs(n);
    int left = LLONG_MAX;
    for (int i = 0; i < n; i++) {
        cin >> labs[i].a >> labs[i].b >> labs[i].c;
        labs[i].sum = labs[i].a + labs[i].b + labs[i].c;
        left = min(left, labs[i].sum);
    }
    int right = 4e18;
    int ret = -1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (check_valid(mid, labs)) {
            ret = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    cout << ret << '\n';
}
signed main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}





