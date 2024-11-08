#include <bits/stdc++.h>
#define ll long long

using namespace std;

map<char,int> m;

void solve(void) {
	string str;
	cin >> str;
	m.insert({'C', 12});
	m.insert({'H', 1});
	m.insert({'O', 16});
	m.insert({'(', 0});
	int ret = 0;
	stack<int> st;
	for (int i = 0; i < str.size(); i++) {
		char c = str[i];
		if (c == ')') {
			int temp = 0;
			while (!st.empty() && st.top() != 0) {
				temp += st.top();
				st.pop();
			}
			st.pop();
			st.push(temp);
		} else if (c >= '1' && c <= '9') {
			int temp = st.top();
			temp *= int(c-'0');
			st.pop();
			st.push(temp);
		 } else {
			st.push(m[c]);
		 }
	}
	while (!st.empty()) {
		ret += st.top();
		st.pop();
	}

	cout << ret << endl;
}
  
int32_t main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
	solve();
	
    return 0;
}

