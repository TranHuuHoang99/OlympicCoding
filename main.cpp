#include <bits/stdc++.h>
#include <chrono>
#include <thread>
#define ll long long

using namespace std;

class Solution {
public:
    string toHex(int num) {
        map<int,char> m;

        for (int i = 0; i < 10; i++) m[i] = i + '0';
        for (int i = 10; i < 16; i++) m[i] = i-10 + 'a';

        string ret;
        if (num == 0) return "0";
        long long temp = num;
        if (num < 0) {
            temp = ((long long)INT32_MAX << 1) + 2 + num;
        }

        while (temp) {
            ret += m[temp%16];
            temp /= 16;
        }

        reverse(ret.begin(), ret.end());
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

    Solution s;
    cout << s.toHex(-1) << endl;

    return 0;
}
