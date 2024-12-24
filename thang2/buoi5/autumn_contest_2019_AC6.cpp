/*
 ******************************************************************************************
 *      * AUTHOR : hoangprodn
 *      * CREATED: 25.12.2024 12:38:41
 ******************************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 60;
pair<int,int> A[N];
int color[N];
int n, k;

bool cmp(pair<int,int> a, pair<int,int> b) {
 	return a.second > b.second;
}

void solve(void) {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> A[i].first >> A[i].second;
	}
	sort(A,A+n,cmp);
	memset(color,0,sizeof(color));
	int cnt = 0;
	int ret = 0;
	for (int i = 0; i < n; i++) {
	 	if (cnt == 2*k) break;
	 	if (color[A[i].first] < k) {
	 	 	color[A[i].first]++;
	 	 	cnt++;
	 	 	ret += A[i].second;
		}
	}
	if (cnt != 2*k) {
	 	cout << -1 << endl;
	} else {
	 	cout << ret << endl;
	}
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
