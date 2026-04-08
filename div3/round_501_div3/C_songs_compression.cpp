/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-03-30 21:34:08
**************************************************************************
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, m;
vector<int> save;
void solve(void) {
    cin >> n >> m;
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        int a, b;
        cin >> a >> b;
        int diff = a - b;
        sum += a;
        save.push_back(diff);
    }
    sort(save.begin(), save.end(), greater<int>());
    int i = 0;
    while (sum > m && i < n) {
        sum -= save[i];
        i++;
    }
    if (sum <= m) {
        cout << i << endl;
    } else {
        cout << -1 << endl;
    }
}

signed main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}




 