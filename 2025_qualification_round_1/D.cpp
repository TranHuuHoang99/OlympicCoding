/*
**************************************************************************
  	author     : hoangprodn
  	email  	   : thhoang08091999@gmail.com
  	local time : 2025-10-18 16:44:54 
************************************************************************** 
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e3+10;
int n;
pair<int,int> save[N];
int prefix[N];
int F[N][N];
void solve(void) {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> save[i].first >> save[i].second;
	}
	sort(save+1, save+1+n, [&] (pair<int,int> a, pair<int,int> b) -> bool {
		return a.first < b.first;
	});
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			F[i][j] = LLONG_MAX;
		}
	}
	for (int i = 0; i <= n+10; i++) prefix[i] = 0;
	for (int i = 1; i <= n; i++) {
		prefix[i] = prefix[i-1] + save[i].second;
	}
	int total = prefix[n];
	int min_val_1 = -(total/2);
	int min_val_2 = (total/2);
	for (int i = 1; i <= n; i++) {
		F[i][i] = save[i].first * save[i].first;
		if (min_val_1 > save[i].first) {
			F[i][i] = min(F[i][i], min_val_1 * min_val_1 + (min_val_1 - save[i].first) * total);
		}
		if (min_val_2 < save[i].first) {
			F[i][i] = min(F[i][i], min_val_2 * min_val_2 + (save[i].first - min_val_2) * total);
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int lefti = j-i+1;
			int righti = j+i-1;
			// current direction is forward to the left
			if (lefti >= 1 && F[j][lefti] != LLONG_MAX) {
				int cost = prefix[n] - (prefix[j] - prefix[lefti-1]);
				// move to the left
				if (lefti-1 >= 1) {
					int dist = abs(save[lefti-1].first - save[j].first);
					F[lefti-1][j] = min(F[lefti-1][j], F[j][lefti] + dist * cost);
				}
				// move to the right
				if (j+1 <= n) {
					int dist = save[j+1].first - save[j].first;
					F[j+1][lefti] = min(F[j+1][lefti], F[j][lefti] + dist * cost);
				}
			}
			// current direction is forward to the right
			if (righti <= n && F[j][righti] != LLONG_MAX) {
				int cost = prefix[n] - (prefix[righti] - prefix[j-1]);
				// move to the right
				if (righti+1 <= n) {
					int dist = save[righti+1].first - save[j].first;
					F[righti+1][j] = min(F[righti+1][j], F[j][righti] + dist * cost);
				}
				// move to the left
				if (j-1 >= 1) {
					int dist = abs(save[j-1].first - save[j].first);
					F[j-1][righti] = min(F[j-1][righti], F[j][righti] + dist * cost);
				}
			}
		}
	}
	int ret = min(F[1][n], F[n][1]);
	cout << ret << endl;
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

