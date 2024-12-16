/*
 ******************************************************************************************
 *      * AUTHOR : hoangprodn
 *      * CREATED: 14.12.2024 13:47:15
 ******************************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 32;
int cnt[N];
int n, k;

void solve(void) {
	memset(cnt,0,sizeof(cnt));
	cin >> n >> k;
	int ret = 0;
	for (int i = 0; i < n; i++) {
	 	int temp;
	 	cin >> temp;
	 	if (i == 0) {
 			ret = temp;
	 	} else {
	 	 	ret &= temp;
	 	}
	 	for (int j = 0; j < 31; j++) {
	 	 	if (!(temp & (1<<j))) cnt[j]++;
	 	}
	}    	
	for (int i = 30; i >= 0; i--) {
	 	if (ret & (1<<i)) continue;
	 	if (k >= cnt[i]) {
	 	 	ret |= (1<<i);
	 	 	k -= cnt[i];
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
	while (t--) {
	 	solve();
	}

	return 0;
}
