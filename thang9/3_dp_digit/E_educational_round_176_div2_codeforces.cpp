/*
**************************************************************************
  	author     : hoangprodn
  	email  	   : thhoang08091999@gmail.com
  	local time : 2025-08-20 22:59:19 
************************************************************************** 
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll MOD = 998244353;
const ll LEN = 35; // maximum number of bit 2^29-1
ll N, M, A, B;
// goi bai toan dp la tong so cach tao ra a1, a1, b1, b2 sao cho (a1 ^ b1 == a2 ^ b2), khi ta co i bit dau tien
// 4 mang tiep theo bao gom
// state = 0 (a1 < a2), state = 1 (a1 == a2)
// state = 0 (a2 < A), state = 1 (a2 == A)
// state = 0 (b1 < b2), state = 1 (b1 == b2)
// state = 0 (b2 < B), state = 1 (b2 == B)
ll dp[LEN][2][2][2][2];

ll fast_power(ll a, ll b) {
 	ll ret = 1ll;
 	while (b) {
 	 	if (b&1) ret = (ret % MOD * a % MOD) % MOD;
 	 	a = (a % MOD * a % MOD) % MOD;
 	 	b >>= 1;
 	}
	return ret;
}

void solve(void) {
 	cin >> N >> M >> A >> B;
 	memset(dp, 0ll, sizeof(dp));
 	ll ret = 0ll;
 	ret = (ret % MOD + (1ll * (A+1) % MOD * 1ll * (B+1) % MOD) % MOD) % MOD;
 	ll mul = 1ll * (A+1);
 	mul = (mul % MOD * 1ll * B % MOD) % MOD;
 	mul = (mul % MOD * 1ll * (B+1) % MOD) % MOD;
 	mul = (mul % MOD * fast_power(1ll*2, MOD-2) % MOD) % MOD;
 	mul = (mul % MOD * (fast_power(1ll*2, M) - 2ll + MOD) % MOD) % MOD;
 	ret = (ret % MOD + mul % MOD) % MOD;
 	mul = 1ll * (B+1);
 	mul = (mul % MOD * 1ll * A % MOD) % MOD;
 	mul = (mul % MOD * 1ll * (A+1) % MOD) % MOD;
 	mul = (mul % MOD * fast_power(1ll*2, MOD-2) % MOD) % MOD;
 	mul = (mul % MOD * (fast_power(1ll*2, N) - 2ll + MOD) % MOD) % MOD;
 	ret = (ret % MOD + mul % MOD) % MOD;
 	// bai toan co so khi tao khong co bit nao va a1 = a2 va b1 = b2
 	dp[0][1][1][1][1] = 1ll;
 	for (int i = 0; i < 30; i++) {
 	 	for (int state1 = 0; state1 <= 1; state1++) {
 	 	 	for (int state2 = 0; state2 <= 1; state2++) {
 	 	 	 	for (int state3 = 0; state3 <= 1; state3++) {
 	 	 	 	 	for (int state4 = 0; state4 <= 1; state4++) {
 	 	 	 	 	 	if (dp[i][state1][state2][state3][state4] <= 0) continue;
						bool bita = (A&(1 << (29-i)));
						bool bitb = (B&(1 << (29-i)));
						for (int bit1 = 0; bit1 <= 1; bit1++) {
						    for (int bit2 = 0; bit2 <= 1; bit2++) {
						     	for (int bit3 = 0; bit3 <= 1; bit3++) {
						     	 	for (int bit4 = 0; bit4 <= 1; bit4++) {
										if ((bit1 ^ bit3) != (bit2 ^ bit4)) continue;
										if (state1 == 1 && bit1 > bit2) continue;
										if (state2 == 1 && bit2 > bita) continue;
										if (state3 == 1 && bit3 > bit4) continue;
										if (state4 == 1 && bit4 > bitb) continue;
										int nextState1 = state1;
										if (state1 == 1 && bit1 < bit2) nextState1 = 0;
										int nextState2 = state2;
										if (state2 == 1 && bit2 < bita) nextState2 = 0;
										int nextState3 = state3;
										if (state3 == 1 && bit3 < bit4) nextState3 = 0;
										int nextState4 = state4;
										if (state4 == 1 && bit4 < bitb) nextState4 = 0;
										(dp[i+1][nextState1][nextState2][nextState3][nextState4] += dp[i][state1][state2][state3][state4]) %= MOD;
						     	 	}
						     	}
						    }
						}	
 	 	 	 	 	}
 	 	 	 	}
 	 	 	}
 	 	}
	}
	ll k = 0ll;
	for (int state2 = 0; state2 <= 1; state2++) {
	 	for (int state4 = 0; state4 <= 1; state4++) {
	 	 	k = (k % MOD + dp[30][0][state2][0][state4] % MOD) % MOD;
	 	}
	}
	ret = (ret % MOD + (k % MOD * (fast_power(1ll*2, N) - 2ll + MOD) % MOD * (fast_power(1ll*2, M) - 2ll + MOD) % MOD) % MOD) % MOD;
	cout << ret << endl;
}	

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
	 	solve();
	}
	return 0;
}










