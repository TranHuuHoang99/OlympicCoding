#include <bits/stdc++.h>
#define ll long long

using namespace std;

vector<ll> res;

void solve(void) {
    ll N;
    cin >> N;
    const ll init = sqrt(N);
    ll ret = init-1;
    ret += ((N-init)/init);
    if (N%init) ret++;
    res.push_back(ret);
}   

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
#ifdef HOANG_DEBUG
    freopen("input.txt", "r", stdin);
#endif // HOANG_DEBUG

    int T;
    cin >> T;
    while (T--) {
        solve();
    }

    for (auto r : res) {
        cout << r << endl;
    }

    return 0;
}
