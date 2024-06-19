#include <bits/stdc++.h>

#define ll long long

using namespace std;

ll A, B, C;


ll f(const ll &D) {
    return (A*D + D%B) % C;
}

void solve(void) {
    cin >> A >> B >> C;

    ll tortoise = 1;
    ll hare = 1;

    if (B == 0 || C == 0) {
        cout << -1 << endl;
        return;
    }

    int count = 0;
    while (count < 2 * 1e7) {
        tortoise = f(tortoise);
        hare = f(f(hare));

        if (tortoise == hare) break;
        count++;
    }

    ll u = 0;
    ll P = 1;
    while (P != tortoise && u < 1e7*2) {
        P = f(P);
        tortoise = f(tortoise);
        u++;
    }

    ll lambda = 0;

    while (lambda < 1e7*2) {
        lambda++;
        P = f(P);
        if (P == tortoise) break;
    }

    if (lambda > 1e7*2 || u > 1e7*2) {
        cout << -1 << endl;
        return;
    } else {
        ll temp = lambda + u;
        if (temp > 1e7 * 2) {
            cout << -1 << endl;
        } else {
            cout << temp << endl;
        }
    }
}       

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

// #ifdef HOANG_DEBUG
    freopen("input.txt", "r", stdin);
// #endif // HOANG_DEBUG
    freopen("output.txt", "w", stdout);

    solve();

    return 0;
}
