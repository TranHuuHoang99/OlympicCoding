#include <bits/stdc++.h>
#define ll long long

using namespace std;

class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int ret = 0;
        int mask = 0;
        for (int i = 0 ; i < allowed.size(); i++) {
            mask |= (1 << (allowed[i]-'a'));
        }

        for (int i = 0; i < words.size(); i++) {
            bool isValid = true;
            for (int j = 0; j < words[i].size(); j++) {
                if ((mask >> (words[i][j]-'a')) % 2 == 0) {
                    isValid = false;
                    break;
                }
            }
            if (isValid) ret++;
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
