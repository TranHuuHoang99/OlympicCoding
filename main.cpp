#include <bits/stdc++.h>
#include <chrono>
#include <thread>
#define ll long long

using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        vector<bool> v(nums.size()+1, false);
        for (auto n : nums) {
            v[n] = true;
        }

        int ret = 0;
        for (int i = 0; i < v.size(); i++) {
            if (!v[i]) ret = i;
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
