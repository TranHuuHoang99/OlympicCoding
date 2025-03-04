/*
 ******************************************************************************************
 *      * AUTHOR : hoangprodn
 *      * CREATED: 27.02.2025 21:52:07
 ******************************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 30;
int A[N];
int n;
string str;

void solve(void) {
	memset(A,0,sizeof(A));
	cin >> n >> str;
	for (int i = 0; i < str.size(); i++) {
	 	int idx = int(str[i]-'A');
	 	if (A[idx] == 0) {
	 	 	A[idx] += 2;
	 	} else {
	 	 	A[idx]++;
	 	}
	}
	int ret = 0;
	for (int i = 0; i < 30; i++) ret += A[i];
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
