#include <bits/stdc++.h>

#define ll long long
using namespace std;

const ll N = 1e5+1;
ll arr1[N], arr2[N], dp1[N], dp2[N];
int N1, N2;

void solve(void) {
	cin >> N1;
	for (int i = 1; i <= N1; i++) cin >> arr1[i];
	cin >> N2;
	for (int i = 1; i <= N2; i++) cin >> arr2[i];

	dp1[1] = arr1[1];
	dp2[1] = arr2[1];

	for (int i = 2; i <= N1; i++) dp1[i] = dp1[i-1] + arr1[i];
	for (int i = 2; i <= N2; i++) dp2[i] = dp2[i-1] + arr2[i];

	map<ll,int> m;
	for (int i = 1; i <= N2; i++) m[arr2[i]] = i;

	int first = 0;
	int second = 0;
	
	vector<ll> ret_arr;
	for (int i = 1; i <= N1; i++) {
		if (m.find(arr1[i]) != m.end()) {
			int index = m[arr1[i]];
			ll temp = max(dp2[index] - dp2[second], dp1[i] - dp1[first]);
			first = i;
			second = index;
			ret_arr.push_back(temp);
		}
		if (first == N1 || second == N2) break; 
	}

	ll ret = 0;
	for (ll r : ret_arr) ret += r;

	if (first < N1 && second < N2) {
		ll temp = max(dp1[N1] - dp1[first], dp2[N2] - dp2[second]);
		ret += temp;
	} else if (first < N1 && second == N2) {
		ret += dp1[N1] - dp1[first];
	} else if (first == N1 && second < N2) {
		ret += dp2[N2] - dp2[second];
	} else {
		ret = ret;
	}

	cout << ret << endl;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();

    return 0;
}
