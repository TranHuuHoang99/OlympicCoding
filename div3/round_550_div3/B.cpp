/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-09-24 22:23:41
**************************************************************************
*/
#include <bits/stdc++.h>
#define int long long
#define pi acos(-1.0)
using namespace std;

const int N = 2e3+10;
int n;
vector<int> even, odd;
void solve(void) {
    cin >> n;
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        int val;
        cin >> val;
        sum += val;
        if (val % 2 == 0) {
            even.push_back(val);
        } else {
            odd.push_back(val);
        }
    }
    sort(even.begin(), even.end());
    sort(odd.begin(), odd.end());
    if (even.size() < odd.size()) swap(even, odd);
    bool isEven = true;
    int val = 0;
    while (true) {
        if (isEven) {
            if (even.empty()) break;
            val += even.back();
            even.pop_back();
            isEven = false;
        } else {
            if (odd.empty()) break;
            val += odd.back();
            odd.pop_back();
            isEven = true;
        }
    }
    cout << sum - val << '\n';
}
signed main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}





