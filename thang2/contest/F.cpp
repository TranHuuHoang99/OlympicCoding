/*
 ******************************************************************************************
 *      * AUTHOR : hoangprodn
 *      * CREATED: 06.01.2025 21:11:05
 ******************************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 1e5+1;
int A[N];
int n, m;

void solve(void) {
	cin >> n >> m;
	vector<int> pos;
	for (int i = 0; i < n; i++) {
		cin >> A[i];
		if (A[i] == m) pos.push_back(i);
	}
	int ret = INT32_MIN;
	for (int i = 0; i < pos.size(); i++) {
	 	int idx = pos[i];
	 	int temp = m;
	 	int left = idx-1;
	 	while (left >= 0 && A[left] > m) {
	 	 	temp += A[left];
	 	 	left--;
	 	}
	 	int right = idx+1;
	 	while (right < n && A[right] > m) {
	 	 	temp += A[right];
	 	 	right++;
	 	}
	 	ret = max(ret, temp);
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
