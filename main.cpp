#include <bits/stdc++.h>
#define ll long long

using namespace std;

class Solution {
public:
    int maximumStrongPairXor(vector<int>& nums) {
        int ret = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < nums.size(); j++) {
                if (abs(nums[i] - nums[j]) <= min(nums[i], nums[j])) {
                    ret = max(ret, nums[i] ^ nums[j]);
                }
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
