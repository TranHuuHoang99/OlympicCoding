/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-09-30 11:03:57
**************************************************************************
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;

struct Node {
    pair<int,int> st;
    pair<int,int> nd;
    pair<int,int> rd;
};
const int N = 2e5+10;
int n;
int A[N];
int cnt[N];
int prefix[N];
void solve(void) {
    cin >> n;
    int min_val = INT32_MAX;
    int max_val = 0;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
        min_val = min(min_val, A[i]);
        max_val = max(max_val, A[i]);
        cnt[A[i]] += 1;
    }
    for (int i = min_val; i <= max_val; i++) {
        prefix[i] = prefix[i-1] + cnt[i];
    }
    int ret_val = 0;
    pair<int,int> ret = {0,0};
    int left = min_val;
    int right = min_val;
    while (right <= max_val) {
        if (cnt[right] == 0) {
            right++;
            left = right;
            continue;
        }
        while (right+1 <= max_val && cnt[right+1] >= 2) {
            right++;
        }
        int actual_right = right;
        if (actual_right+1 <= max_val && cnt[actual_right+1] == 1) {
            actual_right += 1;
        }
        int sum = prefix[actual_right] - prefix[left-1];
        if (sum > ret_val) {
            ret_val = sum;
            ret = {left, actual_right};
        }
        right++;
        left = right;
    }
    if (ret_val == 0) {
        cout << 1 << '\n';
        cout << min_val << '\n';
        return;
    }
    vector<int> arr;
    for (int i = ret.first; i <= ret.second; i++) {
        arr.push_back(i);
        cnt[i]--;
    }
    for (int i = ret.second; i >= ret.first; i--) {
        while (cnt[i] > 0) {
            arr.push_back(i);
            cnt[i]--;
        }
    }
    cout << arr.size() << '\n';
    for (int a : arr) cout << a << ' ';
    cout << '\n';
}

signed main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}





