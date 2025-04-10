/*
 ******************************************************************************************
 *      * AUTHOR : hoangprodn
 *      * CREATED: 08.04.2025 19:32:17
 ******************************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 2e5+10;
int n, m, k;
int A[N], B[N];
int cntBoy[N], cntGirl[N];

void solve(void) {
	memset(A,0,sizeof(A));
	memset(B,0,sizeof(B));
	memset(cntBoy,0,sizeof(cntBoy));
	memset(cntGirl,0,sizeof(cntGirl));
	cin >> n >> m >> k;
	for (int i = 1; i <= k; i++) cin >> A[i];
	for (int i = 1; i <= k; i++) cin >> B[i];
	int ret = 0;
	for (int i = 1; i <= k; i++) {
	 	int invalid = cntBoy[A[i]] + cntGirl[B[i]];
	 	ret += i - 1 - invalid;
	 	cntBoy[A[i]]++;
	 	cntGirl[B[i]]++;
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
