/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-11-08 00:00:18
**************************************************************************
*/
#include <bits/stdc++.h>
#define int long long
#define pi acos(-1.0)
using namespace std;

const int N = 3e5+5;
int n;
vector<int> arr;
vector<int> diff;
bool check_valid(int target) {
    vector<int> need_change;
    for (int i = 0; i < n-1; i++) {
        if (diff[i] > target) need_change.push_back(i);
    }
    if (need_change.empty()) return true;
    if (need_change.size() > 2) return false;
    if (need_change.size() == 2) {
        int idx1 = need_change[0];
        int idx2 = need_change[1];
        int left = idx1 + 1;
        int right = idx2;
        if (left > right) return false;
        for (int i = left; i < right; i++) {
            if (diff[i] * 2 > target) return false;
        }
        if (abs(arr[idx1] - 2 * arr[idx2]) > target) return false;
        if (right < n-1 && abs(arr[left] * 2 - arr[right+1]) > target) return false;
    }
    // case need_change.size() == 1;
    int idx = need_change[0];
    int left = idx+1;
    for (int right = left; right < n; right++) {
        if (right > left && diff[right-1] * 2 > target) break;
        if (abs(arr[left-1] - arr[right] * 2) > target) continue;
        if (right < n-1 && abs(arr[left] * 2 - arr[right+1]) > target) continue;
        return true;
    }
    int right = idx;
    for (int left = right; left >= 0; left--) {
        if (left < right && diff[left] * 2 > target) break;
        if (abs(arr[left] * 2 - arr[right+1]) > target) continue;
        if (left-1 >= 0 && abs(arr[right] * 2 - arr[left-1]) > target) continue;
        return true;
    }
    return false;
}
void solve(void) {
    cin >> n;
    arr.assign(n, 0);
    diff.assign(n-1, 0);
    for (int i = 0; i < n; i++) cin >> arr[i];
    int max_gap = 0;
    for (int i = 0; i < n-1; i++) {
        diff[i] = abs(arr[i] - arr[i+1]);
        max_gap = max(max_gap, diff[i]);
    }
    int left = 0;
    int right = max_gap;
    int ret = max_gap;
    while (left <= right) {
        int mid = (left+right)>>1;
        if (check_valid(mid)) {
            ret = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    cout << ret << '\n';
}
signed main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    arr.reserve(N);
    diff.reserve(N);
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}





