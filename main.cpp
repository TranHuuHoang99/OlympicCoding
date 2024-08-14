#include <bits/stdc++.h>
#define ll long long

using namespace std;

class Solution {
public:
    int findKOr(vector<int>& nums, int k) {
        int ret = 0;
        vector<int> bit(32, 0);

        for (auto n : nums) {
            int temp = n;
            for (int i = 0; i < 32; i++) {
                if (temp % 2 != 0) bit[i]++;
                temp >>= 1;
            }
        }
        
        for (int i = 0; i < 32; i++) {
            if (bit[i] >= k) {
                ret |= (1 << i);
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
