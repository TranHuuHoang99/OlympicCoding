#include <bits/stdc++.h>
#define ll long long

using namespace std;

int A[60][60];
int R, C, D, W;

void solve(void) {
	cin >> R >> C >> D >> W;
	for (int i = 1; i <= R; i++) {
	 	for (int j = 1; j <= C; j++) cin >> A[i][j];
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	solve();

	return 0;
}

