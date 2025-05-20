#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 3e5+10;
int n, q;
bool max_pos[N];
bool min_pos[N];

void solve(void) {
	cin >> n >> q;
	for (int i = 0; i <= n; i++) {
	 	max_pos[i] = min_pos[i] = false;
	}
	vector<ll> A;
	A.push_back(LLONG_MIN);
	for (int i = 1; i <= n; i++) {
	 	ll temp;
	 	cin >> temp;
	 	A.push_back(temp);
	}
	A.push_back(LLONG_MIN);
	ll ret = 0ll;
	for (int i = 1; i <= n; i++) {
	 	if (A[i] > A[i-1] && A[i] > A[i+1]) {
	 	 	ret += A[i];
	 	 	max_pos[i] = true;
	 	}
	 	if (A[i] < A[i-1] && A[i] < A[i+1]) {
	 	  	ret -= A[i];
	 	  	min_pos[i] = true;
	 	}
	}
	cout << ret << endl;
	for (int i = 1; i <= q; i++) {
		int a, b;
		cin >> a >> b;
		vector<int> temp;
		if (a == b) {
		 	if (max_pos[a] == true) {
		 	    ret -= A[a];
		 	    max_pos[a] = false;
		 	}
		 	if (min_pos[a] == true) {
		 	 	ret += A[a];
		 	 	min_pos[a] = false;
			}
		} else () {
		 	
		}
	 	swap(A[a], A[b]);
	 	for (int j = 0; j < temp.size(); j++) {
	 	 	int idx = temp[j];
	 	 	if (idx >= 1 && idx <= n) {
	 	 	 	if (A[idx] > A[idx-1] && A[idx] > A[idx+1]) {
	 	 	 	 	ret += A[idx];
	 	 	 	 	max_pos[idx] = true;
	 	 	 	}
	 	 	 	if (A[idx] < A[idx-1] && A[idx] < A[idx+1]) {
	 	 	 	 	ret -= A[idx];
	 	 	 	 	min_pos[idx] = true;
	 	 	 	}
	 	 	}
	 	}
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
	for (int i = 1; i <= t; i++) {
	 	solve();
	}

	return 0;
}

