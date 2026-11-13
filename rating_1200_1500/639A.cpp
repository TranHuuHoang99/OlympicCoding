/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-11-13 15:45:26
**************************************************************************
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 15e4+10;
int n, k, q;
pair<int,int> arr[N];
int cnt = 1;
bool cmp(pair<int,int> a, pair<int,int> b) {
    return a.first > b.first;
}
void solve(void) {
    cin >> n >> k >> q;
    for (int i = 1; i <= n; i++) {
        int val;
        cin >> val;
        arr[i] = {val, i};
    }
    vector<pair<int,int>> store_vec;
    while (q--) {
        int type, id;
        cin >> type >> id;
        if (type == 1) {
            store_vec.push_back(arr[id]);
            sort(store_vec.begin(), store_vec.end(), cmp);
            if (store_vec.size() > k) store_vec.pop_back();
        } else {
            bool is_found = false;
            for (int i = 0; i < store_vec.size(); i++) {
                if (store_vec[i].second == id) {
                    is_found = true;
                    break;
                }
            }
            if (is_found) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
    }
}
signed main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}






