#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 1e6+10;
const ll M = 1e3+10;
int n, m;
int A[N];
bool dp[M][M][2]; // i numbers, sum, state

void solve(void) {
	cin >> n >> m;
	if (n >= m) {
	 	cout << "YES" << endl;
	 	return;
	}
	for (int i = 1; i <= n; i++) cin >> A[i];
	dp[0][0][0] = true;
	for (int i = 0; i < n; i++) {
	    for (int j = 0; j <= m-1; j++) {
	     	for (int state = 0; state <= 1; state++) {
	     	 	if (dp[i][j][state] == true) {
	     	 	 	// truong hop khong cong i+1 vao day
	     	 	 	dp[i+1][j][state] = true;
	     	 	 	// truong hop cong i+1 vao day
	     	 	 	dp[i+1][(j+A[i+1])%m][1] = true;
	     	 	}
	     	}
	    }
	}	
	if (dp[n][0][1] == true) {
	 	cout << "YES" << endl;
	} else {
	 	cout << "NO" << endl;
    }                      
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	solve();

	return 0;
}

