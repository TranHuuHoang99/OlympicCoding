#include <bits/stdc++.h>
#include <chrono>
#include <thread>
#define ll long long

using namespace std;

class Solution {
public:
    bool hasAlternatingBits(int n) {
        bool valid = false;
        for (int i = 31; i >= 0; i--) {
            int mask = 1 << i;
            if (n & mask) valid = true;

            if (valid && i < 31) {
                int n_mask = 1 << (i+1);
                if (((n & n_mask) && (n & mask)) ||
                    !(n & n_mask) && !(n & mask))
                {
                        return false;
                }
            }
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
