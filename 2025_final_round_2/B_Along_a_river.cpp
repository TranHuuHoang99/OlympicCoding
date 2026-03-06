/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-02-27 22:30:34
**************************************************************************
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5+10;
int n, k;
int S[N], E[N];
vector<pair<int,bool>> save[N];
bool isOpen[N];
void solve(void) {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> S[i];
    for (int i = 1; i <= n; i++) cin >> E[i];
    for (int i = 1; i <= n; i++) {
        save[S[i]].push_back({i, true});
        if (E[i]+1 <= k) save[E[i]+1].push_back({i, false});
    }
    int cnt = 0;
    for (int i = 1; i <= k; i++) {
        for (auto [idx, state] : save[i]) {
            isOpen[idx] = state;
            if (state == true) { // open idx store
                bool isLeft = isOpen[idx-1];
                bool isRight = isOpen[idx+1];
                if (!isLeft && !isRight) cnt++; // create new group
                if (isLeft && isRight) cnt--; // connect two existed groups
            } else {
                bool isLeft = isOpen[idx-1];
                bool isRight = isOpen[idx+1];
                if (!isLeft && !isRight) cnt--;
                if (isLeft && isRight) cnt++;
            }
        }
        cout << cnt << ' ';
    }
    cout << '\n';
}

signed main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}





