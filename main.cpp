#include <bits/stdc++.h>
#define ll long long

using namespace std;

vector<ll> A;

ll sum(int i, int j) {
    ll end = 0;
    while (j > 0) {
        end += A[j];
        j -= (j&-j);
    }

    ll begin = 0;
    int index = i-1;
    while (index > 0) {
        begin += A[index];
        index -= (index & -index);
    }

    return end - begin;
}

void add(int i, int x) {
    while (i < A.size()) {
        A[i] += x;
        i += (i & -i);
    }
}

void solve(void) {
    int N, Q;
    cin >> N >> Q;
    A.assign(N+1, 0);
    for (int i = 1; i <= N; i++) cin >> A[i];

    for (int i = 1; i <= N; i++) {
        int p = i + (i & -i);
        if (p < A.size()) {
            A[p] += A[i];
        }
    }

    vector<ll> ret;
    for (int i = 0; i < Q; i++) {
        int t, p, x;
        cin >> t >> p >> x;
        if (t == 1) {
            add(p,x);
        } else {
            ret.push_back(sum(p,x));
        }
    }

    for (auto r : ret) {
        cout << r << endl;
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
