#include <bits/stdc++.h>
#include <chrono>
#include <thread>
#define ll long long

using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int ret = 0;
        int sum = 0;
        vector<bool> v(51, false);
        for (int i = 1; i <= k; i++) sum += i;
        int temp = 0;
        for (int i = nums.size()-1; i >= 0; i--) {
            if (nums[i] <= k && !v[nums[i]]) {
                temp += nums[i];
                v[nums[i]] = true;
            }
            ret++;
            if (temp == sum) break;
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
