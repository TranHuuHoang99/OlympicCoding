/*
 ******************************************************************************************
 *      * AUTHOR : hoangprodn
 *      * CREATED: 24.01.2025 19:36:04
 ******************************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 7e4+1000;
const ll max_len = 7e4;
int cost;                   
int A[9], B[9];
int deno[9] = {1,2,5,10,20,50,100,200,500};
int dp_pay[10][N];
int dp_back[10][N];

void update_pay(void) {
 	for (int i = 0; i <= 9; i++) {
 	 	for (int j = 0; j <= max_len; j++) {
 	 	 	dp_pay[i][j] = -1;
 	 	}
 	}
 	dp_pay[0][0] = 0;
 	for (int i = 0; i < 9; i++) {
 	 	for (int j = 0; j <= max_len; j++) {
 	 	 	if (dp_pay[i][j] == -1) continue;
 	 	 	for (int numb = 0; numb <= A[i]; numb++) {
 	 	 	 	dp_pay[i+1][j+numb*deno[i]] = max(dp_pay[i+1][j+numb*deno[i]], dp_pay[i][j] + numb);
 	 	 	}
 	 	}
 	}
}

void update_back(void) {
 	for (int i = 0; i <= 9; i++) {
 	 	for (int j = 0; j <= max_len; j++) {
 	 	 	dp_back[i][j] = INT32_MAX;
 	 	}
 	}
 	dp_back[0][0] = 0;
 	for (int i = 0; i < 9; i++) {
 	 	for (int j = 0; j <= max_len; j++) {
 	 	 	if (dp_back[i][j] == INT32_MAX) continue;
 	 	 	for (int numb = 0; numb <= B[i]; numb++) {
 	 	 	 	dp_back[i+1][j+numb*deno[i]] = min(dp_back[i+1][j+numb*deno[i]], dp_back[i][j] + numb);
 	 	 	}
 	 	}
 	}
}

void solve(void) {
	cin >> cost;
	cost /= 1000;
	for (int i = 0; i < 9; i++) {
	 	string str;
	 	cin >> str;
	 	cin >> A[i] >> B[i];
	}
	update_pay();
	update_back();
	int sum = 0;
	for (int i = 0; i < 9; i++) {
	 	sum += A[i];
	}
	int ret = INT32_MAX;
	for (int i = cost; i <= max_len; i++) {
	 	if (dp_pay[9][i] != -1 && dp_back[9][i-cost] != INT32_MAX) {
	 	 	ret = min(ret, sum - dp_pay[9][i] + dp_back[9][i-cost]); 
	 	}
	}
	if (ret == INT32_MAX) {
	 	cout << "SORRY!!!" << endl;
	 	return;
	}
	cout << ret << endl;
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
	for (int i = 1; i <= t; i++) {
		solve();
	}

	return 0;
}
