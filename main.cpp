#include <bits/stdc++.h>
#define ll long long

using namespace std;

class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int ret = 0;

        for (int mask = 1; mask < (1 << nums.size()); mask++) {
            int temp = 0;
            for (int i = 0; i < nums.size(); i++) {
                if (mask & (1 << i)) {
                    temp ^= nums[i];
                }
            }
            ret += temp;
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

    Solution s;
    vector<int> temp = {5,1,6};
    cout << s.subsetXORSum(temp) << endl;

    return 0;
}
