#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 6e4+10;
int n;
int A[N];
int fw[N];

void update_fw(int pos, int val) {
	for (int i = pos; i <= 6e4; i += i&-i) {
	 	fw[i] += val;
	}
}

int get_fw(int pos) {
 	int ret = 0;
 	for (int i = pos; i > 0; i -= i&-i) {
 	 	ret += fw[i];
	}
	return ret;
}

void solve(void) {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> A[i];
	int ret = 0;
	for (int i = n; i >= 1; i--) {
		ret += get_fw(A[i]-1);
		update_fw(A[i], 1); 	
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


