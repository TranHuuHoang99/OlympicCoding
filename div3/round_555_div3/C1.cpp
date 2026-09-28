/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-09-29 13:40:14
**************************************************************************
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(void) {
    int n;
    cin >> n;
    deque<int> dq;
    for (int i = 1; i <= n; i++) {
        int val;
        cin >> val;
        dq.push_back(val);
    }
    string temp = "";
    int cur = 0;
    while (!dq.empty()) {
        if (dq.front() > cur && dq.front() <= dq.back()) {
            temp += 'L';
            cur = dq.front();
            dq.pop_front();
        } else if (dq.back() > cur && dq.back() <= dq.front()) {
            temp += 'R';
            cur = dq.back();
            dq.pop_back();
        } else if (dq.front() > cur) {
            temp += 'L';
            cur = dq.front();
            dq.pop_front();
        } else if (dq.back() > cur) {
            temp += 'R';
            cur = dq.back();
            dq.pop_back();
        } else {
            break;
        }
    }
    cout << temp.size() << '\n';
    cout << temp << '\n';
}

signed main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}





