#include <bits/stdc++.h>
#define ll long long

using namespace std;

class Solution {
public:
    vector<int> evenOddBit(int n) {
        vector<int> ret(2,0);
        for (int i = 0; i < 32; i++) {
            if (n & (1 << i)) {
                if (i % 2 == 0) {
                    ret[0]++;
                } else {
                    ret[1]++;
                }
            }
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


    char temp = '\0';
    cout << temp << endl;

    return 0;
}
