/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-07-19 19:39:36
**************************************************************************
*/
#include <bits/stdc++.h>
#define int long long
#define pi acos(-1.0)
using namespace std;

const int N = 2e5+10;
int n;
map<int,vector<pair<int,int>>> save;
// 0 is state what the total distance arrived end at left most
// 1 is state what the total distance arrived end at right most
int F[2];
bool cmp(pair<int,int> a, pair<int,int> b) {
    if (a.first == b.first) return a.second > b.second;
    return a.first < b.first;
}
int get_dist(pair<int,int> a, pair<int,int> b) {
    return abs(a.first - b.first) + abs(a.second - b.second);
}
void solve(void) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x, y;
        cin >> x >> y;
        int level = max(x, y);
        save[level].push_back({x, y});
    }
    for (auto& it : save) {
        sort(it.second.begin(), it.second.end(), cmp);
    }
    pair<int,int> s_left = {0,0};
    pair<int,int> s_right = {0,0};
    F[0] = F[1] = 0ll;
    for (auto it : save) {
        pair<int,int> c_left = it.second.front();
        pair<int,int> c_right = it.second.back();
        int c_level_dist = get_dist(c_left, c_right);
        // next total value with starting point is left most of previous
        int n_F_eLeft = min(F[0] + get_dist(s_left, c_right), F[1] + get_dist(s_right, c_right)) + c_level_dist;
        int n_F_eRight = min(F[0] + get_dist(s_left, c_left), F[1] + get_dist(s_right, c_left)) + c_level_dist;
        F[0] = n_F_eLeft;
        F[1] = n_F_eRight;
        s_left = c_left;
        s_right = c_right;
    }
    cout << min(F[0], F[1]) << '\n';
}
signed main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}





