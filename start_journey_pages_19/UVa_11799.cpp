#include <bits/stdc++.h>
#define ll long long

using namespace std;

int solve(void) {
	int n;
	cin >> n;
	int ret = INT32_MIN;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		ret = max(ret, temp);
	}
	return ret;	
}
  
int32_t main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL); 

	int t;
	cin >> t;
	int temp = t;
	while (t--) {
		printf("Case %d: %d\n",temp-t, solve());
	}

    return 0;
}




