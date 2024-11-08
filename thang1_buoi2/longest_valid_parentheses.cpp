class Solution {
public:
    int longestValidParentheses(string s) {
		int ret = 0;
		stack<int> st;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '(') {
				st.push(i);
			} else {
				if (st.empty() || s[st.top()] == ')') {
					st.push(i);
				} else {
					st.pop();
				}
			}
		}

		if (st.empty()) return s.size();
		int len = s.size();
		while (!st.empty()) {
			int temp = st.top();
			st.pop();
			ret = max(ret, len - temp - 1);
			len = temp;
		}

		ret = max(ret, len);

		return ret;
    }
};

