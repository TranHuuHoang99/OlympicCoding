#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 1001;
int A[N];

void solve(void) {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> A[i];

	int ret = INT32_MAX;
	for (int i = 0; i < n; i++) {
		int plus = 0;
		int j = i;
		int sum = 0;
		while (j < n) {
			sum += A[j] * plus;
			plus++;
			j++;
		}
		int k = 0;
		while (k < i) {
			sum += A[k] * plus;
			plus++;
			k++;
		}

		ret = min(ret, sum);
	}

	cout << ret << endl;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen("cbarn.in", "r", stdin);
	freopen("cbarn.out", "w", stdout);

	solve();

	return 0;
}	



