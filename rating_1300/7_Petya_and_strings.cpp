/*
**************************************************************************
  	author     : hoangprodn
  	email  	   : thhoang08091999@gmail.com
  	local time : 2025-12-16 10:43:04 
************************************************************************** 
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

string str1, str2;
void solve(void) {
	cin >> str1 >> str2;
	int n = str1.size();
	for (int i = 0; i < n; i++) {
	 	int temp1;
	 	if ('a' <= str1[i] && str1[i] <= 'z') {
	 	 	temp1 = int(str1[i]-'a');
	 	} else {
	 	 	temp1 = int(str1[i]-'A');
	 	}
	 	int temp2;
	 	if ('a' <= str2[i] && str2[i] <= 'z') {
	 	 	temp2 = int(str2[i]-'a');
	 	} else {
	 	 	temp2 = int(str2[i]-'A');
	 	}
	 	if (temp1 < temp2) {
	 	 	cout << -1 << endl;
	 	 	return;
	 	} else if (temp1 > temp2) {
	 	 	cout << 1 << endl;
	 	 	return;
	 	}
	}
	cout << 0 << endl;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}
 