/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-09-05 12:53:19
**************************************************************************
*/
#include <bits/stdc++.h>
#define int long long
#define pi acos(-1.0)
using namespace std;

const int N = 2e5+10;
int n;
int sum_odd[N];
int sum_even[N];
int A[N];
void solve(void) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
        if (i % 2 == 0) {
            sum_even[i] = sum_even[i-1] + A[i];
            sum_odd[i] = sum_odd[i-1];
        } else {
            sum_odd[i] = sum_odd[i-1] + A[i];
            sum_even[i] = sum_even[i-1];
        }
    }
    int ret = 0;
    for (int i = 1; i <= n; i++) {
        if (i % 2 == 1) {
            int cost_odd_left = sum_odd[i-1];
            int cost_odd_right = sum_even[n] - sum_even[i];
            int cost_even_left = sum_even[i-1];
            int cost_even_right = sum_odd[n] - sum_odd[i];
            if (cost_odd_left + cost_odd_right == cost_even_left + cost_even_right)
                ret++;
        } else {
            int cost_even_left = sum_even[i-1];
            int cost_even_right = sum_odd[n] - sum_odd[i];
            int cost_odd_left = sum_odd[i-1];
            int cost_odd_right = sum_even[n] - sum_even[i];
            if (cost_even_left + cost_even_right == cost_odd_left + cost_odd_right)
                ret++;
        }
    }
    cout << ret << '\n';
}
signed main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}





