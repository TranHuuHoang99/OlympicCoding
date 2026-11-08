/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-11-08 19:49:56
**************************************************************************
*/
#include <bits/stdc++.h>
#define int long long
#define pi acos(-1.0)
using namespace std;

const int N = 1e2+10;
int n, m;
pair<int,int> arr[N];
void solve(void) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int val;
        cin >> val;
        arr[i] = {val, i};
    }
    sort(arr+1, arr+1+n, [](pair<int,int> a, pair<int,int> b) -> bool {
        if (a.first == b.first) return a.second < b.second;
        return a.first > b.first;
    });
    cin >> m;
    while (m--) {
        int k, pos;
        cin >> k >> pos;
        vector<pair<int,int>> best_chain;
        for (int i = 1; i <= k; i++) best_chain.push_back(arr[i]);
        sort(best_chain.begin(), best_chain.end(), [](pair<int,int> a, pair<int,int> b) -> bool {
            return a.second < b.second;
        });
        cout << best_chain[pos-1].first << '\n';
    }
}
signed main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}





