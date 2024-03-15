#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int n = 0;
vector<ll> pencils;

bool isValid(const int &i, const int &j, const int &k) {
    return pencils[i] + pencils[j] > pencils[k];
}

ll solve(void) {   
    ll ret = 0;
    sort(pencils.begin(), pencils.end());

    for(int i = n-1; i >= 0; i--) {
        int left = 0;
        int right = i-1;
        while(left < right) {
            if(isValid(left, right, i)) {
                ret += (right-left);
                right--;
            } else {
                left++;
            }
        }
    }

    return ret;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    pencils.assign(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> pencils[i];
    }

    cout << solve() << endl;

    return 0;
}
