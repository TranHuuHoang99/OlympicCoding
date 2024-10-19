#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 101;
int update[4][N];
int A[N];
string str[N];
string ret[N];
int n;

void solve(void) {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> A[i];
	for (int i = 1; i <= n; i++) cin >> str[i];

	iota(update[0]+1, update[0]+n+1, 1);
	for (int i = 1; i <= 3; i++) {
		for (int j =1 ; j <= n; j++) {
			update[i][A[j]] = update[i-1][j];
		}
	}

	for (int i = 1; i <= n; i++) {
		ret[update[3][i]] = str[i];
	}

	for (int i = 1; i <= n; i++) cout << ret[i] << endl;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen("shuffle.in", "r", stdin);
	freopen("shuffle.out", "w", stdout);

	solve();

	return 0;
}	



