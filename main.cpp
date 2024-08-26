#include <bits/stdc++.h>
#include <chrono>
#include <thread>
#define ll long long

using namespace std;

class Solution {
public:
    string longestNiceSubstring(string s) {
        string ret;

        for (int i = 0; i < s.size(); i++) {
            string str;
            for (int j = i; j < s.size(); j++) {
                str += s[j];
                int left = 0;
                int right = 0;
                for (int k = 0; k < str.size(); k++) {
                    if (str[k] >= 'a') {
                        left |= (1 << (str[k]-'a'));
                    } else {
                        right |= (1 << (str[k]-'A'));
                    }
                }

                if (left == right) {
                    if (ret.size() < str.size()) ret = str;
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

    return 0;
}
