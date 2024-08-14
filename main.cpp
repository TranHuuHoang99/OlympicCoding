#include <bits/stdc++.h>
#define ll long long

using namespace std;

class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        int ret = 0;
        map<int,int> cnt;
        set<int> temp;
        for (auto n : nums) {
            cnt[n]++;
            if (cnt[n] == 2) temp.insert(n);
        }

        for (auto t : temp) ret ^= t;
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
