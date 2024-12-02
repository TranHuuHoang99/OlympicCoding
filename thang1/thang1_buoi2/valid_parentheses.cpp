class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (c == '}' || c == ')' || c == ']') {
                if (st.empty()) return false;
                if (c == '}' && st.top() == '{') {
                    st.pop(); 
                    continue;
                }
                if (c == ')' && st.top() == '(') {
                    st.pop();
                    continue;
                }
                if (c == ']' && st.top() == '[') {
                    st.pop();
                    continue;
                }
                return false;
            } else {
                st.push(c);
            }
        }

        return st.size() == 0;
    }
};
