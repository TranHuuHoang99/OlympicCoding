#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 3e5+10;
const ll MOD = 998244353;
pair<int,int> A[N];
int n, k;
ll fact[N];
ll inv[N];
priority_queue<int, vector<int>, greater<int>> pq;

ll fast_pow(ll a, ll b) {
 	ll ret = 1ll;
 	while (b) {
 	 	if (b&1) ret = ret * a % MOD;
 	 	a = a * a % MOD;
 	 	b >>= 1;
 	}
 	return ret;
}

void init(void) {
 	fact[0] = 1ll;
 	inv[0] = 1ll;
 	for (int i = 1; i <= 3e5; i++) {
 	 	fact[i] = (fact[i-1] % MOD * 1ll * i) % MOD;
 	 	inv[i] = fast_pow(fact[i], MOD-2) % MOD;
 	}
}

ll combination(int a, int b) {
 	return (fact[a] % MOD * inv[b] % MOD * inv[a-b] % MOD) % MOD;
}

bool cmp(pair<int,int> a, pair<int,int> b) {
 	return a.first < b.first;
}

void solve(void) {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
	 	cin >> A[i].first >> A[i].second;
	}
	sort(A+1,A+1+n,cmp);
	ll ret = 0ll;
	for (int i = 1; i < n; i++) {
		int max_left = A[i].first;
		while (!pq.empty()) {
			if (pq.top() < max_left) {
				 pq.pop();
			} else {
				 break;
			}
	 	}
	 	if (k-1 <= int(pq.size())) {
			ret += (combination(int(pq.size()), k-1) % MOD) % MOD; 		 	
	 	}
		pq.push(A[i].second);
	}
	int max_left = A[n].first;
	while (!pq.empty()) {
		if (pq.top() < max_left) {
		 	pq.pop();
		} else {
		    break;
		}	
	}
	if (k-1 <= int(pq.size())) {
	 	ret += (combination(int(pq.size()), k-1)) % MOD;
	}
	cout << (ret % MOD) << endl;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

#ifdef HOANGPRODN_DEBUG
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
#endif // HOANGPRODN_DEBUG
    init();
	solve();

	return 0;
}

