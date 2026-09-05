/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-09-06 10:35:36
**************************************************************************
*/
#include <bits/stdc++.h>
#define int long long
#define pi acos(-1.0)
using namespace std;

int n, m;
vector<int> A;
bool cmp(int a, int b) {
    return a > b;
}
int get_val(int target) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        int inc = i / target;
        sum += max(0ll, A[i] - inc);
    }
    return sum;
}
void solve(void) {
    cin >> n >> m;
    int quick_check = 0;
    for (int i = 1; i <= n; i++) {
        int val;
        cin >> val;
        A.push_back(val);
        quick_check += val;
    }
    if (quick_check < m) {
        cout << -1 << '\n';
        return;
    }
    sort(A.begin(), A.end(), cmp);
    int ret = -1;
    int left = 1;
    int right = n;
    while (left <= right) {
        int mid = (left+right)>>1;
        if (get_val(mid) >= m) {
            ret = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
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





