/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2025-11-09 08:37:15
**************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll N = 2e5+10;
int n;
ll A[N];
string str;
bool cmp(ll a, ll b) {
    return a > b;
}
void solve(void) {
    cin >> n;
    cin >> str;
    ll sum = 0ll;
    vector<ll> save;
    for (int i = 0; i < n; i++) {
        ll left_val = 1ll * (i-0);
        ll right_val = 1ll * (n-i-1);
        if (str[i] == 'L') {
            sum += left_val;
            if (right_val - left_val > 0) {
                save.push_back(right_val - left_val);
            }
        } else {
            sum += right_val;
            if (left_val - right_val > 0) {
                save.push_back(left_val - right_val);
            }
        }
    }
    sort(save.begin(), save.end(), cmp);
    int idx = 0;
    for (int i = 1; i <= n; i++) {
        while (idx < save.size() && idx < i) {
            sum += save[idx];
            idx++;
        }
        cout << sum << ' ';
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) solve();
    return 0;
}





