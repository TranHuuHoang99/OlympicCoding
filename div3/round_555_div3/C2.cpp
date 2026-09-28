/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-09-29 14:15:50
**************************************************************************
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5+10;
int n;
int A[N];
void solve(void) {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> A[i];
    string ret = "";
    int cur = 0;
    int left = 1;
    int right = n;
    while (left <= right) {
        if (A[left] > cur && A[right] > cur && A[left] == A[right]) {
            int cntLeft = 0;
            int curLeft = cur;
            for (int i = left; i <= right; i++) {
                if (A[i] > curLeft) {
                    curLeft = A[i];
                    cntLeft++;
                } else {
                    break;
                }
            }
            int cntRight = 0;
            int curRight = cur;
            for (int i = right; i >= left; i--) {
                if (A[i] > curRight) {
                    curRight = A[i];
                    cntRight++;
                } else {
                    break;
                }
            }
            if (cntLeft >= cntRight) {
                for (int i = 0; i < cntLeft; i++) ret += 'L';
            } else {
                for (int i = 0; i < cntRight; i++) ret += 'R';
            }
            break;
        }
        if (A[left] > cur && (A[right] <= cur || A[left] < A[right])) {
            ret += 'L';
            cur = A[left];
            left++;
        } else if (A[right] > cur && (A[left] <= cur || A[right] < A[left])) {
            ret += 'R';
            cur = A[right];
            right--;
        } else {
            break;
        }
    }
    cout << ret.size() << '\n';
    cout << ret << '\n';
}

signed main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}





