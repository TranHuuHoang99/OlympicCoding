#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll A[100000+1];
ll B[100000+1];
int n, q;

void updatePoint(ll* arr, int index, ll val) {
    for (int i = index; i <= n; i += i&-i) arr[i] += val;
}

void updateRange(int u, int v, ll x) {    
    updatePoint(A, u, (n-u+1)*x);
    updatePoint(A, v+1, -(n-v)*x);
    updatePoint(B, u, x);
    updatePoint(B, v+1, -x);
}

ll getSum(ll* arr, int index) {
    ll ret = 0;
    for (int i = index; i > 0; i -= i&-i) ret += arr[i];
    return ret;
}

ll sum(int i) {
    return getSum(A, i) - getSum(B, i) * (n-i);
}

ll sumRange(int u , int v) {
    return sum(v) - sum(u-1);
}

void solve(void) {
    cin >> n >> q;
    memset(B, 0, n+1);
    for (int i = 1; i <= n; i++) cin >> A[i];
    for (int i = 1; i <= n; i++) {
        int p = i + (i&-i);
        if (p <= n) A[p] += A[i];
    }

    for (int i = 0; i < q; i++) {
        int t;
        cin >> t;
        if (t == 1) {
            int u, v;
            ll x;
            cin >> u >> v >> x;
            updateRange(u, v, x);
        } else {
            int u, v;
            cin >> u >> v;
            cout << sumRange(u, v) << endl;
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
