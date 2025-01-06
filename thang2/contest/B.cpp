/*
 ******************************************************************************************
 *      * AUTHOR : hoangprodn
 *      * CREATED: 06.01.2025 19:59:04
 ******************************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 1e3+1;
int A[N];

void solve(void) {
	int n;
	int cnt = 1;
	while (cin >> n && n != 0) {
		 memset(A,0,sizeof(A));
	 	 for (int i = 0; i < n; i++) cin >> A[i];
	 	 vector<int> arr;
	 	 for (int i = 0; i < n; i++) {
	 	  	for (int j = i+1; j < n; j++) {
	 	  	 	arr.push_back(A[i]+A[j]);
	 	  	}
	 	 }
	 	 sort(arr.begin(), arr.end());
		 int m;
	 	 cin >> m;
		 cout << "Case " << cnt << ":" << endl;
		 for (int i = 0; i < m; i++) {
		 	int temp;
		 	cin >> temp;
		 	int ret = 0;
		 	auto it = lower_bound(arr.begin(), arr.end(), temp);
		 	if (it == arr.end()) {
		 	 	--it;
		 	 	ret = *it;
		 	} else if (it == arr.begin()) {
		 		ret = *it;
		 	} else {
				int temp1 = *it;
				--it;
				int temp2 = *it;
				if (abs(temp1-temp) < abs(temp2-temp)) {
				 	ret = temp1;
				} else {
				 	ret = temp2;
				}
         	}
		 	cout << "Closest sum to " << temp << " is " << ret << "." << endl;
		 }
		 cnt++;
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
