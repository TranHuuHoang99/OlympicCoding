#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n = 0,k=0;
vector<int> arr;

void solve(void) {
    cin >> n >> k;
    arr.assign(n, 0);

    for(auto &a : arr) {
        cin >> a;
    }

    sort(arr.begin()+1, arr.end(), greater<int>());
    int ret = arr[0];
    for(int i = 1; i < n; i++) {
        if(i <= k) {
            ret += arr[i];
        } else {
            ret -= arr[i];
        }
    }

    cout << ret << endl;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
