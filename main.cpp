#include <bits/stdc++.h>
#include <chrono>
#include <thread>
#define ll long long

using namespace std;

class Solution {
public:
    int bitwiseComplement(int n) {
        if (n == 0) return 1;
        bool isValid = false;
        for (int i = 63; i >= 0; i--) {
            long int mask = (static_cast<long int>(1) << i);
            if (mask & n) isValid = true;
            if (isValid) {
                n ^= mask;
            }
        }

        return n;
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
