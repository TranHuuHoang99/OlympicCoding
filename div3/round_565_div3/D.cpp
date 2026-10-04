/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-10-05 14:31:07
**************************************************************************
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5+10;
int n;
int cnt[2750133];
vector<int> prime_order;
bool is_prime(int target) {
    if (target <= 1) return false;
    if (target <= 3) return true;
    if (target % 2 == 0 || target % 3 == 0) return false;
    for (int i = 5; i * i <= target; i+=6) {
        if (target % i == 0 || target % (i+2) == 0) return false;
    }
    return true;
}
int biggest_divisor(int target) {
    int ret = 1;
    for (int i = 2; i * i <= target; i++) {
        if (target % i == 0) {
            ret = max(ret, i);
            ret = max(ret, target / i);
        }
    }
    return ret;
}
void solve(void) {
    cin >> n;
    int b_len = 2 * n;
    vector<int> b_arr;
    for (int i = 1; i <= b_len; i++) {
        int val;
        cin >> val;
        b_arr.push_back(val);
        cnt[val]++;
    }
    for (int val = 2; val <= 2750131; val++) {
        if (is_prime(val)) {
            prime_order.push_back(val);
        }
    }
    vector<int> ret;
    sort(b_arr.begin(), b_arr.end(), greater<int>());
    for (int b_a : b_arr) {
        if (is_prime(b_a)) {
            int index = lower_bound(prime_order.begin(), prime_order.end(), b_a)
                        - prime_order.begin() + 1;
            if (cnt[index] > 0 && cnt[b_a] > 0) {
                cnt[index]--;
                cnt[b_a]--;
                ret.push_back(index);
            }
        } else {
            int div = biggest_divisor(b_a);
            if (cnt[div] > 0 && cnt[b_a] > 0) {
                cnt[div]--;
                cnt[b_a]--;
                ret.push_back(b_a);
            }
        }
    }
    for (int r : ret) cout << r << ' ';
    cout << '\n';
}
signed main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}






