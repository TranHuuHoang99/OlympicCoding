#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 1e6+10;
int n;
int A[N];

int calMod(int a, int b) {
 	return (a % b) + (b % a);
}

void solve(void) {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> A[i];
	int min_val = A[1];
	int ret = 0;
	for (int i = 1; i <= n; i++) {
	    ret = max(ret, calMod(A[i],min_val));
	    if (A[i] > min_val) {
	     	if (A[i] >= 2 * min_val) {
	     	 	for (int j = 1; j < i; j++) {
	     	 	 	ret = max(ret, calMod(A[i],A[j]));
	     	 	}
	     	} else {
	     	 	ret = A[i];
	     	}
	     	min_val = A[i];
	    }
	    cout << ret << ' ';
	}
	cout << endl;	
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
 