#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n = 0;
ll a = 0, b = 0, c = 0;
vector<pair<ll,ll>> arr;

bool cmp(pair<ll,ll> a, pair<ll,ll> b) {
    return a.first < b.first;
}

void solve(void) {
    cin >> n >> c;
    arr.assign(n, {0,0});
    for(int i = 0; i < n; i++) {
        cin >> arr[i].first >> arr[i].second;
    }

    sort(arr.begin(), arr.end(), cmp);

    int count = 0;
    for(auto a : arr) {
        if(a.first <= c) {
            c += a.second;
            count++;
        }
    }

    cout << count << endl;
}   

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
