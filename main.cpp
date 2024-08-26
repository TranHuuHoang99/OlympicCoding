#include <bits/stdc++.h>
#include <chrono>
#include <thread>
#define ll long long

using namespace std;

class Solution {
public:
    int minChanges(int n, int k) {
        int ret = 0;
        for (int i = 0 ; i < 32; i++) {
            int mask = 1 << i;
            if (!(mask & n) && (mask & k)) return -1;
            if ((mask & n) && !(mask & k)) ret++;
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
