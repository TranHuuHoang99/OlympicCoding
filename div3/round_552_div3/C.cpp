/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-09-28 10:04:02
**************************************************************************
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<int> daily = {1, 2, 3, 1, 3, 2, 1};
void solve(void) {
    int fish, rabbit, chicken;
    cin >> fish >> rabbit >> chicken;
    int min_val = min({fish/3, rabbit/2, chicken/2});
    int ret = min_val * (7);
    int r_fish = fish - min_val * 3;
    int r_rabbit = rabbit - min_val * 2;
    int r_chicken = chicken - min_val * 2;
    int max_val = 0;
    for (int i = 0; i < 7; i++) {
        int cnt = 0;
        int idx = i;
        int r_fish_temp = r_fish;
        int r_rabbit_temp = r_rabbit;
        int r_chicken_temp = r_chicken;
        while (true) {
            if (daily[idx % 7] == 1 && r_fish_temp > 0) {
                r_fish_temp--;
                cnt++;
            } else if (daily[idx % 7] == 2 && r_rabbit_temp > 0) {
                r_rabbit_temp--;
                cnt++;
            } else if (daily[idx % 7] == 3 && r_chicken_temp > 0) {
                r_chicken_temp--;
                cnt++;
            } else {
                break;
            }
            idx++;
        }
        max_val = max(max_val, cnt);
    }
    ret += max_val;
    cout << ret << '\n';
}
signed main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}





