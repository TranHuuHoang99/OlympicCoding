#include <bits/stdc++.h>
#include <chrono>
#include <thread>
#define ll long long

using namespace std;

class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n == 1) return true;
        vector<int> temp;
        for (int i = 2; i < 32; i+=2) {
            temp.push_back(1 << i);
        }

        for (auto t : temp) {
            if (n == t) return true;
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
