#include <bits/stdc++.h>
#define ll long long

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size()-1; i++) {
            for (int j = i+1; j < nums.size(); j++) {
                if (nums[i] + nums[j] == target) {
                    return {i,j};
                }
            }
        }

        return {-1,-1};
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
