/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-09-22 10:27:55
**************************************************************************
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5+10;
int n;
vector<int> A;
void solve(void) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int val;
        cin >> val;
        A.push_back(val);
    }
    sort(A.begin(), A.end());
    int ret = 1;
    for (int i = 0; i < n; i++) {
        int target = A[i];
        int left = lower_bound(A.begin(), A.end(), target-5) - A.begin();
        int mid = lower_bound(A.begin(), A.end(), target) - A.begin();
        int right = upper_bound(A.begin(), A.end(), target+5) - A.begin();
        ret = max(ret, max(mid-left, right-mid));
    }
    cout << ret << '\n';
}

signed main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}





