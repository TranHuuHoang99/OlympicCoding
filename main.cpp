#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve(void) {
	int n;
	cin >> n;
	
	vector<ll> ret;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		int idx = lower_bound(ret.begin(), ret.end(), temp) - ret.begin();
		if (idx == ret.size()) {
			ret.push_back(temp);
		} else {
			ret[idx] = temp;
		}
	}

	cout << ret.size() << endl;
	
}
  
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();	

	return 0;
}
