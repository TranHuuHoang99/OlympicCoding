/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-09-23 14:09:26
**************************************************************************
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 150000 + 10;
int n;
string str_left;
string str_right;
unordered_map<char,queue<int>> l_save;
unordered_map<char,queue<int>> r_save;
void solve(void) {
    cin >> n;
    cin >> str_left >> str_right;
    for (int i = 0; i < n; i++) {
        l_save[str_left[i]].push(i);
        r_save[str_right[i]].push(i);
    }
    vector<pair<int,int>> ret;
    for (char c = 'a'; c <= 'z'; c++) {
        int len = min(l_save[c].size(), r_save[c].size());
        for (int i = 0; i < len; i++) {
            int pos_left = l_save[c].front();
            l_save[c].pop();
            int pos_right = r_save[c].front();
            r_save[c].pop();
            ret.push_back({pos_left, pos_right});
        }
    }
    queue<int> lq = l_save['?'];
    for (char c = 'a'; c <= 'z'; c++) {
        queue<int> q = r_save[c];
        while (!q.empty() && !lq.empty()) {
            int lidx=  lq.front();
            lq.pop();
            int ridx = q.front();
            q.pop();
            ret.push_back({lidx, ridx});
        }
    }
    queue<int> rq = r_save['?'];
    for (char c = 'a'; c <= 'z'; c++) {
        queue<int> q = l_save[c];
        while (!q.empty() && !rq.empty()) {
            int lidx = q.front();
            q.pop();
            int ridx = rq.front();
            rq.pop();
            ret.push_back({lidx, ridx});
        }
    }
    while (!lq.empty() && !rq.empty()) {
        int lidx = lq.front();
        lq.pop();
        int ridx = rq.front();
        rq.pop();
        ret.push_back({lidx, ridx});
    }
    cout << ret.size() << '\n';
    for (pair<int,int> r : ret) cout << r.first + 1 << ' ' << r.second + 1 << '\n';
}

signed main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}





