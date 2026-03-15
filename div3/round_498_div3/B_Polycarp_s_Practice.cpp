/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-03-15 14:51:31
**************************************************************************
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e3+10;
int n, k;
pair<int,int> save[N];
bool used[N];
void solve(void) {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> save[i].first;
        save[i].second = i;
    }
    sort(save+1, save+1+n, [&] (pair<int,int> a, pair<int,int> b) -> bool {
        return a.first > b.first;
    });
    int max_val = 0;
    for (int i = 1; i <= k; i++) {
        max_val += save[i].first;
        used[save[i].second] = true;
    }
    vector<int> ret;
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (used[i] == true) {
            cnt++;
            ret.push_back(cnt);
            cnt = 0;
        } else {
            cnt++;
        }
    }
    if (cnt != 0) {
        ret.back() += cnt;
    }
    cout << max_val << endl;
    for (int r : ret) cout << r << ' ';
    cout << endl;
}

signed main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}





