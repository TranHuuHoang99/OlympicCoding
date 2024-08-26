#include <bits/stdc++.h>
#include <chrono>
#include <thread>
#define ll long long

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        string ret;
        int i = a.size()-1;
        int j = b.size()-1;
        int add = 0;

        while (i >= 0 || j >= 0 || add) {
            if (i >= 0) {
                add += (a[i--]-'0');
            }

            if (j >= 0) {
                add += (b[j--]-'0');
            }

            ret += (add % 2 + '0');
            add /= 2;
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

    return 0;
}
