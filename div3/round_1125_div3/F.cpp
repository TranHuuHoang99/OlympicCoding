/*
**************************************************************************
  	author     : hoangprodn
  	email  	   : thhoang08091999@gmail.com
  	local time : 2026-10-09 14:08:16 
************************************************************************** 
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5+10;
const int M = 32005;
int n;
int A[N];
int is_prime[M];
vector<int> primes;
void init(void) {
 	memset(is_prime, 1, sizeof(is_prime));
 	for (int i = 2; i <= 32000; i++) {
     	if (!is_prime[i]) continue;
     	primes.push_back(i);
     	for (int j = i*i; j <= 32000; j+=i) {
     	 	is_prime[j] = false;
     	}
    }
}
void solve(void) {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> A[i];
	vector<vector<int>> k_masks(n);
	for (int i = 1; i <= n; i++) {
		vector<int> temp;
		int val = A[i];
		for (int j = 0; j < primes.size() && primes[j] * primes[j] <= val; j++) {
		 	int prime = primes[j];
		 	if (val % prime != 0) continue;
		 	int cnt = 0;
		 	while (val % prime == 0) {
		 	 	cnt++;
		 	 	val /= prime;
		 	}
		 	if (cnt&1) {
		 	 	temp.push_back(prime);
		 	}
		}
		if (val > 1) temp.push_back(val);
		k_masks[i-1] = temp;
	}
	map<vector<int>, int> save_mask;
	set<int> odd_prime_fact;
	for (int i = 0; i < n; i++) {
	 	for (int k_m : k_masks[i]) {
	 	 	auto it = odd_prime_fact.insert(k_m);
	 	 	if (!it.second) {
	 	 	 	odd_prime_fact.erase(it.first);
	 	 	}
	 	}
	 	if (odd_prime_fact.size() > 7) continue;
	 	save_mask[vector<int>(odd_prime_fact.begin(), odd_prime_fact.end())] += 1;
	}
	int ret = 0;
	for (const vector<int>& k_m : k_masks) {
	 	auto it = save_mask.find(k_m);
	 	if (it != save_mask.end()) {
	 	 	ret += it->second;
	 	}
	}
	cout << ret << '\n';
}
signed main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	init();
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
	 	solve();
	}
	return 0;
}






















