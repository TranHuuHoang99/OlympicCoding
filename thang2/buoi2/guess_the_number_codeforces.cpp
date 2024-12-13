/*
 ******************************************************************************************
 *      * AUTHOR : hoangprodn
 *      * CREATED: 11.12.2024 21:55:00
 ******************************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve(void) {
	int left = 1;
	int right = 1e6;
	int ret = -1;
	while (left <= right) {
	 	int mid = (left+right)/2;
	 	cout << mid << endl;
	 	fflush(stdout);
	 	string str;
	 	cin >> str;
	 	if (str == ">=") {
	 	 	ret = mid;
	 	 	left = mid+1;
	 	} else {
	 		right = mid-1;  	
	 	}
	}
	cout << "! " << ret << endl;
	fflush(stdout);
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	solve();

	return 0;
}
