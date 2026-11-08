/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-11-08 21:00:58
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

const int N = 2e5+10;
int n, m;
int origin_arr[N];
pair<int,int> arr[N];
pair<int,pair<int,int>> queries[N];
int ret[N];
void solve(void) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int val;
        cin >> val;
        origin_arr[i] = val;
        arr[i] = {-val, i};
    }
    sort(arr+1, arr+1+n);
    cin >> m;
    for (int i = 1; i <= m; i++) {
        int k, pos;
        cin >> k >> pos;
        queries[i] = {k, {pos, i}};
    }
    sort(queries+1, queries+1+m);
    int len = 0;
    ordered_set best_chain;
    for (int i = 1; i <= m; i++) {
        int k = queries[i].first;
        int pos = queries[i].second.first;
        int idx = queries[i].second.second;
        while (len < k) {
            best_chain.insert(arr[++len].second);
        }
        ret[idx] = origin_arr[*best_chain.find_by_order(pos-1)];
    }
    for (int i = 1; i <= m; i++) cout << ret[i] << '\n';
}
signed main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}





