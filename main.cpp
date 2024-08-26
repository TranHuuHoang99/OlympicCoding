#include <bits/stdc++.h>
#include <chrono>
#include <thread>
#define ll long long

using namespace std;

class Solution {
public:
    char findTheDifference(string s, string t) {
        char ret = 0;
        int left = 0;
        int right = 0;
        for (char c : s) left ^= (1 << (c-'a'));
        for (char c : t) right ^= (1 << (c-'a'));
        
        int ret_mask = left ^ right;
        for (int i = 0; i <= 26; i++) {
            int mask = 1 << i;
            if (mask & ret_mask) {
                ret = 'a'+i;
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
