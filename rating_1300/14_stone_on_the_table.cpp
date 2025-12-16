/*
**************************************************************************
  	author     : hoangprodn
  	email  	   : thhoang08091999@gmail.com
  	local time : 2025-12-16 21:38:22 
************************************************************************** 
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

string str;
int n;
void solve(void) {
	cin >> n;
	cin >> str;
	int ret = 0;
	for (int i = 0; i < str.size()-1; i++) {
	 	if (str[i] == str[i+1]) ret++;
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

