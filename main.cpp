#include <bits/stdc++.h>
#define ll long long

using namespace std;

int n, k;

ll trapWater(vector<ll> A) {
    ll ret = 0;
    stack<int> s;
    for (int i = 0; i < A.size(); i++) {
        while (!s.empty() && A[s.top()] < A[i]) {
            int temp = s.top();
            s.pop();
            if (s.empty()) break;
            ll width = i - s.top() - 1;
            ll height = min(A[i] - A[temp], A[s.top()] - A[temp]);
            ret += (width * height);
        }
        s.push(i);
    }

    return ret;
}

void dfs(int i, int remain, ll &ret, vector<ll> A) {
    if (i >= A.size() || remain < 1) {
        ret = max(ret, trapWater(A));
        return;
    }

    dfs(i+1, remain, ret, A);
    A[i] += 1;
    dfs(i, remain - 1, ret, A);
}

void solve(void) {
    int n, k;
    cin >> n >> k;
    vector<ll> A(n);
    for (int i = 0; i < n; i++) cin >> A[i];
    ll ret = INT64_MIN;
    dfs(0, k, ret, A);

    cout << ret << endl;
}
  
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
#ifdef HOANG_DEBUG
    freopen("input.txt", "r", stdin);
#endif // HOANG_DEBUG

    solve();

    return 0;
}
