#include <bits/stdc++.h>
#define ll long long

using namespace std;

class Solution {
public:
    bool divideArray(vector<int>& nums) {
        vector<int> ret(501, 0);
        for (int i = 0; i < nums.size(); i++) {
            ret[nums[i]]++;
        }        
        for (auto r : ret) {
            if (r > 0 && r%2 != 0) return false;
        }
        return true;
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
