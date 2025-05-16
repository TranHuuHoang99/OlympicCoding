#include <bits/stdc++.h>
#define ll long long

using namespace std;

string str;

ll Cal(ll a) {
 	ll ret = a;
 	ret *= (a-1ll);
 	ret /= 2;
 	return ret;
}

void solve(void) {
	cin >> str;
	int n = int(str.size());
	int temp = n;
	for (int i = 0; i < n; i++) {
	 	if (str[i] != '?') {
	 	 	temp = i;
	 	 	break;
	 	}
	}
	for (int i = 0; i < temp; i++) {
	 	str[i] = (temp == n) ? 'A' : str[temp];
	}
	temp = -1;
	for (int i = n-1; i >= 0; i--) {
	 	if (str[i] != '?') {
	 	 	temp = i;
	 	 	break;
	 	}
	}
	for (int i = temp+1; i < n; i++) str[i] = str[temp];
	vector<pair<char,int>> save;
	int numb = 1;
	char ch = str[0];
	for (int i = 1; i < n; i++) {
	 	if (str[i] == str[i-1]) {
	 	 	numb++;
	 	} else {
			save.push_back({ch, numb});
			numb = 1;
			ch = str[i];	 	 	
	 	}
	}
	save.push_back({ch,numb});
	int len = int(save.size());
	vector<int> sum(len,0);
	for (int i = 0; i < len; i++) {
	 	sum[i] = (i == 0 ? 0 : sum[i-1]) + save[i].second;
	}
	vector<int> prePos(len, 0);
	vector<int> lastPos(26, -1);
	for (int i = 0; i < len; i++) {
	 	if (save[i].first == '?') {
	 	 	if (i > 0) {
	 	 	 	prePos[i] = prePos[i-1];
	 	 	}
	 	} else {
	 	 	for (int ch = 0; ch < 26; ch++) {
	 	 	 	if (int(save[i].first-'A') != ch) {
	 	 	 	 	prePos[i] = max(prePos[i], lastPos[ch]+1);
	 	 	 	}
	 	 	}
	 	 	lastPos[int(save[i].first-'A')] = i;
	 	}
	}
	vector<ll> dp(len,0ll);
	for (int i = 0; i < len; i++) {
	 	int p = prePos[i];
	 	if (p == 0) {
	 	 	dp[i] = Cal(sum[i]);
	 	} else {
	 	 	dp[i] = dp[p-1] + Cal(1ll * (sum[i]-sum[p-1]));
	 	 	if (save[p].first == '?') {
	 	 	 	dp[i] = max(dp[i], dp[p] + Cal(1ll*(sum[i]-sum[p])));
	 	 	}
	 	}
	}
	cout << Cal(1ll * n) - dp[len-1] << endl;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	freopen("ADN.INP", "r", stdin);
	freopen("ADN.OUT", "w", stdout);
	
	solve();

	return 0;
}

