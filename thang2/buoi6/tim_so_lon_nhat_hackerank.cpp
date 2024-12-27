/*
 ******************************************************************************************
 *      * AUTHOR : hoangprodn
 *      * CREATED: 27.12.2024 20:28:41
 ******************************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int n;
vector<int> arr;

int rc(int next) {
 	if (next == 0) return arr[0];
 	return max(rc(next-1), arr[next]);
}

void solve(void) {
 	cin >> n;
 	for (int i = 0; i < n; i++) {
 	 	int temp;
 	 	cin >> temp;
 	 	arr.push_back(temp);
	}
	cout << rc(arr.size()-1) << endl;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	solve();

	return 0;
}
