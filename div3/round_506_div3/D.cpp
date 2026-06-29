/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-06-29 20:45:18
**************************************************************************
*/
#include <bits/stdc++.h>
#define int long long
#define pi acos(-1.0)
using namespace std;

const int N = 2e5+10;
int n, k;
int A[N];
int pw[12];
int len[N];
vector<int> rem[12];
void solve(void) {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> A[i];
    pw[0] = 1ll;
    for (int i = 1; i <= 10; i++) {
        pw[i] = pw[i-1] * 10 % k;
    }
    for (int i = 1; i <= n; i++) {
        int val = A[i];
        while (val) {
           len[i]++;
           val /= 10;
        }
        rem[len[i]].push_back(A[i] % k);
    }
    for (int i = 1; i <= 10; i++) sort(rem[i].begin(), rem[i].end());
    int ret = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 10; j++) {
            int val = (A[i] * pw[j]) % k;
            int target = (k - val) % k;
            auto it_left = lower_bound(rem[j].begin(), rem[j].end(), target);
            auto it_right = upper_bound(rem[j].begin(), rem[j].end(), target);
            ret += (it_right - it_left);
            if (len[i] == j && (val + (A[i] % k)) % k == 0) ret -= 1;
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





