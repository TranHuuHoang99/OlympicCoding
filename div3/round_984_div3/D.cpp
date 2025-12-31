#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve(void) {
	int n, m;
	cin >> n >> m;
	vector<string> matrix(n);
	for (int i = 0; i < n; i++) cin >> matrix[i];
	int ret = 0;
	for (int i = 0; i+i < min(n, m); i++) {
		string temp = "";
		for (int j = i+1; j < m-i; j++) temp += matrix[i][j];
		for (int j = i+1; j < n-i; j++) temp += matrix[j][m-i-1];	
		for (int j = m-i-2; j >= i+1; j--) temp += matrix[n-i-1][j];
		for (int j = n-i-1; j >= i; j--) temp += matrix[j][i];
		temp += temp.substr(0,3);
		for (int j = 0; j <= (int)temp.size() - 4; j++) {
			if (temp.substr(j,4) == "1543") ret++;
		}
	}	

	cout << ret << endl;
}
  
int32_t main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;
	while (t--) {
		solve();
	}	

	return 0;
}



