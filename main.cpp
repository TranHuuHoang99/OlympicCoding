#include <bits/stdc++.h>

#define ll long long

using namespace std;

ll A, B;

ll f(ll input) {
    input %= B;
    return input * 10;
}

void solve(void) {
    cin >> A >> B;
    string ret;
    string str;
    string init = to_string(A/B);
    ll tortoise = A;
    ll hare = A;

    ll i = 0;
    str += to_string(A/B);
    ll temp = A%B;
    while (i <= 1e7 && temp != 0) {
        temp *= 10;
        str += to_string(temp/B);
        temp %= B;
        i++;
    }

    while (tortoise != 0) {
        tortoise = f(tortoise);
        hare = f(f(hare));

        if (tortoise == hare) {
            break;
        }
    }

    ll p = A;
    ll count = 0;
    while (p != tortoise) {
        p = f(p);
        tortoise = f(tortoise);
        count++;
    }

    ret += (init+'.');
    ret += str.substr(init.size(), count-1);

    ll lambda = 0;
    while (lambda <= 1e7) {
        str += to_string(p/B);
        lambda++;
        p = f(p);
        if (tortoise == p) break;
    }

    ret += '(';
    ret += str.substr(count+init.size()-1, lambda);
    ret += ')';
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
