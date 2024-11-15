class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
		int len = points.size();
		vector<int> x(len), y(len);
		for (int i = 0; i < len; i++) {
			x[i] = points[i][0];		
			y[i] = points[i][1];		
		}
		int ret = INT32_MIN;
		deque<int> dq;
		for (int i = 0; i < len; i++) {
			while (!dq.empty() && x[i] - x[dq.front()] > k) dq.pop_front();
			if (!dq.empty()) {
				ret = max(ret, y[i] + y[dq.front()] + x[i] - x[dq.front()]);
			}
			while (!dq.empty() && y[i] - x[i] >= y[dq.back()] - x[dq.back()]) dq.pop_back();	
			dq.push_back(i);
		}
		return ret;
    }
};
