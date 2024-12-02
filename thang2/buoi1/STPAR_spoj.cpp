/*
 ******************************************************************************************
 *      * AUTHOR : hoangprodn
 *      * CREATED: 03.12.2024 20:48:56
 ******************************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int n;

void solve(void) {
	while (cin >> n && n != 0) {
	 	vector<int> A(n);
	 	for (int i = 0; i < n; i++) cin >> A[i];
	 	stack<int> st;
	 	int order = 1;
	 	for (int i = 0; i < n; i++) {
			if (A[i] == order) {
			 	order++;
			} else {
			 	while (!st.empty() && st.top() == order) {
			 	 	st.pop();
					order++;
			 	}
			 	st.push(A[i]);
			}
	 	}
	 	while (!st.empty() && st.top() == order) {
	 	 	st.pop();
	 	 	order++;
	 	}
	 	cout << (st.empty() ? "yes" : "no") << endl;
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	solve();

	return 0;
}
