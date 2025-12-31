/*
**************************************************************************
  	author     : hoangprodn
  	email  	   : thhoang08091999@gmail.com
  	local time : 2025-12-15 09:49:37 
************************************************************************** 
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

string str;
void solve(void) {
	cin >> str;
	int cnt_b = 0;
	int cnt_a = 0;
	vector<int> save;
	for (int i = 0; i < str.size(); i++) {
	 	if (str[i] == 'B') {
	 	 	cnt_b++;
	 	 	if (cnt_a != 0) {
	 	 	 	save.push_back(cnt_a);
	 	 	}
	 	 	cnt_a = 0;
	 	} else {
 			cnt_a++;
	 	}
	}
	if (cnt_a != 0) save.push_back(cnt_a);
	if (cnt_b >= save.size()) {
	 	cout << accumulate(save.begin(), save.end(), 0) << endl;
	} else {
	 	int ret = 0;
	 	sort(save.begin(), save.end(), [&](int a, int b) -> bool {
	 	   	return a > b;
	 	});
	 	for (int i = 0; i < cnt_b; i++) {
			ret += save[i];
	 	}
	 	cout << ret << endl;
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
 