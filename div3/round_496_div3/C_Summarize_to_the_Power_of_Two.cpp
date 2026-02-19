/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-02-08 22:42:08
**************************************************************************
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5+10;
int n;
int A[N];
map<int,int> save;
void solve(void) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
        save[A[i]] += 1;
    }
    int ret = 0;
    for (int i = 1; i <= n; i++) {
        bool valid = false;
        for (int j = 0; j <= 30; j++) {
            int power_two = (1 << j);
            if (power_two < A[i]) continue;
            int temp = power_two - A[i];
            if (save.find(temp) != save.end()) {
                if (A[i] == temp && save[temp] <= 1) continue;
                valid = true;
                break;
            }
        }
        if (!valid) ret++;
    }
    cout << endl;
    cout << ret << endl;
}

signed main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}





