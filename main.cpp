#include <bits/stdc++.h>

#define ll long long
#define N 10000000

using namespace std;

int A[N], bit[N];
int n;

void update(int index) {
    for (int i = index; i <= N; i += i&-i) bit[i]++;
}

int sum(int index) {
    int ret = 0;
    for (int i = index; i > 0; i -= i&-i) ret += bit[i];
    return ret;
}

void solve(void) {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> A[i];

    int ret = 0;
    for (int i = n; i >= 1; i--) {
        ret += sum(A[i]);
        update(A[i]+1);
    }

    cout << ret << endl;
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
