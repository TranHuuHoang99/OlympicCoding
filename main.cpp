#include <bits/stdc++.h>
#define ll long long

using namespace std;

void update(vector<ll> &arr, int i, ll val, int n) {
    while (i <= n) {
        arr[i] += val;
        i += i&-i;
    }
}

ll sum(vector<ll> arr, int i) {
    ll ret = 0;
    while (i > 0) {
        ret += arr[i];
        i -= i&-i;
    }
    return ret;
}

void solve(void) {
    int n, u, q;
    cin >> n >> u;
    vector<ll> A(n+1, 0);
    for (int i = 0; i < u; i++) {
        int l, r;
        ll val;
        cin >> l >> r >> val;
        l++; r++;
        update(A, l, val, n);
        update(A, r+1, -val, n);
    }

    cin >> q;

    for (int i = 0; i < q; i++) {
        int temp;
        cin >> temp;
        cout << sum(A, temp+1) << endl;
    }
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
