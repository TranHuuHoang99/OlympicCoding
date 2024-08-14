#include <bits/stdc++.h>
#define ll long long

using namespace std;

class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        vector<int> ret;
        map<int,vector<int>> m;

        for (auto a : arr) {
            int temp = a;
            int cnt = 0;
            for (int i = 0; i < 32; i++) {
                if (temp % 2 != 0) cnt++;
                temp >>= 1;
            }
            m[cnt].push_back(a);
        }

        for (auto _m : m) {
            sort(_m.second.begin(), _m.second.end());
            for (auto __m : _m.second) {
                ret.push_back(__m);
            }
        }

        return ret;
    }
};

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
#ifdef HOANG_DEBUG
    freopen("input.txt", "r", stdin);
#endif // HOANG_DEBUG

    return 0;
}
