#include <bits/stdc++.h>
#define ll long long
#define N 2*100000+1

using namespace std;

ll A[N], B[N];
int n, q;

void update(int index, ll val) {
    for (int i = index; i <= n; i += i&-i) B[i] += val;
}

void updateRange(int u, int v, ll val) {
    update(u, val);
    update(v+1, -val);
}

ll sum(int index) {
    ll ret = 0;
    for (int i = index; i > 0; i -= i&-i) ret += B[i];
    return ret;
}

void solve(void) {
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
        update(i, A[i]-A[i-1]);
    }

    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int u, v;
            ll x;
            cin >> u >> v >> x;
            updateRange(u, v, x);
        } else {
            int u; 
            cin >> u;
            cout << sum(u) << endl;
        }
    }
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
