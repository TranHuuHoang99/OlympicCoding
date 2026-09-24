/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-09-24 22:52:05
**************************************************************************
*/
#include <bits/stdc++.h>
#define int long long
#define pi acos(-1.0)
using namespace std;

const int N = 2e5+10;
int n;
int A[N];
int cnt[N];
void solve(void) {
    cin >> n;
    int min_idx = INT32_MAX;
    int max_idx = INT32_MIN;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
        cnt[A[i]]++;
        min_idx = min(min_idx, A[i]);
        max_idx = max(max_idx, A[i]);
    }
    int max_numb = -1;
    int target = -1;
    for (int i = min_idx; i <= max_idx; i++) {
        if (cnt[i] > max_numb) {
            max_numb = cnt[i];
            target = i;
        }
    }
    cout << n - max_numb << '\n';
    int idx = -1;
    for (int i = 1; i <= n; i++) {
        if (A[i] == target) {
            idx = i;
            break;
        }
    }
    int i = idx-1;
    while (i >= 1) {
        if (A[i] < target) {
            cout << 1 << ' ' << i << ' ' << i+1 << '\n';
        } else if (A[i] > target) {
            cout << 2 << ' ' << i << ' ' << i+1 << '\n';
        }
        i--;
    }
    int j = idx+1;
    while (j <= n) {
        if (A[j] < target) {
            cout << 1 << ' ' << j << ' ' << j-1 << '\n';
        } else if (A[j] > target) {
            cout << 2 << ' ' << j << ' ' << j-1 << '\n';
        }
        j++;
    }
}
signed main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}





