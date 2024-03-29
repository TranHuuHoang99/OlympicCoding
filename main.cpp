#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n = 0;
int Q = 0;
vector<ll> K;
vector<ll> arr;

void bs(ll k) {
    int left = 0;
    int right = n-1;
    ll ret = 1e9 * (-2);

    while(left <= right) {
        int mid = left + (right-left)/2;
        if(arr[mid] < k) {
            left = mid+1;
            ret = arr[mid];
        } else {
            right = mid-1;
        }
    }

    if(ret != 1e9 * (-2)) {
        cout << ret << endl;
    } else {
        cout << "NONE" << endl;
    }
    return;
}

void solve(void) {
    cin >> n;
    arr.assign(n, 0);
    for(auto &a : arr) {
        cin >> a;
    }
    sort(arr.begin(), arr.end());

    cin >> Q;
    K.assign(Q, 0);
    for(auto &_k : K) {
        cin >> _k;
    }

    for(auto _k : K) {
        bs(_k);
    }

    return;
}   

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
