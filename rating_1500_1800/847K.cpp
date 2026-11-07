/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-11-07 15:48:09
**************************************************************************
*/
#include <bits/stdc++.h>
#define int long long
#define pi acos(-1.0)
using namespace std;

const int N = 610;
int n, a, b, k, f;
int cnt = 1;
map<string,int> path_converter;
pair<string,string> arr[N];
void solve(void) {
    cin >> n >> a >> b >> k >> f;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i].first >> arr[i].second;
        auto it = path_converter.find(arr[i].first);
        if (it == path_converter.end()) {
            path_converter[arr[i].first] = cnt++;
        }
        it = path_converter.find(arr[i].second);
        if (it == path_converter.end()) {
            path_converter[arr[i].second] = cnt++;
        }
    }
    map<pair<int,int>, int> cost_same_route;
    int t_cost_w_f = 0;
    int pv = -1;
    for (int i = 1; i <= n; i++) {
        int u = path_converter[arr[i].first];
        int v = path_converter[arr[i].second];
        int cost = a;
        if (u == pv) cost = b;
        t_cost_w_f += cost;
        int uu = u;
        int vv = v;
        if (uu > vv) swap(uu, vv);
        cost_same_route[{uu, vv}] += cost;
        pv = v;
    }
    vector<int> all_costs;
    for (pair<pair<int,int>, int> p : cost_same_route) {
        all_costs.push_back(p.second);
    }
    sort(all_costs.begin(), all_costs.end(), [](int ta, int tb) -> bool {
        return ta > tb;
    });
    for (int i = 0; i < min((int)all_costs.size(), k); i++) {
        if (all_costs[i] > f) {
            t_cost_w_f -= all_costs[i];
            t_cost_w_f += f;
        } else {
            break;
        }
    }
    cout << t_cost_w_f << '\n';
}
signed main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}





