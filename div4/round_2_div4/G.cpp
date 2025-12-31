/*
 ******************************************************************************************
 *      * AUTHOR : hoangprodn
 *      * CREATED: 14.12.2024 13:17:24
 ******************************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 51;
char matrix[N][N];
int n, m;

void solve(void) {
	memset(matrix, 0, sizeof(matrix));
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
	 	for (int j = 0; j < m; j++) {
	 	 	cin >> matrix[i][j];
	 	}
	}
	for (int j = 0; j < m; j++) {
		stack<int> st;
		for (int i = 0; i < n; i++) {
		 	if (matrix[i][j] == '*') st.push(i);
		}
		while (!st.empty()) {
		 	int idx = st.top();
		 	st.pop();
		 	for (int i = idx; i < n-1; i++) {
		 	 	if (matrix[i+1][j] == '.') {
		 	 	 	swap(matrix[i][j], matrix[i+1][j]);
		 	 	} else {
		 	 	 	break;
		 	 	}
		 	}
		}
	}
	for (int i = 0; i < n; i++) {
	 	for (int j = 0; j < m; j++) {
	 	 	cout << matrix[i][j];
	 	}
	 	cout << endl;
	}
	cout << endl;
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
