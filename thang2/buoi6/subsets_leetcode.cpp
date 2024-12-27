class Solution {
public:
    void back_track(vector<vector<int>>& ret, const vector<int> numbs, vector<int> temp, int next) {
        if (next >= numbs.size()) {
            ret.push_back(temp);
            return;
        }
        back_track(ret, numbs, temp, next+1);
        temp.push_back(numbs[next]);
        back_track(ret, numbs, temp, next+1);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ret;
        vector<int> temp;
        back_track(ret, nums, temp, 0);
        return ret;
    }
};