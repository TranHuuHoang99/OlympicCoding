/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-01-27 13:15:09
**************************************************************************
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve(void) {
    int n, k;
    cin >> n >> k;
    deque<int> save;
    for (int i = 1; i <= n; i++) {
        int val;
        cin >> val;
        save.push_back(val);
    }
    int ret = 0;
    while (!save.empty()) {
        bool isLeft = false;
        bool isRight = false;
        if (!save.empty()) {
            if (save.front() <= k) {
                save.pop_front();
                isLeft = true;
                ret++;
            }
        }
        if (!save.empty()) {
            if (save.back() <= k) {
                save.pop_back();
                isRight = true;
                ret++;
            }
        }
        if (!isLeft && !isRight) break;
    }
    cout << ret << endl;
}

signed main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}





