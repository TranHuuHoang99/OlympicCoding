#include <bits/stdc++.h>
#define ll long long

using namespace std;

class Solution {
public:
    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
        int ret = 0;
        for (int i = 0; i < nums.size(); i++) {
            int cnt = 0;
            int temp = i;
            for (int j = 0; j < 32; j++) {
                if (temp % 2 != 0) cnt++;
                temp >>= 1; 
            }

            if (cnt == k) ret += nums[i];
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
