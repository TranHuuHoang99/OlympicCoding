/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-09-29 22:05:03
**************************************************************************
*/
#include <bits/stdc++.h>
#define int long long
#define pi acos(-1.0)
using namespace std;

int n, k;
void solve(void) {
    cin >> n >> k;
    /*
        we have formula like so
        x + (x+1) + (x+2) + ... (x+k-1) is the optimal ways
        after that we will fill the value which is not reach to the maximum
        of the previous value
        x = (n - k * (k-1) / 2) / k
    */
    if (k * (k-1) / 2 > n) {
        cout << "NO\n";
        return;
    }
    int prog = k * (k-1) / 2;
    int val = (n - prog) / k;
    if (val <= 0) {
        cout << "NO\n";
        return;
    }
    vector<int> arr(k);
    iota(arr.begin(), arr.end(), val);
    int sum = accumulate(arr.begin(), arr.end(), 0);
    if (sum > n) {
        cout << "NO\n";
        return;
    }
    int remain = n - sum;
    for (int i = k-1; i > 0 && remain > 0; i--) {
        int prev = arr[i-1] * 2;
        int diff = prev - arr[i];
        int reduce = min(diff, remain);
        remain -= reduce;
        arr[i] += reduce;
    }
    if (remain > 0) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    for (int a : arr) cout << a << ' ';
    cout << '\n';
}
signed main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}





