/*
**************************************************************************
  	author     : hoangprodn
  	email  	   : thhoang08091999@gmail.com
  	local time : 2025-08-15 21:42:56 
************************************************************************** 
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll MOD = 1e9+7;
const ll N = 1e6+10;
string A;
ll dp[N]; // goi dp la tong binh phuong substring khi ta co i chu so dau tien, gia su (123) = 3^2 + 23^2 + 123^2
ll sum_dp[N]; // tong substring khi ta co i chu so dau tien gia su (123) = 3 + 23 + 123

void solve(void) {
 	cin >> A;
 	int len = A.size();
 	A = " " + A;
 	// bai toan co so, khi ta khong co chu so nao trong day thi tong bang 0
 	dp[0] = 0ll;
 	for (int i = 1; i <= len; i++) {
 	 	dp[i] = (1ll * 100 % MOD * dp[i-1] % MOD) % MOD;
 	 	int temp = int(A[i]-'0');
 	 	dp[i] = (dp[i] % MOD + 1ll * 20 * temp * sum_dp[i-1] % MOD + 1ll * i * temp * temp % MOD) % MOD;
		sum_dp[i] = (1ll * 10 % MOD * sum_dp[i-1] % MOD) % MOD;
		sum_dp[i] = (sum_dp[i] % MOD + 1ll * i * temp % MOD) % MOD;
 	}
 	ll ret = 0ll;
 	for (int i = 1; i <= len; i++) {
 	 	ret = (ret % MOD + dp[i] % MOD) % MOD;
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

