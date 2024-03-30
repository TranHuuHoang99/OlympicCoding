#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n = 0;
int Q = 0;
vector<ll> K;
vector<ll> arr;
vector<ll> dp;

void bs(ll k) {
    int left = 0;
    int right = n-1;
    ll ret = INT64_MIN;
    ll sum = 0;
    ll count = 0;

    while(left <= right) {
        int mid = left + (right-left)/2;

        int index = left-1;
        ll temp = 0;
        if(index < 0) {
            sum += dp[mid];
            temp = dp[mid];
        } else {
            sum += (dp[mid] - dp[index]);
            temp = (dp[mid]-dp[index]);
        }

        count += (mid-left+1);
        if(sum / count < k) {
            ret = max(ret, count);
            left = mid+1;
        } else {
            count -= (mid-left+1);
            sum -= temp;
            right = mid-1;
        }
    }

    if(ret != INT64_MIN) {
        cout << ret << endl;
    } else {
        cout << 0 << endl;
    }

    return;
}

void solve(void) {
    cin >> n;
    arr.assign(n, 0);
    dp.assign(n, 0);
    ll temp = 0;

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    for(int i = 0; i < n; i++) {
        temp += arr[i];
        dp[i] = temp;
    }
    
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
