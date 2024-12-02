#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 2e5+1;
pair<ll,ll> A[N];
int n, k;

bool cmp(pair<ll,ll> a, pair<ll,ll> b) {
	return a.second < b.second;
}

void solve(void) {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> A[i].first >> A[i].second;
	}
	sort(A,A+n,cmp);
	int ret = 0;
	multiset<ll> ms;
	for (int i = 0; i < k; i++) ms.insert(0);
	for (int i = 0; i < n; i++) {
		auto it = ms.upper_bound(A[i].first);
		if (it != ms.begin()) {
			ret++;
			--it;
			ms.erase(it);
			ms.insert(A[i].second);
		}
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


