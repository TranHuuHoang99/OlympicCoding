/*
 ******************************************************************************************
 *      * AUTHOR : hoangprodn
 *      * CREATED: 04.12.2024 22:50:53
 ******************************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N =1e5+1;
ll A[N];
int n;

void solve(void) {
	cin >> n;
	multiset<ll> ms;
	for (int i = 0; i < n; i++) {
	 	cin >> A[i];
	 	ms.insert(A[i]);
	}
	vector<ll> ret;
	for (int i = 0; i < n; i++) {
	 	ll temp = *ms.begin();
	 	if (A[i] == temp) {
	 		ret.push_back(A[i]); 	
	 	} else {
			ret.push_back(A[i]+1);
			ms.insert(A[i]+1);	 	 	
	 	}
	 	auto it = ms.find(A[i]);
	 	ms.erase(it);
	}
	sort(ret.begin(), ret.end());
	for (int i = 0; i < ret.size(); i++) cout << ret[i] << ' ';
	cout << endl;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

#ifdef HOANGPRODN_DEBUG
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
#endif // HOANGPRODN_DEBUG

	int t;
	cin >> t;
	while (t--) {
	 	solve();
	}

	return 0;
}
