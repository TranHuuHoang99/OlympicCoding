#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll solve(ll a, ll b) {
    while(a != b) {
        if(a > b) {
            a -= b;
        } else {
            b -= a;
        }
    }

    return a;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll A, B;
    cin >> A >> B;
    ll ret = A / solve(A, B);
    ret *= B;

    cout << ret << endl;

    return 0;
}
