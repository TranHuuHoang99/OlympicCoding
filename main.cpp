#include <bits/stdc++.h>
#define ll long long
#define N 10000000

using namespace std;

int n;
ll bit1[N], bit2[N];
ll ans1[N], ans2[N];

void update(ll* arr, ll index, int val) {
    for (ll i = index; i <= n; i += i&-i) arr[i] += val;
}

ll sum(ll* arr, ll index) {
    ll ret = 0;
    for (ll i = index; i > 0; i -= i&-i) ret += arr[i];
    return ret;
}

bool cmp(pair<pair<ll,ll>, ll> A, pair<pair<ll,ll>, ll> B) {
    if (A.first.first == B.first.first) {
        return A.first.second > B.first.second;
    }

    return A.first.first < B.first.first;
}

void solve(void) {
    cin >> n;
    set<ll> B;
    set<ll> C;
    map<ll,ll> m;
    vector<pair<pair<ll,ll>, ll>> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i].first.first >> A[i].first.second;
        A[i].second = i;
        B.insert(A[i].first.second);
    }

    sort(A.begin(), A.end(), cmp);

    int count = 0;
    for (auto _B : B) {
        m[_B] = ++count;
    }

    for (int i = n-1; i >= 0; i--) {
        ans1[A[i].second] += sum(bit1, m[A[i].first.second]);
        update(bit1, m[A[i].first.second], 1);
    }

    for (int i = 0; i < n; i++) cout << ans1[i] << ' ';
    cout << '\n';

    for (int i = 0; i < n; i++) {
        ans2[A[i].second] += sum(bit2, m[A[i].first.second]);
        update(bit2, 1, 1);
        update(bit2, m[A[i].first.second]+1, -1);
    }

    for (int i = 0; i < n; i++) cout << ans2[i] << ' ';
    cout << '\n';
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
