/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-07-23 23:47:28
**************************************************************************
*/
#include <bits/stdc++.h>
#define int long long
#define pi acos(-1.0)
using namespace std;

const int N = 2e5+10;
int n;
map<int,int> save;
void solve(void) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int val;
        cin >> val;
        save[val] += 1;
    }
    vector<int> freq;
    for (pair<int,int> s : save) {
        freq.push_back(s.second);
    }
    sort(freq.begin(), freq.end(), greater<int>());
    int ret = 0;
    int len = freq.size();
    for (int i = 1; i <= freq[0]; i++) {
        int sum = i;
        int need = i;
        int idx = 1;
        while (idx < len) {
            if (need % 2 == 0 && freq[idx] >= (need / 2)) {
                need /= 2;
                sum += need;
            } else {
                break;
            }
            idx++;
        }
        ret = max(ret, sum);
    }
    cout << ret << '\n';
}
signed main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}





