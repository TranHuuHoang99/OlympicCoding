#include <bits/stdc++.h>
#include <chrono>
#include <thread>
#define ll long long

using namespace std;

class Solution {
public:
    int findComplement(int num) {
        bool isValid = false;
        for (int i = 30; i >= 0; i--) {
            int mask = 1 << i;
            if (num & mask) isValid = true;
            if (isValid) num ^= mask;
        }

        return num;
    }
};

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
#ifdef HOANG_DEBUG
    freopen("input.txt", "r", stdin);
#endif // HOANG_DEBUG

    Solution s;
    cout << s.findComplement(5) << endl;

    return 0;
}
