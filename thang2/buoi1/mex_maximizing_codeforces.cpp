/*
 ******************************************************************************************
 *      * AUTHOR : hoangprodn
 *      * CREATED: 04.12.2024 19:57:06
 ******************************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 4e5+1;
int A[N];
int q, x;
int cnt = 0;

void solve(void) {
	cin >> q >> x;
	for (int i = 0; i < q; i++) {
	 	int temp;
	 	cin >> temp;
	 	A[temp%x]++;
	 	while (true) {
	 	 	if (A[cnt%x] > 0) {
	 	 	 	A[cnt%x]--;
	 	 	 	cnt++;
	 	 	} else {
				break;
	 	 	}
	 	}
	 	cout << cnt << endl;
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	solve();

	return 0;
}
