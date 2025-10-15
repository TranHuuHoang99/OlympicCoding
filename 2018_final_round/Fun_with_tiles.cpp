/*
**************************************************************************
  	author     : hoangprodn
  	email  	   : thhoang08091999@gmail.com
  	local time : 2025-10-10 09:30:45 
************************************************************************** 
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll MOD = 1e9+7;
int R, C, n;
map<int,vector<int>> save;

ll fast_power(ll a, ll b) {
 	ll ret = 1ll;
 	while (b) {
 	 	if (b&1) ret = (ret % MOD * a % MOD) % MOD;
 	 	a = (a % MOD * a % MOD) % MOD;
 	 	b >>= 1ll;
 	}
 	return ret;
}

void solve(void) {
 	cin >> R >> C >> n;
 	for (int i = 1; i <= n; i++) {
 	 	int x, y;
 	 	cin >> x >> y;
 	 	save[x].push_back(y);
 	}
 	ll ret = 1ll;
 	ll sum = 0ll;
 	for (auto it : save) {
 	 	vector<int> stick = it.second;
 	 	stick.push_back(0);
 	 	stick.push_back(C+1);
 	 	sort(stick.begin(), stick.end());
 	 	for (int i = 0; i < stick.size()-1; i++) {
 	 	 	int diff = stick[i+1] - stick[i] - 1;
 	 	 	if (diff > 1) {
 	 	 	 	sum += diff / 2;
 	 	 	 	if (diff % 2 > 0) {
 	 	 	 	 	ret = (ret * ((diff+1) / 2)) % MOD;
 	 	 	 	}
 	 	 	}
 	 	}
 	}
	int temp = R - save.size();
	if (temp > 0) {
	 	sum += static_cast<long long>(1ll * (C/2) * (temp));
	 	if (C % 2 > 0) {
	 	 	ret = (ret * fast_power(1ll * (C+1)/2, 1ll * temp)) % MOD; 
	 	}
	}
	cout << sum << ' ' << ret << endl;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}

