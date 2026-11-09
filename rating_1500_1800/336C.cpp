/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-11-09 20:59:55
**************************************************************************
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define int long long
#define pi acos(-1.0)
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

const int N = 1e5+10;
int n;
void solve(void) {
    cin >> n;
    vector<int> arr(n);
    for (auto& a : arr) cin >> a;
    map<int,vector<int>> save;
    for (int bit = 0; bit <= 31; bit++) {
        for (int i = 0; i < n; i++) {
            if (arr[i] & (1 << bit)) save[bit].push_back(i);
        }
    }
    pair<int,int> ret = {-1,-1};
    for (auto it = save.rbegin(); it != save.rend(); it++) {
        int cur_val = (1ll << 31) - 1;
        for (int i : it->second) cur_val &= arr[i];
        for (int bit = it->first; bit >= 0; bit--) {
            if ((cur_val % (1ll << bit)) == 0) {
                if (ret.first < bit) {
                    ret = {bit, it->first};
                } else if (ret.first == bit && save[ret.second].size() < it->second.size()) {
                    ret = {bit, it->first};
                }
            }
        }
    }
    if (ret.first == -1) {
        cout << -1 << '\n';
        return;
    }
    cout << save[ret.second].size() << '\n';
    for (int r : save[ret.second]) cout << arr[r] << ' ';
    cout << '\n';
}
signed main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}





