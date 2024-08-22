#include <bits/stdc++.h>
#define ll long long

using namespace std;

class Solution {
public:
    char repeatedCharacter(string s) {
        int temp = 0;
        for (char c : s) {
            if (temp & (1 << (c-'a'))) return c;
            temp ^= (1 << (c-'a'));
        }

        return '\0';
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
