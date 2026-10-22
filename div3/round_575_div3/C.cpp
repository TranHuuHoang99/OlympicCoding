/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-10-22 11:52:11
**************************************************************************
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(void) {
    int n;
    cin >> n;
    vector<pair<int,int>> x_pos;
    vector<pair<int,int>> y_pos;
    for (int i = 1; i <= n; i++) {
        int x, y, i_up, i_right, i_down, i_left;
        cin >> x >> y >> i_up >> i_right >> i_down >> i_left;
        if (i_up && i_down) {
            x_pos.push_back({-1e5, 1e5});
        } else if (i_up) {
            x_pos.push_back({-1e5, x});
        } else if (i_down) {
            x_pos.push_back({x, 1e5});
        } else {
            x_pos.push_back({x, x});
        }
        if (i_left && i_right) {
            y_pos.push_back({-1e5, 1e5});
        } else if (i_left) {
            y_pos.push_back({-1e5, y});
        } else if (i_right) {
            y_pos.push_back({y, 1e5});
        } else {
            y_pos.push_back({y, y});
        }
    }
    int x_left = -1e5-10;
    int x_right = 1e5+10;
    int y_up = -1e5-10;
    int y_down = 1e5+10;
    for (pair<int,int> p : x_pos) {
        x_left = max(x_left, p.first);
        x_right = min(x_right, p.second);
    }
    for (pair<int,int> p : y_pos) {
        y_up = max(y_up, p.first);
        y_down = min(y_down, p.second);
    }
    if (x_left > x_right || y_up > y_down) {
        cout << 0 << '\n';
        return;
    }
    cout << 1 << ' ' << x_left << ' ' << y_up << '\n';
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






