/*
**************************************************************************
  	author     : hoangprodn
  	email  	   : thhoang08091999@gmail.com
  	local time : 2025-08-01 21:26:32 
************************************************************************** 
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll N = 100+10;
vector<int> A;
int n;
map<vector<int>, int> map_mask;

void solve(void) {
	cin >> n;
	A.resize(n);
	for (int i = 0; i < n; i++) cin >> A[i];
	for (int mask = 0; mask < (1 << 15); mask++) {
	 	vector<int> save_one;
	 	for (int i = 0; i < A.size(); i++) {
	 		int cnt = 0;
	 	 	for (int b = 0; b < 15; b++) {
	 	 	 	bool one_mask = (mask & (1 << b));
	 	 	 	bool one_A = (A[i] & (1 << b));
	 	 	 	if (one_mask != one_A) {
					cnt++;
	 	 	 	}	
	 	 	}
	 	 	save_one.push_back(cnt);
	 	}
	 	map_mask[save_one] = mask;
	}
	for (int mask = 0; mask < (1 << 15); mask++) {
	 	vector<int> save_one;
	 	for (int i = 0; i < A.size(); i++) {
	 	 	int cnt = 0;
	 	 	for (int b = 0; b < 15; b++) {
	 	 	 	bool one_mask = (mask & (1 << b));
	 	 	 	bool one_A = (A[i] & (1 << (b+15)));
	 	 	 	if (one_mask != one_A) {
	 	 	 	 	cnt++;
	 	 	 	}
	 	 	}
	 	 	save_one.push_back(cnt);
	 	}
		for (int numb = 0; numb <= 30; numb++) {
			vector<int> remain_one;
			bool isValid = true;
		 	for (int i = 0; i < save_one.size(); i++) {
		 	    if (numb - save_one[i] > 15) {
 					isValid = false;
 					break;
		 	    }
		 	    remain_one.push_back(numb-save_one[i]);
		 	}	
		 	if (isValid) {
		 	 	if (map_mask.find(remain_one) != map_mask.end()) {
		 	 	 	cout << ((mask << (15)) | (map_mask[remain_one])) << endl;
		 	 	 	return;
		 	 	}
		 	}
		}
	}
	cout << -1 << endl;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}

