#include <bits/stdc++.h>
#include <chrono>
#include <thread>
#define ll long long

using namespace std;

class Solution {
public:
    bool isPrime(int x) {
        if (x == 1) return false;
        for (int i = 2; i < x; i++) {
            if (x % i == 0) return false;
        }
        return true;
    }

    int countPrimeSetBits(int left, int right) {
        int ret = 0;
        for (int i = left; i <= right; i++) {
            int cnt = 0;
            for (int j = 0; j < 32; j++) {
                int mask = 1 << j;
                if (i & mask) cnt++;
            }
            if (isPrime(cnt)) ret++;
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
