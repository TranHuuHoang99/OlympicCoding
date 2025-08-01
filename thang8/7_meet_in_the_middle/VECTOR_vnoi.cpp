/*
**************************************************************************
  	author     : hoangprodn
  	email  	   : thhoang08091999@gmail.com
  	local time : 2025-08-01 20:15:35 
************************************************************************** 
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll N = 40;
pair<int,int> A[N];
pair<int,int> base;
map<pair<int,int>, int> cnt;
int n;

void solve(void) {
	cin >> n;
	for (int i = 0; i < n; i++) {
	 	cin >> A[i].first >> A[i].second;
	}
	cin >> base.first >> base.second;
	int half = n/2;
	int len1 = (1 << half);
	int len2 = (1 << (n-half));
	int ret = 0;
	for (int mask = 0; mask < len1; mask++) {
		pair<int,int> temp = {0,0};
		for (int i = 0; i < half; i++) {
		 	if (mask & (1 << i)) {
		 	 	temp.first += A[i].first;
		 	 	temp.second += A[i].second;
		 	}
		}
		cnt[temp]++;
	}
	for (int mask = 0; mask < len2; mask++) {
	 	pair<int,int> temp = {0,0};
	 	for (int i = half; i < n; i++) {
	 	 	if (mask & (1 << (i-half))) {
	 	 	 	temp.first += A[i].first;
	 	 	 	temp.second += A[i].second;
	 	 	}
	 	}
	 	pair<int,int> remain = {base.first - temp.first, base.second - temp.second};
		if (cnt.find(remain) != cnt.end()) {
		  	ret += cnt[remain];
		}
	}    	
	cout << ret << endl;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}

