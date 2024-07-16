#include <bits/stdc++.h>
#define ll long long

using namespace std;

void dfs(int index, vector<ll> A, vector<int> S, int &ret, const ll &m) {
    if (index >= A.size()) {
        stack<pair<ll, int>> st;
        st.push({A[0], 0});

        for (int i = 1; i < A.size(); i++) {
            if (S[i] == 2) {
                pair<ll,int> temp = st.top();
                st.pop();
                temp.first = (temp.first * A[i]) % m;
                st.push(temp);
            } else {
                st.push({A[i], S[i]});
            }
        }

        ll ret_temp = 0;
        while (!st.empty()) {
            pair<ll, int> temp = st.top();
            st.pop();
            if (temp.second == 0) {
                ret_temp = (ret_temp + temp.first) % m;
            } else {
                ret_temp = (ret_temp - temp.first) % m;
            }
        }

        if (ret_temp == 0) ret++;
        return;
    }

    for (int i = 0; i < 3; i++) {
        S[index] = i;
        dfs(index+1, A, S, ret, m);
    }
}

void solve(void) {
    int n;
    ll m;
    cin >> n >> m;
    vector<ll> A(n);
    vector<int> S(n, 0);
    for (int i = 0; i < n; i++) cin >> A[i];

    int ret = 0;
    dfs(1, A, S, ret, m);

    cout << ret << endl;
}
  
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
#ifdef HOANG_DEBUG
    freopen("input.txt", "r", stdin);
#endif // HOANG_DEBUG

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
