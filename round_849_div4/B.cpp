/*
**************************************************************************
  	author     : hoangprodn
  	email  	   : thhoang08091999@gmail.com
  	local time : 2025-12-01 11:21:35 
************************************************************************** 
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

map<char, pair<int,int>> mp = {
  	{'U', {1, 0}},
  	{'D', {-1, 0}},
  	{'L', {0, -1}},
  	{'R', {0, 1}}
};
int n;
string str;
void solve(void) {
	cin >> n;
	cin >> str;
	int x = 0;
	int y = 0;
	for (char c : str) {
	 	auto [ver,hor] = mp[c];
	 	x += ver;
	 	y += hor;
	 	if (x == 1 && y == 1) {
	 	 	cout << "YES" << endl;
	 	 	return;
	 	}
	}
	cout << "NO" << endl;
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
 