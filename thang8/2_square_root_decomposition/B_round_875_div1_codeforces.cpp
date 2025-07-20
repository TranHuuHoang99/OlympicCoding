/*
**************************************************************************
  	author     : hoangprodn
  	email  	   : thhoang08091999@gmail.com
  	local time : 2025-07-20 14:02:08 
************************************************************************** 
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll N = 2e5+10;
int n;
int cnt[N];
pair<int,int> A[N];

bool cmp(pair<int,int> a, pair<int,int> b) {
    return a.first < b.first;
}	

void solve(void) {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> A[i].first;
    for (int i = 1; i <= n; i++) cin >> A[i].second;
    sort(A+1, A+1+n, cmp);
    // because we sort increased order by a so ai is a constant from 1 -> sqrt(2*n)
	// because bi + bj <= 2 * n <=> ai * aj <= 2 * n <=> ai <= sqrt(2*n)
	// so we have const square is sqrt(2*n)
	ll ret = 0ll;
	for (int ai = 1; ai <= sqrt(2*n); ai++) {
		// reset counting table
		for (int i = 0; i <= n; i++) cnt[i] = 0;
	    for (int j = 1; j <= n; j++) {
	    	// we have ai * aj = bi + bj
			// => bi = ai * aj - bj (with ai from 1->sqrt(2*n)) 	
			int bi = ai * A[j].first - A[j].second;
			if (1 <= bi && bi <= n) {
			    ret += 1ll * cnt[bi];
			}
			// if current index exist constant value from 1 -> sqrt(2*n)
			if (ai == A[j].first) {
				cnt[A[j].second]++;
			}
	    }
	}
	cout << ret << endl;	
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
	for (int i = 1; i <= t; i++) {
	 	solve();
	}
	return 0;
}

