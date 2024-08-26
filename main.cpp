#include <bits/stdc++.h>
#include <chrono>
#include <thread>
#define ll long long

using namespace std;

class Solution {
public:
    int binaryGap(int n) {
        int ret = INT_MIN;
        int temp = 0;
        bool init = false;
        
        for (int i = 0; i < 32; i++) {
            int mask = 1 << i;
            if (mask & n) {
                if (init) {
                    ret = max(ret, i-temp);
                }

                temp = i;
                init = true;
            }
        }

        return ret == INT_MIN ? 0 : ret;
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
