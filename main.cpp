#include <bits/stdc++.h>
#include <chrono>
#include <thread>
#define ll long long

using namespace std;

class Solution {
public:
    bool hasTrailingZeros(vector<int>& nums) {
        vector<bool> isVisited(101, false);

        int count = 0;
        for (auto n : nums) {
            if (n % 2 == 0) count++;
            if (count >= 2) return true;
        }
        return false;
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
