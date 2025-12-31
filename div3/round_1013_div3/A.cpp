/*
 ******************************************************************************************
 *      * AUTHOR : hoangprodn
 *      * CREATED: 31.03.2025 23:15:41
 ******************************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int A[30];
int n;
int cnt[10];
int numb[5] = {0,1,2,3,5};
int match[5] = {3,1,2,1,1};

void solve(void) {
	memset(cnt,0,sizeof(cnt));
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> A[i];
	for (int i = 1; i <= n; i++) {
		cnt[A[i]]++;
		bool isValid = true;
		for (int j = 0; j < 5; j++) {
			if (cnt[numb[j]] < match[j]) {
			 	isValid = false;
			 	break;
			}
		}
		if (isValid) {
		 	cout << i << endl;
		 	return;
		}
	}
	cout << 0 << endl;
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
