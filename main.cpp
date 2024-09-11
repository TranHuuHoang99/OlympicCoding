#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll dp[18+1];
ll a, b;

ll count_func(ll inp) {
	if (inp < 1) {
		return inp == 0 ? 1 : 0;
	}

	ll ret = 0;
	string str = to_string(inp);
	ll prv = 0;
	
	for (int i = 0; i < str.size(); i++) ret += dp[i];

	for (int i = 0; i < str.size(); i++) {
		ll digit = (ll)(str[i]-'0');
		int idx = str.size() - i - 1;
		ll numb = digit > prv ? digit-1 : digit;
		ret += digit == 0 ? 0 : numb * dp[idx];

		if (digit == prv) return ret;

		prv = digit;
	}

	return ret+1;	
}

void solve(void) {
	cin >> a >> b;
	dp[0] = 1;
	ll temp = 1;
	for (int i = 1; i <= 18; i++) {
		temp *= 9;
		dp[i] = temp;
	}

	cout << count_func(b) - count_func(a-1) << endl;
}
  
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();	

	return 0;
}
