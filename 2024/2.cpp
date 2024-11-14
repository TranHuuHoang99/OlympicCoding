#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 151;
int matrix[N][N];
int n;

void solve(void) {
    cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> matrix[i][j];
		}
	}
	vector<int> check;
	int max_val = -1;
	for (int i = 0; i < n; i++) {
		int sum1 = 0;
		int sum2 = 0;
		for (int j = 0; j < n; j++) {
			sum1 += matrix[i][j];
			sum2 += matrix[j][i];
		}
		check.push_back(sum1);
		check.push_back(sum2);
		max_val = max(max_val, max(sum1, sum2));
	}
	for (int i = max_val; i <= 30000; i++) {
		int temp = 0;
		for (int j = 0; j < check.size(); j++) {
			temp += i - check[j];
		}
		if (temp % 2 == 0) {
			cout << temp / 2 << endl;
			return;
		}
	}
}
  
int32_t main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
	solve();
	
    return 0;
}

