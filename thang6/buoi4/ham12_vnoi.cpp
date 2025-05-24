#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 1e2+10;
int n, m, k;
string str;
string A[N];

void solve(void) {
	cin >> n >> m >> k;
	cin >> str;
	for (int i = 1; i <= k; i++) cin >> A[i];
	int ret = INT32_MAX;
	for (int i = 1; i <= k; i++) {
	 	string temp = A[i];
	 	for (int j = 0; j < n; j++) {
	 		int cnt = 0;
	 	 	for (int l = 0; l < m; l++) {
				if (temp[l] != str[(j+l) % n]) cnt++;					 	 	 	
	 	 	}
	 	 	ret = min(ret, cnt);
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

