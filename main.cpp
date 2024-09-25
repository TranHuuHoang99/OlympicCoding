class Solution {
public:
    int calculate(string s) {
 		int ret = 0;
		
		stack<int> st;
		int numb = 0;
		int n_sign = 1;
		for (char c : s) {
			if (isdigit(c)) {
				numb = numb * 10 + static_cast<int>(c-'0');
			} else if (c == '+' || c == '-') {
				ret += numb * n_sign;
				n_sign = c == '+' ? 1 : -1;
				numb = 0;
			} else if (c == '(') {
				st.push(ret);
				st.push(n_sign);
				ret = 0;
				n_sign = 1;
			} else if (c == ')') {
				ret += numb * n_sign;
				ret *= st.top();
				st.pop();
				ret += st.top();
				st.pop();
				numb = 0;
			}
		}		

		return ret + numb * n_sign;
    }
};

