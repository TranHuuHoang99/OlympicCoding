/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-07-23 22:44:20
**************************************************************************
*/
#include <bits/stdc++.h>
#define int long long
#define pi acos(-1.0)
using namespace std;

const int N = 1e6+10;
int n;
pair<int,int> save[N];
bool cmp(pair<int,int> a, pair<int,int> b) {
    return a.first < b.first;
}
void solve(void) {
    cin >> n;
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        int val;
        cin >> val;
        sum += val;
        save[i] = {val, i};
    }
    sort(save+1, save+1+n, cmp);
    vector<int> ret;
    for (int i = 1; i <= n; i++) {
        int rem_val = save[i].first;
        int sum_temp = sum - rem_val;
        int idx = (i == n) ? n-1 : n;
        int max_val = save[idx].first;
        sum_temp -= max_val;
        if (sum_temp == max_val) {
            ret.push_back(save[i].second);
        }
    }
    if (ret.empty()) {
        cout << 0 << '\n';
        return;
    }
    cout << ret.size() << '\n';
    for (int r : ret) cout << r << ' ';
    cout << '\n';
}
signed main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}





