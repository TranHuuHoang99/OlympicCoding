/*
**************************************************************************
  	author     : hoangprodn
  	email  	   : thhoang08091999@gmail.com
  	local time : 2026-04-05 13:11:53 
************************************************************************** 
*/
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MOD = 676767677;
const int N = 2e5+10;
int n, m;
int A[N];
int cnt[N];
int prefix[N];
void solve(void) {
 	memset(A, 0, sizeof(A));
	memset(cnt, 0, sizeof(cnt));
	memset(prefix, 0, sizeof(prefix));
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
	 	cin >> A[i];
		cnt[A[i]]++;
	}
	A[0] = A[n+1] = 2e6+10;
	for (int i = 0; i < m; i++) {
	 	prefix[i+1] = prefix[i] + cnt[i];
	}
	int ret = 1ll;
	for (int i = 1; i <= n; i++) {
	 	if (A[i] == 0) continue;
		int min_val = min(A[i-1], A[i+1]);
		min_val += 1;
		if (A[i] > min_val) {
		 	ret = (ret % MOD * cnt[A[i]-1] % MOD) % MOD;
		} else if (A[i] == min_val) {
		 	ret = (ret % MOD * prefix[A[i]] % MOD) % MOD;
        } else {
         	ret = 0;
        }                                
	}
	cout << ret % MOD << endl;
}
signed main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
		solve();
    }
    return 0;
}
