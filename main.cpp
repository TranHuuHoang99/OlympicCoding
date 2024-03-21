#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
vector<vector<ll>> matrix;
ll sum = 0;
ll max_value = INT64_MIN;
int n = 0;

ll solve(void) {
    for(int i = 0; i < n; i++) {
        ll temp = 0;
        for(int j = 0; j < n; j++) {
            temp += matrix[j][i];
        }
        max_value = max(max_value, temp);
    }

    ll total = max_value * n;
    return total - sum;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    matrix.assign(n, vector<ll>(n, 0));
    for(auto &m : matrix) {
        ll temp = 0;
        for(auto &sub_m : m) {
            cin >> sub_m;
            sum += sub_m;
            temp += sub_m;
            max_value = max(max_value, temp);
        }
    }

    cout << solve() << endl;

    return 0;
}
