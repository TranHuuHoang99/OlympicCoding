#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 1e6+10;
int n, q;
ll A[N];
ll prefix[N];
unordered_map<ll,int> mp;
int dp[N][20]; // vi tri left gan voi i nhat sao cho, co 2^j so luong doan con co tong la 0

void solve(void) {
 	scanf("%d %d", &n, &q);
 	for (int i = 1; i <= n; i++) {
 	    scanf("%lld", &A[i]);
 	    prefix[i] = prefix[i-1] + A[i];
 	}
 	for (int j = 0; j <= 18; j++) {
 	 	for (int i = 0; i <= n; i++) {
 	 	 	dp[i][j] = -1;
 	 	}
 	}
 	dp[0][0] = 0;
 	mp[prefix[0]] = 0;
 	for (int i = 1; i <= n; i++) {
 	 	// truong hop 1 : ta khong chap nhan phan tu i vao tong
 	 	dp[i][0] = dp[i-1][0];
 	 	// truong hop 2 : ta chap nhan phan tu i vao tong
 	 	if (mp.find(prefix[i]) != mp.end()) {
 	 	 	dp[i][0] = max(dp[i][0], mp[prefix[i]]+1);
 	 	}
 	 	mp[prefix[i]] = i;
	}
	for (int j = 1; j <= 18; j++) {
	 	for (int i = 1; i <= n; i++) {
			if (dp[i][j-1] != -1) {
			 	int prevPos = dp[i][j-1] - 1;
			 	if (prevPos >= 0 && dp[prevPos][j-1] != -1) {
			 	 	dp[i][j] = dp[prevPos][j-1];
			 	}
			}
	 	}
	}
	for (int i = 1; i <= q; i++) {
	 	int left, right;
	 	scanf("%d %d", &left, &right);
	 	int curRight = right;
	 	int ret = 0;
	 	for (int j = 18; j >= 0; j--) {
			if (dp[curRight][j] != -1 && dp[curRight][j] >= left) {
			 	ret += (1 << j);
			 	curRight = dp[curRight][j] - 1;
			 	if (curRight < left) break;
			}
	 	}
	 	printf("%d\n", ret);
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
	solve();
	return 0;
}

