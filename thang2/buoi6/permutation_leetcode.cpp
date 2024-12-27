class Solution {
public:
    void back_track(vector<vector<int>>& ret, const vector<int> nums, vector<int> temp, vector<bool> v) {
        if (temp.size() == nums.size()) {
            ret.push_back(temp);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (!v[i]) {
                temp.push_back(nums[i]);
                v[i] = true;
                back_track(ret, nums, temp, v);
                v[i] = false;
                temp.pop_back();
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ret;
        vector<int> temp;
        vector<bool> v(nums.size(), false);
        back_track(ret, nums, temp, v);
        return ret;
    }
};