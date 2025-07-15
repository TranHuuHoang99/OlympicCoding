#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 1e5+10;
int n;
int A[N];
set<int> cur, ret;

void solve(void) {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> A[i];
	for (int i = 1; i <= n; i++) {
		cur.insert(0);
		set<int> temp;
		for (int e : cur) {
		    ret.insert(A[i] | e);
		  	temp.insert(A[i] | e);
		}	
		cur = temp;
	}	
	cout << ret.size() << endl;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
#ifdef HOANGPRODN_DEBUG
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
#endif // HOANGPRODN_DEBUG
	solve();
	return 0;
}

