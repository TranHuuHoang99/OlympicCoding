#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll m = 0, n = 0, k = 0;

ll count(const ll x) {
    ll ret = 0;
    for(int i = 1; i <= m; i++) {
        if(i*i > x) break;
        ret += min(n, (ll)sqrt(x-i*i));
    }

    return ret;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> m >> n >> k;

    ll left = 2;
    ll right = m*m + n*n;

    if(m > n) swap(m,n);

    while(left <= right) {
        ll mid = (right+left)/2;
        
        if(count(mid) < k) {
            left = mid+1;
        } else {
            right = mid-1;
        }
    }

    cout << left << endl;

    return 0;
}
