/*
 ******************************************************************************************
 *      * AUTHOR : hoangprodn
 *      * CREATED: 06.01.2025 19:46:42
 ******************************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 1e5+1;
int A[N];
int n, m;

void solve(void) {
	while (cin >> n) {
	 	for (int i = 0; i < n; i++) {
	 	 	cin >> A[i];
	 	}
	 	sort(A,A+n);
	 	cin >> m;
	 	int left = 0;
	 	int right = n-1;
	 	int ret_left = 0;
	 	int ret_right = 0;
	 	while (left < right) {
	 	 	if (A[left] + A[right] < m) {
	 	 	 	left++;
	 	 	} else if (A[left]+A[right] == m) {
	 	 		ret_left = left;
	 	 		ret_right = right;
	 	 		left++;
	 	 		right--;
           } else {
				right--;
           }
	 	}
	 	cout << "Peter should buy books whose prices are" << " " << A[ret_left] << " and " << A[ret_right] << "." << endl;
	 	cout << endl;
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	solve();

	return 0;
}
