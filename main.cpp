#include <bits/stdc++.h>

using namespace std;

#define ll long long

int test_case = 0;
int N = 0;
vector<ll> D;
string S;
vector<ll> R;
vector<ll> next_ele;
ll max_value = 0;
vector<ll> debug;

bool health(ll mid) {
    ll temp = mid;
    for(int i = 0; i < N; i++) {
        mid -= D[i];

        if(mid <= 0) return false;
        if(S[i] == '+') {
            mid += R[i];
        } else {
            if((ll)log2(mid) + (ll)log2(R[i]) >= 62) return true;
            mid *= R[i];
        }

    }

    return mid > 0;
}

void solve(ll left, ll right) {
    ll ret = 0;

    while(left <= right) {
        ll mid = (right+left) / 2;
        if(health(mid)) {
            ret = mid;
            right = mid-1;
        } else {
            left = mid+1;
        }
        
    }

    cout << ret << endl;
    // debug.push_back(ret);
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> test_case;
    ll left = 1;
    
    while(test_case-- >= 1) {
        max_value = 0;
        cin >> N;
        D.assign(N, 0);
        R.assign(N, 0);
        for(int i = 0; i < N; i++) {
            cin >> D[i];
            max_value += D[i];
            next_ele.push_back(max_value);
        }

        cin >> S;

        for(int i = 0; i < N; i++) {
            cin >> R[i];
        }

        solve(left, max_value+1);
    }

    // for(auto db : debug) {
    //     cout << db << " ";
    // }
    // cout << "\n";


    return 0;
}