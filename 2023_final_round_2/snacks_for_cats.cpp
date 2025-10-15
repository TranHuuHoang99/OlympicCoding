/*
**************************************************************************
  	author     : hoangprodn
  	email  	   : thhoang08091999@gmail.com
  	local time : 2025-10-15 22:39:35 
************************************************************************** 
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll N = 60;
int n, m;
ll A[N][N];
ll V[N];
const ll ESP = 1e-9;

pair<ll,ll> plusPair(pair<ll,ll> left, pair<ll,ll> right) {
	if (left.first == 0) return right;
	if (right.first == 0) return left;
	ll a = left.first;
	ll b = left.second;
	ll c = right.first;
	ll d = right.second;
	ll top = a*d + b*c;
	ll bottom = b*d;
	ll g = gcd(top,bottom);
	return {top/g, bottom/g};
}

bool cmp(pair<ll,ll> left, pair<ll,ll> right) {
 	return left.first * right.second < right.first * left.second;
}

void solve(void) {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		cin >> V[i];
	 	for (int j = 1; j <= n; j++) {
	 	 	cin >> A[i][j];
	 	}
	}
	vector<pair<ll,ll>> save(n+1);
	for (int cat = 1; cat <= n; cat++) {
		pair<ll,ll> temp = {0ll,0ll};
	 	for (int snack = 1; snack <= m; snack++) {
			temp = plusPair(temp, {A[snack][cat], V[snack]});
	 	}
		save[cat] = temp;
	}
	if (n == 1) {
	 	cout << save[1].first << '/' << save[1].second << endl;
	 	return;
	}
	sort(save.begin()+1, save.end(), cmp);
	pair<ll,ll> left = save[1];
	pair<ll,ll> right = save[n];
	ll top = left.first * right.second - right.first * left.second;
	if (top < 0ll) top = -top;
	if (top <= 0ll) {
	 	cout << 0 << endl;
	 	return;
	}
	ll bottom = left.second * right.second;
	ll g = gcd(top,bottom);
	top /= g;
	bottom /= g;
	if (bottom == 1) {
	 	cout << top << endl;
	 	return;
	}
	cout << top << '/' << bottom << endl;
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














