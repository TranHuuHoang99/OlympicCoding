#include <bits/stdc++.h>
#define ll long long

using namespace std;

class Solution {
public:
    int hammingDistance(int x, int y) {
        int ret = 0;
        for (int i = 0; i < 32; i++) {
            if (x%2 != y%2) ret++;
            x >>= 1;
            y >>= 1;
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
