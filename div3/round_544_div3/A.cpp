/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-09-21 11:41:57
**************************************************************************
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(void) {
    string a, b;
    cin >> a >> b;
    int h_a = stoi(a.substr(0, 2));
    int h_b = stoi(b.substr(0, 2));
    int m_a = stoi(a.substr(3, 2));
    int m_b = stoi(b.substr(3, 2));
    int diff = (h_b - h_a) * 60 + (m_b - m_a);
    diff /= 2;
    int hour = h_a + diff / 60;
    int minute = m_a + diff % 60;
    if (minute >= 60) {
        hour += minute / 60;
        minute %= 60;
    }
    string ret_h = to_string(hour);
    string ret_m = to_string(minute);
    if (ret_h.size() == 1) ret_h = "0" + ret_h;
    if (ret_m.size() == 1) ret_m = "0" + ret_m;
    cout << ret_h << ":" << ret_m << '\n';
}

signed main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}





