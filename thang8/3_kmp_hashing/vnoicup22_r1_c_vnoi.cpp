/*
**************************************************************************
  	author     : hoangprodn
  	email  	   : thhoang08091999@gmail.com
  	local time : 2025-07-24 21:34:06 
************************************************************************** 
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct Node {
  	string str;
  	int id;
  	vector<ll> prefix, suffix;
};
const ll N = 1e6+10;
const ll prime = 1e9+7;
int n;
ll power_prime[N];
Node A[N];
map<ll, int> hashA[N];
int ans[N];

bool cmp(const Node& a, const Node& b) {
 	return a.str.size() > b.str.size();
}

void solve(void) {
	power_prime[0] = 1ll;
 	for (int i = 1; i <= 1e6; i++) {
 	 	power_prime[i] = power_prime[i-1] * prime;
 	}
 	cin >> n;
 	for (int i = 1; i <= n; i++) {
 	    string str;
 	    cin >> str;
 	    A[i].str = str;
 	    A[i].id = i;
 	}	
 	sort(A+1, A+1+n, cmp);
 	for (int i = 1; i <= n; i++) {
 	 	int len = A[i].str.size();
 	 	A[i].prefix.assign(len+1, 0ll);
 	 	for (int j = 1; j <= len; j++) {
 	 	 	A[i].prefix[j] = A[i].prefix[j-1] + int(A[i].str[j-1]-'a'+1) * power_prime[j-1];
 	 	}
 	 	A[i].suffix.assign(len+2, 0ll);
 	 	for (int j = len; j >= 1; j--) {
 	 	 	A[i].suffix[j] = A[i].suffix[j+1] + int(A[i].str[j-1]-'a'+1) * power_prime[j-1];
 	 	}
	}
	for (int i = 1; i <= n; i++) {
	 	int len = A[i].str.size();
	 	ll val = A[i].prefix[len];
	 	hashA[len][val] = INT32_MAX;
	 	for (int j = 1; j <= len; j++) {
	 		ll temp = A[i].prefix[j] + int(A[i].str[j-1]-'a'+1) * power_prime[j] + A[i].suffix[j+1] * prime;
			if (hashA[len+1].find(temp) == hashA[len+1].end()) {
			 	hashA[len][val] = 1;
			 	break;
	 		} else {
				hashA[len][val] = min(hashA[len][val], hashA[len+1][temp]+1); 		 	
	 		}
	 	}
	 	ans[A[i].id] = hashA[len][val];	
	}
	for (int i = 1; i <= n; i++) cout << ans[i] << endl;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
#ifdef HOANGPRODN_DEBUG
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
#endif // HOANGPRODN_DEBUG
	solve();
	return 0;
}

