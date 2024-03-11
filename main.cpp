#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n = 0, t = 0;
vector<ll> A;
vector<ll> S;
vector<ll> arr;

int solve(void) {
    arr.assign(n, 0);
    arr[n-1] = A[n-1] + t * S[n-1];
    for(int i = n-2; i >= 0; i--) {
        arr[i] = A[i] + t * S[i];
        if(arr[i] > arr[i+1]) arr[i] = arr[i+1]; 
    }

    set<ll> ret;
    for(auto a : arr) {
        ret.insert(a);
    }

    return ret.size();
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> t;
    A.assign(n, 0);
    S.assign(n, 0);

    for(int i = 0; i < n; i++) {
        cin >> A[i] >> S[i];
    }

    cout << solve() << endl;

    return 0;
}
