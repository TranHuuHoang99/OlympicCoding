/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2025-11-09 22:45:20
**************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve(void) {
    int n;
    cin >> n;
    uint32_t val1 = 0;
    uint32_t val2 = 0;
    for (uint32_t i = 0; i < n-2; i++) {
        val1 ^= i;
        val2 ^= (i+1);
    }
    uint32_t last = (1 << 31) - 1;
    if (val1 != 0) {
        for (int i = 0; i < n-2; i++) cout << i << ' ';
        val1 ^= last;
        cout << last << ' ' << val1 << endl;
    } else {
        for (int i = 1; i <= n-2; i++) cout << i << ' ';
        val2 ^= last;
        cout << last << ' ' << val2 << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) solve();
    return 0;
}





