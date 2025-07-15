#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll n;
vector<ll> ans;

void solve(void) {
	cin >> n;
	for (ll i = 2ll; i * i <= n; i++) {
	 	vector<ll> save;
	 	ll temp = n;
	 	while (temp > 0ll) {
	 	 	save.push_back(temp % i);
	 	 	temp /= i;
	 	}
	 	int left = 0;
	 	int right = save.size()-1;
	 	bool isValid = true;
	 	while (left <= right) {
	 	    if (save[left] == save[right]) {
	 	        left++;
	 	        right--;
	 	    } else {
	 	     	isValid = false;
	 	     	break;
	 		}
	 	}
	 	if (isValid) ans.push_back(i);	
	}
	for (ll i = 1ll; i * i <= n; i++) {
	 	if (n % i != 0) continue;
	 	ll temp = n / i - 1ll;
	 	if (temp > sqrt(n)) {
	 	 	ans.push_back(temp);
	 	}
	}
	sort(ans.begin(), ans.end());
	if (ans.empty()) {
	 	cout << "*" << endl;
	} else {
	 	for (int i = 0; i < ans.size(); i++) cout << ans[i] << ' ';
	 	cout << endl;
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}

