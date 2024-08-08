#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int LEN = 1e5+1, MOD = 1e6*5;
int A[LEN], inc[LEN], bit[LEN], n, k;

void update(int index, int val) {
    for (int i = index; i <= LEN; i += i&-i) {
        bit[i] = (bit[i] + val) % MOD;
    }
}

int sum(int index) {
    int ret = 0;
    for (int i = index; i > 0; i -= i&-i) ret += bit[i];
    return ret % MOD;
}

void solve(void) {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> A[i]; A[i]++;
        inc[i] = 1;
    }

    for (int temp = 2; temp <= k; temp++) {
        memset(bit, 0, sizeof(bit));
        for (int i = 1; i <= n; i++) {
            update(A[i], inc[i]);
            inc[i] = sum(A[i]-1);
        }
    }

    ll ret = 0;
    for (int i = 1; i <= n; i++) ret += inc[i];
    cout << ret % MOD << endl;
}


int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

#ifdef HOANG_DEBUG
	freopen("input.txt", "r", stdin);
#endif //HOANG_DEBUG

    solve();

    return 0;
}
