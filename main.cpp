#include <bits/stdc++.h>
#include <chrono>
#include <thread>
#define ll long long

using namespace std;

class Solution {
public:
    int similarPairs(vector<string>& words) {
        int ret = 0;
        vector<int> temp(words.size(), 0);

        for (int i = 0; i < words.size(); i++) {
            for (int j = 0; j < words[i].size(); j++) {
                temp[i] |= (1 << (words[i][j] - 'a'));
            }
        }

        for (int i = 0; i < temp.size(); i++) {
            for (int j = i+1; j < temp.size(); j++) {
                if (temp[i] == temp[j]) ret++;
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

    vector<string> temp = {"aba","aabb","abcd","bac","aabc"};
    Solution s;
    s.similarPairs(temp);

    return 0;
}
