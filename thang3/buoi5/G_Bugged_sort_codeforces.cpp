/*
 ******************************************************************************************
 *      * AUTHOR : hoangprodn
 *      * CREATED: 21.01.2025 20:25:35
 ******************************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 2e5+1;
pair<int,int> A[N];
int n;
/*
  	initialize dp array:
  	- First array is the number from 1 -> n
  	- Second array is having a flipped event or not, if is having a flipped and wait for next flipped to close -> 1, otherwise -> 0
  	- Third array is current State flipped or not, 1 is flipped, 0 is not 
  	- The answer if after went through n number and current state is not flipped and next flipped could be 1 or 0
*/
bool dp[N][2][2];

bool cmp(pair<int,int> a, pair<int,int> b) {
 	return min(a.first, a.second) < min(b.first, b.second);
}

void solve(void) {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> A[i].first;
	for (int i = 1; i <= n; i++) cin >> A[i].second;
 	sort(A+1,A+1+n,cmp);
	for (int i = 0; i <= n; i++) {
	    for (int flipped = 0; flipped <= 1; flipped++) {
	     	for (int curState = 0; curState <= 1; curState++) {
	     	    dp[i][flipped][curState] = false;
	     	}	
	    }
	}
	// if n == 1 -> then we create initial array with 1 is true
	dp[1][0][0] = true;
	dp[1][1][1] = true;
	for (int i = 1; i < n; i++) {
	 	for (int flipped = 0; flipped <= 1; flipped++) {
	 	 	for (int curState = 0; curState <= 1; curState++) {
	 	 	 	if (dp[i][flipped][curState] == false) continue;
				if (curState == 0) { // the current State is flipped
					// we keep next event not flipped
					if (A[i].first < A[i+1].first && A[i].second < A[i+1].second) {
					 	dp[i+1][flipped][0] = true;
					}
					// we flipped next event and if having a flipped event so we close it or open new
					if (A[i].first < A[i+1].second && A[i].second < A[i+1].first) {
						dp[i+1][1-flipped][1] = true;				 	
					}
				} else {
				 	// we keep next event not flipped
				 	if (A[i].second < A[i+1].first && A[i].first < A[i+1].second) {
				 	 	dp[i+1][flipped][0] = true;
				 	}
				 	// we flipped next event
				 	if (A[i].first < A[i+1].first && A[i].second < A[i+1].second) {
				 	 	dp[i+1][1-flipped][1] = true;
				 	}
				}
	 	 	}
	 	}
	}
	if (dp[n][0][0] || dp[n][0][1]) {
	 	cout << "yes" << endl;
	} else {
	 	cout << "no" << endl;
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

	int t;
	cin >> t;
	while (t--) {
	 	solve();
	}

	return 0;
}
