#include <bits/stdc++.h>
#include <chrono>
#include <thread>
#define ll long long

using namespace std;

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_set<int> unqNums;
        vector<int> res;
        for(auto num : nums){
            if(unqNums.count(num)){
                res.push_back(num);
            }
            unqNums.insert(num);
        }
        for(int num = 1; num <= nums.size(); num++){
            if(!unqNums.count(num))res.push_back(num);
        }
        return res;
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
