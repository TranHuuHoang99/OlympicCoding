#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
int n = 0, k = 0;
ll l = 0;
vector<ll> trees;

bool isValid(ll force) {
    ll distance = trees[0] + force*2;
    int count = k-1;
    for(int i = 0; i < n; i++) {
        if(trees[i] > distance) {
            distance = trees[i] + force*2;
            count--;
        }
    }

    if(count >= 0) return true;
    return false;
}

ll solve(void) {
    ll left = 0;
    ll right = l;
    ll ret = INT64_MAX;

    while(left <= right) {
        ll mid = left + (right-left)/2;
        if(isValid(mid)) {
            ret = min(ret, mid);
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return ret;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> l >> k;
    trees.assign(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> trees[i];
    }

    sort(trees.begin(), trees.end());

    cout << solve() << endl;    

    return 0;
}
