#include <bits/stdc++.h>
#define ll long long

using namespace std;

class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        vector<int> ret;
        vector<int> arr(101, 0);
        vector<bool> isVisited(101, false);

        for (auto n : nums1) {
            if (!isVisited[n]) {
                isVisited[n] = true;
                arr[n]++;
            }
        }

        isVisited.assign(101, false);
        for (auto n : nums2) {
            if (!isVisited[n]) {
                isVisited[n] = true;
                arr[n]++;
            }
        }
        isVisited.assign(101, false);
        for (auto n : nums3) {
            if (!isVisited[n]) {
                isVisited[n] = true;
                arr[n]++;
            }
        }

        for (int i = 1; i <= 100; i++) {
            if (arr[i] >= 2) ret.push_back(i);
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

    vector<int> temp1 = {1,1,3,2};
    vector<int> temp2 = {2,3};
    vector<int> temp3 = {3};
    Solution s;
    for (auto t : s.twoOutOfThree(temp1, temp2, temp3)) {
        cout << t << ' ';
    }
    cout << '\n';

    return 0;
}
