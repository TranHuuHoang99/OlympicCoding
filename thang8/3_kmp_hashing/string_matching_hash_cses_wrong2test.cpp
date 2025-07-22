/*  
**************************************************************************
  	author     : hoangprodn
  	email  	   : thhoang08091999@gmail.com
  	local time : 2025-07-21 22:38:54 
************************************************************************** 
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll N = 1e6+10;
const ll prime = 31ll;
string pattern, text;
ll power31[N];
ll hashP[N];

void solve(void) {
 	cin >> pattern >> text;
 	int n = pattern.size();
 	int m = text.size();
 	pattern = " " + pattern;
 	text = " " + text;
 	power31[0] = 1ll;
 	for (int i = 1; i <= n; i++) power31[i] = power31[i-1] * prime;
 	for (int i = 1; i <= n; i++) {
 	    hashP[i] = hashP[i-1] + 1ll * int(pattern[i]-'a'+1) * power31[i-1];
 	}	
 	ll hashT = 0ll;
 	for (int i = 1; i <= m; i++) hashT += int(text[i]-'a'+1) * power31[i-1];
 	int ret = 0;
 	for (int i = m; i <= n; i++) {
 	 	if (hashP[i] - hashP[i-m] == hashT * power31[i-m]) ret++;
 	}
 	cout << ret << endl;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
#ifdef HOANGPRODN_DEBUG
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
#endif // HOANGPRODN_DEBUG
	solve();
	return 0;
}

