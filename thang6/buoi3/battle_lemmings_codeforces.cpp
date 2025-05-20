#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 82;
const ll M = N * (N-1) / 2 + 10;
int n;
int A[N];
int dp[2][N][M]; // i, total zeros, number of swaps
int prefixSum[N];

void solve(void) {
	cin >> n;
	int k = n * (n-1) / 2;
	for (int i = 1; i <= n; i++) cin >> A[i];
	A[0] = 1;
	A[n+1] = 1;
	vector<int> groupZeros;
	int lastPos = 0;
	for (int i = 1; i <= n+1; i++) {
	 	if (A[i] == 1) {
	 	 	groupZeros.push_back(i-lastPos-1);
	 	 	lastPos = i;
	 	}
	}
	int len = groupZeros.size();
	for (int i = 1; i <= len; i++) {
	 	prefixSum[i] = prefixSum[i-1] + groupZeros[i-1];
	}
	int totalZeros = prefixSum[len];
	for (int i = 0; i <= 1; i++) {
	    for (int curZeros = 0; curZeros <= totalZeros; curZeros++) {
	        for (int curSwaps = 0; curSwaps <= k; curSwaps++) {
	         	dp[i][curZeros][curSwaps] = INT32_MAX;
	        }
	    }	
	}	
	dp[0][0][0] = 0;
	for (int i = 0; i < len; i++) {
	 	int cur = i&1;
	 	int next = !cur;
	 	for (int curZeros = 0; curZeros <= totalZeros; curZeros++) {
	 		for (int curSwaps = 0; curSwaps <= k; curSwaps++) {
	 		 	dp[next][curZeros][curSwaps] = INT32_MAX;
	 		}
	   	}
	   	for (int curZeros = 0; curZeros <= totalZeros; curZeros++) {
			for (int curSwaps = 0; curSwaps <= k; curSwaps++) {
			 	if (dp[cur][curZeros][curSwaps] == INT32_MAX) continue;
			 	for (int addedZeros = 0; addedZeros + curZeros <= totalZeros; addedZeros++) {
			 	 	int nextSwaps = curSwaps + abs(prefixSum[i+1] - addedZeros - curZeros);
			 	 	if (nextSwaps > k) continue;
			 	 	dp[next][addedZeros+curZeros][nextSwaps] = min(dp[next][addedZeros+curZeros][nextSwaps], dp[cur][curZeros][curSwaps] + addedZeros * addedZeros);
			 	}
			}
	   	}
	}
	int ret = INT32_MAX;
	for (int totalSwaps = 0; totalSwaps <= k; totalSwaps++) {
	 	ret = min(ret, dp[len&1][totalZeros][totalSwaps]);
	 	cout << (totalZeros * totalZeros - ret) / 2 << ' ';
	}
	cout << endl;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	solve();

	return 0;
}

