/*
 ******************************************************************************************
 *      * AUTHOR : hoangprodn
 *      * CREATED: 24.12.2024 19:59:06
 ******************************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 1e5+1;
int n;

void solve(void) {
	cin >> n;
	multiset<int> A;
	multiset<int> B;
	for (int i = 0; i < n; i++) {
	 	int temp;
	 	cin >> temp;
	 	A.insert(temp);
	}
	for (int i = 0; i < n; i++) {
	 	int temp;
	 	cin >> temp;
	 	B.insert(temp);
	}
	int ret = 0;
	while (!A.empty() && !B.empty()) {
		int max_val = max(*A.begin(), *B.begin());
		ret++;
		while (!A.empty() && *A.begin() <= max_val) A.erase(A.begin());
		while (!B.empty() && *B.begin() <= max_val) B.erase(B.begin());
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
