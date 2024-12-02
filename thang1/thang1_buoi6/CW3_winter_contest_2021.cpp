/*
 ******************************************************************************************
 *      * AUTHOR : hoangprodn
 *      * CREATED: 01.12.2024 16:41:40
 ******************************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve(void) {
	int n, b;
	cin >> n >> b;
	vector<vector<ll>> A(n+1,vector<ll>(b,0));
	for (int i = 1; i <= n; i++) {
	 	for (int j = 0; j < b; j++) {
 			cin >> A[i][j];
	 	}
	}
	vector<vector<ll>> update(n+1, vector<ll>(b,0));
	for (int j = 0; j < b; j++) {
	 	for (int i = 1; i <= n; i++) {
	 	 	update[i][j] = update[i-1][j] + A[i][j];
	 	}
	}
	map<vector<ll>,ll> mp;
	vector<ll> start(b-1,0);
	mp[start] = 1;
	ll ret = 0;
	for (int i = 1; i <= n; i++) {
		vector<ll> temp(b-1,0);
		for (int j = 0; j < b-1; j++) {
		 	temp[j] = update[i][j] - update[i][j+1];
		}
		ret += mp[temp];
		mp[temp]++;
	}
	cout << ret << endl;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
		
	int t;
	cin >> t;
	while (t--) {
	 	solve();
	}

	return 0;
}
