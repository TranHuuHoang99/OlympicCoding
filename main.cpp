#include <bits/stdc++.h>
#include <memory>
#define int long long

using namespace std;

int n = 0, t = 0;

int solve(vector<int> books) {
    int ret = INT_MIN;

    int j = -1, sum = 0, ans = 0;

    for(int i = 0; i < n; i++) {
        if(sum+books[i] <= t) {
            sum += books[i];
        } else {
            sum += books[i];
            while(sum > t) {
                j++;
                sum -= books[j];
            }
        }
        ret = max(ret, i-j);
    }
     
    return ret;
}

int32_t main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> t;

    vector<int> books(n, 0);

    for(int i = 0; i < n; i++) {
        cin >> books[i];
    }

    cout << solve(books) << endl;

    return 0;
}

