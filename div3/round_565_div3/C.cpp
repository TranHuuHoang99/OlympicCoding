/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-10-05 10:07:35
**************************************************************************
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 5e5+10;
int n;
vector<int> sample_arr = {4,8,15,16,23,42};
multiset<pair<int,int>> ms;
vector<int> init_idx;
void solve(void) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int val;
        cin >> val;
        ms.insert({val, i});
        if (val == 4) init_idx.push_back(i);
    }
    multiset<pair<int,int>> ret;
    for (int i : init_idx) {
        pair<int,int> cur_ele = {4, i};
        int idx = 0;
        multiset<pair<int,int>> remove_eles;
        while (!ms.empty() && idx < 6) {
            auto it = ms.lower_bound(cur_ele);
            if (it != ms.end() && it->first == sample_arr[idx]) {
                remove_eles.insert(cur_ele);
                int n_idx = it->second;
                ms.erase(it);
                idx++;
                if (idx < 6) cur_ele = {sample_arr[idx], n_idx};
            } else {
                break;
            }
        }
        if (idx != 6) {
            for (pair<int,int> r_e : remove_eles) {
                ret.insert(r_e);
            }
        }
    }
    cout << ms.size() + ret.size() << '\n';
}
signed main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}






