/*
**************************************************************************
  	author     : hoangprodn
  	email  	   : thhoang08091999@gmail.com
  	local time : 2025-11-25 19:59:35 
************************************************************************** 
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n;
void solve(void) {
	cin >> n;
	vector<int> save;
	for (int i = 1; i <= n; i++) {
		int temp;
		cin >> temp;
		if (save.empty() || temp != save.back()) {
		 	save.push_back(temp);
		}
	}
	int ret = 0;
	for (int i = 0; i < save.size(); i++) {
	 	if ((i == 0 || save[i-1] > save[i]) && (i == save.size()-1 || save[i+1] > save[i])) {
	 		ret++;
	 	}
	}
	if (ret == 1) {
	 	cout << "YES" << endl;
	} else {
	 	cout << "NO" << endl;
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
	 	solve();
	}
	return 0;
}

