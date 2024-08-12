#include <bits/stdc++.h>
#define ll long long

using namespace std;

class Solution {
public:
    int minBitFlips(int start, int goal) {
        int ret = 0;
        for (int i = 0; i < 32; i++) {
            if ((start%2) != (goal%2)) {
                ret++;
            }
            start >>= 1;
            goal >>= 1;
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
