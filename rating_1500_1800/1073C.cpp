/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-04-30 21:45:32
**************************************************************************
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5+10;
int n;
string str;
pair<int,int> des;
void update(pair<int,int>& pos, char c, int val) {
    if (c == 'L')
        pos.first -= val;
    if (c == 'R')
        pos.first += val;
    if (c == 'U')
        pos.second += val;
    if (c == 'D')
        pos.second -= val;
}
bool ok(pair<int,int> u, pair<int,int> v, int len) {
    int dist = abs(u.first - v.first) + abs(u.second - v.second);
    if (dist % 2 != len % 2) return false;
    return dist <= len;
}
bool valid(int len) {
    pair<int,int> pos = {0,0};
    for (int i = len; i < n; i++)
        update(pos, str[i], 1);
    int left = 0;
    int right = len;
    while (true) {
        if (ok(pos, des, len)) return true;
        if (right == n) break;
        update(pos, str[left++], 1);
        update(pos, str[right++], -1);
    }
    return false;
}
void solve(void) {
    cin >> n;
    cin >> str;
    cin >> des.first >> des.second;
    if (abs(des.first) + abs(des.second) > n) {
        cout << -1 << endl;
        return;
    }
    int left = 0;
    int right = n;
    int ret = -1;
    while (left <= right) {
        int mid = (left+right)/2;
        if (valid(mid)) {
           ret = mid;
           right = mid - 1; 
        } else {
            left = mid + 1;
        }
    }
    cout << ret << endl;
}

signed main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}





