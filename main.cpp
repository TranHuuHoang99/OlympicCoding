#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
        typedef long long ll;
        int minEatingSpeed(vector<int>& piles, int h) {
            ll left = 1;
            ll right = *max_element(piles.begin(), piles.end());
            int ret = 0;

            while(left <= right) {
                ll mid = left+(right-left)/2;
                ll count = 0;
                for(auto p : piles) {
                    if(p < mid) {
                        count++;
                    } else if(p % mid == 0) {
                        count += (p/mid);
                    } else {
                        count += (p/mid+1);
                    }
                }

                if(count <= h) { // there is some cases "count" do not equal to h so we update the value nearly to h
                    ret = mid;
                    right = mid -1;
                } else {
                    left = mid + 1;
                }
            }
 
            return ret;
        }
};

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Solution solve;

    vector<pair<int, vector<int>>> data = {
        {8, {3,6,7,11}},
        {5, {30,11,23,4,20}},
        {6, {30,11,23,4,20}}
    };

    for(auto d : data) {
        cout << solve.minEatingSpeed(d.second, d.first) << endl;
    }

    return 0;
}
