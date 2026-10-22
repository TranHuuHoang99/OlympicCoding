/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-10-22 22:41:42
**************************************************************************
*/
#include <bits/stdc++.h>
#define int long long
#define pi acos(-1.0)
using namespace std;

int moves[5] = {1, 0, -1, 0, 1};
void solve(void) {
    int b, w;
    cin >> b >> w;
    bool is_swap_color = false;
    if (b > w) {
        swap(b, w);
        is_swap_color = true;
    }
    if (w > 3 * b + 1) {
        cout << "no\n";
        return;
    }
    set<pair<int,int>> black_cells;
    set<pair<int,int>> white_cells;
    int x_begin = 3;
    if (is_swap_color) x_begin = 2;
    for (int i = 1; i <= b; i++) {
        int x = x_begin;
        int y = i*2;
        black_cells.insert({x, y});
        if (white_cells.size() < w) {
            white_cells.insert({x, y-1});
        }
        if (white_cells.size() < w) {
            white_cells.insert({x, y+1});
        }
    }
    auto it = black_cells.begin();
    while (it != black_cells.end() && white_cells.size() < w) {
        auto [x, y] = *it;
        it++;
        if (white_cells.size() < w) {
            white_cells.insert({x-1, y});
        }
        if (white_cells.size() < w) {
            white_cells.insert({x+1, y});
        }
    }
    cout << "yes\n";
    for (pair<int,int> p : black_cells) cout << p.first << ' ' << p.second << '\n';
    for (pair<int,int> p : white_cells) cout << p.first << ' ' << p.second << '\n';
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





