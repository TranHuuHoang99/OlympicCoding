#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 1e6+10;
int n, q;
ll prefix[N];
int dp[N][20]; // xet vi tri left gan sao cho tu left -> i, co the tao thanh 2^j doan
unordered_map<ll, int> um;

void solve(void) {
 	scanf("%d %d", &n, &q);
 	for (int i = 1; i <= n; i++) {
 	    scanf("%lld", &prefix[i]); 
 	    prefix[i] += prefix[i-1];
 	}
 	for (int i = 0; i <= n; i++) {
 	    for (int j = 0; j <= 18; j++) {
 	     	dp[i][j] = -1;
 	    }
 	}	
 	dp[0][0] = 0;
 	um[prefix[0]] = 0;	
 	for (int i = 1; i <= n; i++) {
 	 	// ta khong chap nhan vi tri i vao doan con
 	 	dp[i][0] = dp[i-1][0];
 	 	if (um.find(prefix[i]) != um.end()) {
 	 	 	dp[i][0] = max(dp[i][0], um[prefix[i]]+1);
 	 	}
 	 	um[prefix[i]] = i;
 	}
 	for (int j = 1; j <= 18; j++) {
 	    for (int i = 1; i <= n; i++) {
 	     	// gia su j = 1 -> 2^1 = 2
 	     	// tu diem i ta can tim vi tri mid co the tao thanh 2^j-1 doan con -> 2^0 = 1 doan con
 	     	// sau khi tim dc vi tri mid ta tiep tuc xet tiep vi tri truoc do la mid-1
 	     	// tu diem mid - 1 ta can tim vi tri left co the tao thanh 2^0 = 1 doan con
 	     	// left, ......, mid - 1, mid, .........., i
 	     	if (dp[i][j-1] != -1) { // tim vi tri mid
 	     	 	int midPos = dp[i][j-1] - 1; // sau khi tim dc thi tim vi tri trc do
 	     	 	if (midPos >= 0 && dp[midPos][j-1] != -1) { // tim vi tri left
					dp[i][j] = dp[midPos][j-1];
 	     	 	}
 	     	}
 	    }
 	}	
 	for (int i = 1; i <= q; i++) {
 	    int left, right;
 	    scanf("%d %d", &left, &right);
 	    // ta can tim tu vi tri right nguoc ve left
 	    int curRight = right;
 	    int ret = 0;
 	   	for (int j = 18; j >= 0; j--) {
 	   	 	if (dp[curRight][j] != -1 && dp[curRight][j] >= left) {
 	   	 	 	ret += (1 << j);
 	   	 	 	curRight = dp[curRight][j] - 1; // xet vi tri trc do
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

