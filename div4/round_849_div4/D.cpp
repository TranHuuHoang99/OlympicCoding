/*
**************************************************************************
  	author     : hoangprodn
  	email  	   : thhoang08091999@gmail.com
  	local time : 2025-12-01 11:39:45 
************************************************************************** 
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll N = 2e5+10;
int prefix[N];
int suffix[N];
int n;
string str;
void solve(void) {
	cin >> n;
	cin >> str;
	memset(prefix, 0, sizeof(prefix));
	memset(suffix, 0, sizeof(suffix));
	set<char> save;
	for (int i = 1; i <= n; i++) {
	 	save.insert(str[i-1]);
	 	prefix[i] = (int)save.size();
	}
	save.clear();
	for (int i = n; i >= 1; i--) {
	 	save.insert(str[i-1]);
	 	suffix[i] = (int)save.size();
	}
	int ret = 0;
	for (int i = 1; i <= n; i++) {
	 	ret = max(ret, max(prefix[i-1]+suffix[i], prefix[i]+suffix[i+1]));
	}
	cout << ret << endl;
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
 