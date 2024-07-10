#include <bits/stdc++.h>
#define ll long long

using namespace std;

vector<ll> prime;

bool isPrime(const ll &a) {
    if (a <= 1) return false;
    for (ll i = 2; i <= sqrt(a); i++) {
        if (a % i == 0) return false;
    }

    return true;
}

void init(void) {
    for (ll i = 2; i <= 1e5+1000; i++) {
        if (isPrime(i)) {
            prime.push_back(i);
        }
    }
}

void solve(void) {
    init();

    int n,m;
    cin >> n >> m;
    vector<vector<ll>> matrix(n, vector<ll>(m));
    ll ret = INT64_MAX;

    for (int i = 0; i < n; i++) {
        ll temp = 0;
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
            auto it = lower_bound(prime.begin(), prime.end(), matrix[i][j]);
            temp += (*it - matrix[i][j]);
        }

        ret = min(ret, temp);
    }

    for (int i = 0; i < m; i++) {
        ll temp = 0;
        for (int j = 0; j < n; j++) {
            auto it = lower_bound(prime.begin(), prime.end(), matrix[j][i]);
            temp += (*it - matrix[j][i]);
        }
        ret = min(ret, temp);
    }

    cout << ret << endl;
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
