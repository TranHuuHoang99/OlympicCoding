/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-07-23 23:18:26
**************************************************************************
*/
#include <bits/stdc++.h>
#define int long long
#define pi acos(-1.0)
using namespace std;

const int N = 2e5+10;
int n, k;
int cnt[N];
set<int> A;
vector<pair<int,int>> save;
vector<int> check_valid(int target) {
    vector<int> ret;
    int numb = k;
    for (pair<int,int> s : save) {
        int div = s.first / target;
        int min_t = min(div, numb);
        for (int i = 1; i <= min_t; i++) {
            ret.push_back(s.second);
        }
        numb -= min_t;
        if (numb == 0) break;
    }
    return ret;
}
void solve(void) {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        int val;
        cin >> val;
        A.insert(val);
        cnt[val] += 1;
    }
    for (int temp : A) {
        save.push_back({cnt[temp], temp});
    }
    sort(save.begin(), save.end(), [&] (pair<int,int> a, pair<int,int> b) -> bool {
        return a.first < b.first;
    });
    int left = 1;
    int right = n;
    vector<int> ret;
    while (left <= right) {
        int mid = (left+right)>>1;
        vector<int> a_get = check_valid(mid);
        if (a_get.size() == k) {
            ret = a_get;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    for (int r : ret) cout << r << ' ';
    cout << '\n';
}
signed main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}





