/*
 ******************************************************************************************
 *      * AUTHOR : hoangprodn
 *      * CREATED: 02.12.2024 16:49:23
 ******************************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 3e4+1;
int A[N];
int n;

void solve(void) {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> A[i];
	pair<int,pair<int,int>> ret = {INT32_MIN, {INT32_MAX, INT32_MAX}};
	stack<int> st;
	for (int i = 0; i < n; i++) {
	 	while (!st.empty() && A[st.top()] >= A[i]) {
	 	 	int idx = st.top();
	 	 	st.pop();
	 	 	int width = st.empty() ? i : i - st.top() - 1;
	 	 	int left_pos = st.empty() ? 1 : st.top() + 2;
	 	 	int temp = width * A[idx];
	 	 	if (temp > ret.first) {
	 	 	 	ret.first = temp;
	 	 	 	ret.second = {left_pos, i};
	 	 	} else if (temp == ret.first) {
				if (ret.second.first > left_pos) {
				 	ret.second = {left_pos, i};
				}
	 	 	}
	 	}
	 	st.push(i);
	}
	while (!st.empty()) {
	 	int idx = st.top();
	 	st.pop();
	 	int width = st.empty() ? n : n - st.top() - 1;
	 	int left_pos = st.empty() ? 1 : st.top() + 2;
	 	int temp = width * A[idx];
	 	if (temp > ret.first) {
	 	 	ret.first = temp;
	 	 	ret.second = {left_pos, n};
	 	} else if (temp == ret.first) {
	 	 	if (ret.second.first > left_pos) {
	 	 	 	ret.second = {left_pos, n};
	 	 	}
	 	}
	}
	cout << ret.first << ' ' << ret.second.first << ' ' << ret.second.second << endl;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

#ifdef HOANGPRODN_DEBUG
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
#endif // HOANGPRODN_DEBUG
                  
	int t;
	cin >> t;
	while (t--) {
	 	solve();
	}

	return 0;
}
