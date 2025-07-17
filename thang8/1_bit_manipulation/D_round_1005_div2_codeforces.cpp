#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 2e5+10;
int n, q;
int W[N];
int suffixXor[N];
int dp[N][32]; // voi 1 vi tri i, goi dp[i][b] la vi tri j gan vi tri i nhat, tinh ve phia ben trai sao cho tu bit b -> bit 29, phai co bit = 1
int maxPos[32];

void solve(void) {
 	cin >> n >> q;
 	for (int i = 1; i <= n; i++) cin >> W[i];
 	suffixXor[n+1] = 0;
 	for (int i = n; i >= 1; i--) {
 	 	suffixXor[i] = suffixXor[i+1] ^ W[i];
 	}
	for (int i = 0; i <= 31; i++) maxPos[i] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 31; j >= 0; j--) {
		 	int temp = 0;
		 	for (int biggerBit = j; biggerBit <= 31; biggerBit++) {
		 	 	temp = max(temp, maxPos[biggerBit]);
		 	}
		 	dp[i][j] = temp+1;
		}
		for (int j = 31; j >= 0; j--) {
		 	if (W[i] & (1 << j)) {
		 	 	maxPos[j] = i;
		 	 	break;
		 	}
		}
	}
	for (int i = 1; i <= q; i++) {
	 	int x;
	 	cin >> x;
	 	int position = n+1;
	 	while (true) {
	 	 	if (position == 1) break;
	 	 	int lastBit = -1;
	 	 	for (int j = 31; j >= 0; j--) {
	 	 	 	if (x & (1 << j)) {
	 	 	 	 	lastBit = j;
	 	 	 	 	break;
	 	 	 	}
	 	 	}
	 	 	if (lastBit == -1) break;
	 	 	if (x < W[position-1]) break;
	 	 	position--;
	 	 	x ^= W[position];
	 	 	lastBit = -1;
			for (int j = 31; j >= 0; j--) {
			 	if (x & (1 << j)) {
			 	 	lastBit = j;
			 	 	break;
			 	}
			}
			if (lastBit == -1) break;
			// set value x to be 0
			x ^= suffixXor[position];
			position = dp[position][lastBit];
			// xor all the value back in the array
			x ^= suffixXor[position];
	 	}
	 	cout << n - position + 1 << ' ';
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

