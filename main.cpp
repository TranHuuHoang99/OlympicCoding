#include <bits/stdc++.h>
#include <chrono>
#include <thread>
#define ll long long

using namespace std;

class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool> ret(nums.size(), false);

        int mask = 0;
        for (int i = 0; i < nums.size(); i++) {
            mask = ((mask << 1) + nums[i]) % 5;
            ret[i] = mask == 0;
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
