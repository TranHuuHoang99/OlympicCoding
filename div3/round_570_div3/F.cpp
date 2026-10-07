/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-10-21 22:07:30
**************************************************************************
*/
#include <bits/stdc++.h>
#define int long long
#define pi acos(-1.0)
using namespace std;

void solve(void) {
    int n;
    cin >> n;
    set<int> save;
    for (int i = 1; i <= n; i++) {
        int val;
        cin >> val;
        save.insert(val);
    }
    int max_val = *save.rbegin();
    int ret = 0;
    if ((max_val % 2 == 0) && (max_val % 3 == 0) && (max_val % 5 == 0)) {
        int first_val = max_val / 2;
        int second_val = max_val / 3;
        int third_val = max_val / 5;
        if (save.count(first_val) && save.count(second_val) && save.count(third_val)) {
            ret = max(ret, first_val + second_val + third_val);
        }
    }
    vector<int> ret_arr;
    while (!save.empty() && ret_arr.size() < 3) {
        int cur_val = *prev(save.end());
        save.erase(prev(save.end()));
        bool valid = true;
        for (int r : ret_arr) {
            if (r % cur_val == 0) {
                valid = false;
                break;
            }
        }
        if (valid) ret_arr.push_back(cur_val);
    }
    ret = max(ret, accumulate(ret_arr.begin(), ret_arr.end(), 0ll));
    cout << ret << '\n';
}
signed main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}





