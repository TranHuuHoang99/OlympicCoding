/*
**************************************************************************
  	author     : hoangprodn
  	email  	   : thhoang08091999@gmail.com
  	local time : 2025-11-22 15:19:42 
************************************************************************** 
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll N = 2e5+10;
bool visited[N];
int A[N];
int n;
void solve(void) {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> A[i];
	memset(visited, 0, sizeof(visited));
	int cur_or = 0;
	for (int i = 0; i < min(31, n); i++) {
	 	int max_val = 0;
	 	int idx = -1;
	 	for (int j = 1; j <= n; j++) {
	 	 	if (visited[j]) continue;
	 	 	if ((cur_or | A[j]) > max_val) {
	 	 	 	max_val = cur_or | A[j];
	 	 	 	idx = j;
	 	 	}
	 	}
	 	visited[idx] = true;
	 	cout << A[idx] << ' ';
	 	cur_or |= A[idx];
	}
	for (int i = 1; i <= n; i++) {
	 	if (!visited[i]) cout << A[i] << ' ';
	}
	cout << endl;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
	 	solve();
	}
	return 0;
}

