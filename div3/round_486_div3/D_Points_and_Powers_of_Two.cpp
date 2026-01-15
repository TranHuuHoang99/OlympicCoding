/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-01-13 11:49:40
**************************************************************************
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;

int n;
void solve(void) {
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++) cin >> A[i];
    sort(A.begin(), A.end());
    vector<int> ret = {A[0]};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= 31; j++) {
            int left_val = A[i] - (1 << j);
            int right_val = A[i] + (1 << j);
            bool isLeftExist = binary_search(A.begin(), A.end(), left_val);
            bool isRightExist = binary_search(A.begin(), A.end(), right_val);
            if (isLeftExist && isRightExist) {
                cout << 3 << endl;
                cout << left_val << ' ' << A[i] << ' ' << right_val << endl;
                return;
            }
            if (isLeftExist) {
                ret = {left_val, A[i]};
            }
            if (isRightExist) {
                ret = {right_val, A[i]};
            }
        }
    }
    cout << ret.size() << endl;
    for (int r : ret) cout << r << ' ';
    cout << endl;
}

signed main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}