/*
 ******************************************************************************************
 *      * AUTHOR : hoangprodn
 *      * CREATED: 30.11.2024 20:51:32
 ******************************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

multimap<ll,int> mm;
int n;
ll x;

void solve(void) {
	cin >> n >> x;
	for (int i = 1; i <= n; i++) {
	 	ll a;
	 	cin >> a;
	 	mm.insert({a,i});
	}
	for (auto it : mm) {
	 	ll temp = it.first;
	 	auto it_temp = mm.find(x-temp);
	 	if (it_temp != mm.end() && it.second != it_temp->second) {
	 	 	cout << it_temp->second << ' ' << it.second << endl;
	 	 	return;
	 	}
	}
	cout << "IMPOSSIBLE" << endl;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();

	return 0;
}
