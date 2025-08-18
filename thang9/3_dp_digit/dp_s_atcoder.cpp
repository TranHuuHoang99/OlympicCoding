/*
**************************************************************************
  	author     : hoangprodn
  	email  	   : thhoang08091999@gmail.com
  	local time : 2025-08-15 20:22:39 
************************************************************************** 
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll M = 1e2+10;
const ll N = 1e4+10;
const ll MOD = 1e9+7;
ll D;
string A;
// goi dp la so luon cac so chia het cho D, khi ta co i chu so dau tien
// so khi co i chu so dau tien chia het cho D du r
// state la trang thai so hien tai so voi so trc do
// state == 0 so hien tai nho hon so co i chu so trc do
// state == 1 so hien tai bang so co i chu so trc do
// state == 2 so hien tai lon hon so co i chu so trc do
ll dp[N][M][3];

void solve(void) {
 	cin >> A;
 	cin >> D;
 	int len = A.size();
 	A = " " + A;
	// bai toan co so
	// khi ta co 1 chu so dau tien ta xet cac so tu 0->9 va so sanh voi chu so dau tien de lay dc state
	// vi chu so dau tien khong the bang 0 cho nen ta chi xet tu 1->9
	for (char c = '1'; c <= '9'; c++) {
	 	int state;
	 	if (c < A[1]) {
			state = 0;
	 	} else if (c == A[1]) {
			state = 1; 	 	
	 	} else {
	 	 	state = 2;
	 	}
	 	dp[1][int(c-'0') % D][state]++;
	}
	for (int i = 1; i < len; i++) {
	 	for (int remain = 0; remain < D; remain++) {
	 	 	for (int state = 0; state <= 2; state++) {
	 	 		if (dp[i][remain][state] == 0ll) continue;
	 	 	 	for (char c = '0'; c <= '9'; c++) {
	 	 	 		int nextState;
	 	 	 		if (state == 1) { // so hien tai dang bang voi so trong day thi ta can xet tiep cac so tu 0->9 voi  so i+1
 						// gia su hien tai ta dang la so 12 == 12 thi so tiep theo + vao chuoi phai so sanh voi so A[i+1]
 						if (c < A[i+1]) {
 						 	nextState = 0;
 						} else if (c == A[i+1]) {
 						 	nextState = 1;
 						} else {
 						 	nextState = 2;
 						}
	 	 	 		} else {
	 	 	 			// gia su hien tai ta dang xet so co 1 chu so la 9
	 	 	 			// truong hop state == 0, VD ta dang xet so 8 < 9
	 	 	 			// ta co the thay neu xet len so co 2 chu so, du 8 ghep voi so lon nhat la 9
	 	 	 			// va 9 ghep voi so nho nhat la 0
	 	 	 			// thi state tiep theo voi so co 2 chu so cung so la 0 (89 < 90)
	 	 	 			// tuong tu voi truong hop state == 2
	 	 	 		 	nextState = state;
	 	 	 		}
	 	 	 	 	(dp[i+1][(remain+int(c-'0')) % D][nextState] += dp[i][remain][state] % MOD) %= MOD;
	 	 	 	}
	 	 	}
	 	}
	}
	// dap an cua bai toan neu chuoi hien tai nho hon len thi ta se lay tong tu state 0->2
	// neu i hien tai == len thi ta se lay state 0 va 1
	ll ret = 0ll;
	for (int i = 1; i <= len; i++) {
	 	if (i < len) {
	 	 	for (int state = 0; state <= 2; state++) {
	 	 		// lay cac so co i chu so, chia het cho D bang 0, state 0->2
	 	 	 	ret = (ret % MOD + dp[i][0][state] % MOD) % MOD;
	 	 	}
	 	}  else {
	 	 	for (int state = 0; state <= 1; state++) {
	 	 	 	// vi i == len, nen ta chi lay cac so co state la 0 hoac 1
	 	 	 	ret = (ret % MOD + dp[i][0][state] % MOD) % MOD;
	 	 	}
	 	}
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

