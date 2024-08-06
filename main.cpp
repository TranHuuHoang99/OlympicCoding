#include <bits/stdc++.h>
#define ll long long
#define N 100000+1

using namespace std;

ll diff[N], A[N];
int n, m;

void update(int index, ll val) {
    for (int i = index; i <= n; i += i&-i) {
        diff[i] += val;
    }
}

ll sum(int index) {
    ll ret = 0;
    for (int i = index; i > 0; i -= i&-i) ret += diff[i];
    return ret;
}

int bs(ll target) {
    int left = 1;
    int right = n;
    int ret = -1;
    while (left <= right) {
        int mid = (right+left) /2;
        if (sum(mid) >= target) {
            ret = mid;
            right = mid-1;
        } else {
            left = mid + 1;
        }
    }

    return ret;
}

void solve(void) {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> A[i];
    sort(A, A+n+1);
    for (int i = 1; i <= n; i++) {
        update(i, A[i]-A[i-1]);   
    }

    cin >> m;
    while (m--) {
        ll target;
        cin >> target;
        int i = bs(target);
        if (i != -1) {
            cout << n-i+1 << endl;
            update(i, -1);
        } else {
            cout << 0 << '\n';
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
