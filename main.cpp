class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
		int ret = 0;
		vector<vector<int>> dp(2, vector<int>(matrix[0].size(), 0));

		for (int i = 0; i < matrix.size(); i++) {
			for (int j = 0; j < matrix[i].size(); j++) {
				if (matrix[i][j] == '0') {
					dp[1][j] = 0;
				} else {
					dp[1][j] = dp[0][j] + 1;
				}
			}

			stack<int> hs;
			stack<int> ps;
		
			for (int j = 0; j < dp[1].size(); j++) {
				if (hs.empty() || hs.top() < dp[1][j]) {
					hs.push(dp[1][j]);
					ps.push(j);
					continue;
				}
				
				int temp_pos = -1;
				while (!hs.empty() && hs.top() > dp[1][j]) {
					int height = hs.top();
					hs.pop();

					int width = j - ps.top();
					temp_pos = ps.top();
					ps.pop();

					ret = max(ret, height * width);
				}

				if (temp_pos != -1) {
					hs.push(dp[1][j]);
					ps.push(temp_pos);
				}
			}

			cout << i << ' ' << hs.size() << ' ' << ps.size() << endl;	

			const int len = dp[1].size();
			while (!hs.empty()) {
				int height = hs.top();
				hs.pop();
				int width = len - ps.top();
				ps.pop();

				ret = max(ret, height * width);
			}

			swap(dp[1], dp[0]);
		}

		return ret;
	}
};

