/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-01-29 17:27:51
**************************************************************************
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;

int a, b, x;
void solve(void) {
    cin >> a >> b >> x;
    if (x % 2 == 0) {
        if (a > b) {
            for (int i = 1; i <= x/2; i++) {
                cout << "01";
            }
            cout << string(b-x/2, '1');
            cout << string(a-x/2, '0');
            cout << endl;
        } else {
            for (int i = 1; i <= x/2; i++) {
                cout << "10";
            }
            cout << string(a-x/2, '0');
            cout << string(b-x/2, '1');
            cout << endl;
        }
    } else {
        if (a > b) {
            for (int i = 1; i <= x/2; i++) {
                cout << "01";
            }
            cout << string(a-x/2, '0');
            cout << string(b-x/2, '1');
            cout << endl;
        } else {
            for (int i = 1; i <= x/2; i++) {
                cout << "10";
            }
            cout << string(b-x/2, '1');
            cout << string(a-x/2, '0');
            cout << endl;
        }
    }
}
    
signed main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}





