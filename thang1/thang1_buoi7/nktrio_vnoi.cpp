/*
 ******************************************************************************************
 *      * AUTHOR : hoangprodn
 *      * CREATED: 03.12.2024 22:01:15
 ******************************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 1e3+1;
int A[N][N];
int n;

void solve(void) {
	cin >> n;
	for (int i = 0; i < n; i++) {
	 	for (int j = 0; j < n; j++) {
	 	 	cin >> A[i][j];
	 	}
	}
	vector<bitset<1000>> win(n);
	vector<bitset<1000>> lose(n);	
	for (int i = 0; i < n; i++) {
	 	for (int j = 0; j < n; j++) {
	 	 	if (A[i][j]) {
	 	 	 	win[i].set(j,1);
	 	 	 	lose[j].set(i,1);
	 	 	}
	 	}
	}
	for (int i = 0; i < n; i++) {
	 	for (int j = 0; j < n; j++) {
	 	 	if (A[i][j]) {
	 	 	 	bitset<1000> temp = win[j] & lose[i];
				if (temp.count() > 0) {
					for (int k = 0; k < n; k++) {
					 	if (i != j && j != k && k != i && temp[k]) {
					 	 	cout << i+1 << ' ' << j+1 << ' ' << k+1 << endl;
					 	 	return; 
					 	}
				 	}
				}
	 	 	}
	 	}
	}
	cout << -1 << ' ' << -1 << ' ' << -1 << endl;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	solve();

	return 0;
}
