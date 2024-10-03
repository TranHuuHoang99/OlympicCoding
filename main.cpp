class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> ret;
		sort(nums.begin(), nums.end());

		for (int i = 0; i < nums.size() - 2; i++) {
			for (int j = i+1; j < nums.size() - 1; j++) {
				int left = j + 1;
				int right = nums.size() - 1;
				while (left <= right) {
					int mid = left + (right - left) / 2;
					if (nums[mid] == -(nums[i] + nums[j])) {
						ret.push_back({nums[mid], nums[i], nums[j]});
						break;
					} else if (nums[mid] < -(nums[i] + nums[j])) {
						left = mid + 1;
					} else {
						right = mid - 1;
					}
				}

				while (j+1 < nums.size()-1 && nums[j] == nums[j+1]) j++;
			}

			while (i+1 < nums.size() && nums[i] == nums[i+1]) i++;
		}
			
		return ret;		
	}
};
