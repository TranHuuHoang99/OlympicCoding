/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-07-29 23:45:49
**************************************************************************
*/
#include <bits/stdc++.h>
#define int long long
#define pi acos(-1.0)
using namespace std;

int n;
int len;
vector<string> A;
string ret = "";
bool is_valid(const string& prefix, const string& suffix) {
    string str = prefix + suffix.substr(n-2);
    multiset<string> all, pre, suf;
    for (int i = 0; i < n-1; i++) {
        pre.insert(str.substr(0, n - i - 1));
        all.insert(str.substr(0, n - i - 1));
        suf.insert(str.substr(i + 1));
        all.insert(str.substr(i + 1));
    }
    ret.clear();
    if (all == multiset<string>(A.begin(), A.end())) {
        for (int i = 0; i < len; i++) {
            auto it_pre = pre.find(A[i]);
            auto it_suf = suf.find(A[i]);
            if (it_pre != pre.end()) {
                ret += 'P';
                pre.erase(it_pre);
            } else if (it_suf != suf.end()) {
                ret += 'S';
                suf.erase(it_suf);
            } else {
                return false;
            }
        }
        return true;
    }
    return false;
}
void solve(void) {
    cin >> n;
    len = 2 * (n-1);
    A.resize(len);
    vector<string> sample;
    for (int i = 0; i < len; i++) {
        cin >> A[i];
        if (A[i].size() == n-1) sample.push_back(A[i]);
    }
    if (is_valid(sample[0], sample[1])) {
    } else {
        is_valid(sample[1], sample[0]);
    }
    cout << ret << '\n';
}
signed main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}





