/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-07-18 20:56:44
**************************************************************************
*/
#include <bits/stdc++.h>
#define int long long
#define pi acos(-1.0)
using namespace std;

const int N = 2e5+10;
int q;
int pos[N];
void solve(void) {
    cin >> q;
    int left = 0;
    int right = 0;
    for (int i = 1; i <= q; i++) {
        char cmd;
        int id;
        cin >> cmd >> id;
        if (i == 1) {
            pos[id] = left;
            left--;
            right++;
        } else {
            if (cmd == 'L') {
                pos[id] = left;
                left--;
            } else if (cmd == 'R') {
                pos[id] = right;
                right++;
            } else {
                int ret = min(abs(pos[id]-left), abs(pos[id]-right)) - 1;
                cout << ret << '\n';
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





