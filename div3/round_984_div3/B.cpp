#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 2e5+1;
int n, k;

void solve(void) {
	cin >> n >> k;
	map<int,int> m;
	for (int i = 0; i < k; i++) {
		int b ,c;
		cin >> b >> c;
		m[b] += c;
	}

	vector<int> temp;
	for (auto _m : m) temp.push_back(_m.second);
	sort(temp.begin(), temp.end(), greater<int>());
	int ret = 0;
	for (int i = 0; i < min(n, (int)temp.size()); i++) ret += temp[i];

	cout << ret << endl;
}
  
int32_t main(void) {
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


