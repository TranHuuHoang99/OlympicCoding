#include <bits/stdc++.h>
#define ll long long

using namespace std;

vector<string> res;
ll L, R;

void solve(int count) {
    int ret = 0;
    cin >> L >> R;
    for (int i = 40; i >= 1; i--) {
        ll left = 2, right = R;
        while (left <= right) {
            ll mid = (right+left)/2;
            
            if (pow(mid, i) < L) {
                left = mid+1;
            } else {
                if (pow(mid, i) <= R) {
                    ret = max(ret, i);
                }
                right = mid-1;
            }
        }
    }

    string temp = "Case #" + to_string(count) + ": " + to_string(ret);
    res.push_back(temp);
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
#ifdef HOANG_DEBUG
    freopen("input.txt", "r", stdin);
#endif // HOANG_DEBUG

    int N;
    cin >> N;
    int count = 1;
    while (N--) {
        solve(count);
        count++;
    }

    for (auto r : res) {
        cout << r << endl;
    }

    return 0;
}
