#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 2e5+10;
ll cnt[N];
ll A[N];
int n;
bool visited[N];

void solve(void) {
	cin >> n;
	for (int i = 1; i <= n; i++) {
	 	cin >> A[i];
	 	cnt[A[i]]++;
	}
	for (int i = 1; i <= 2e5; i++) {
	 	cnt[i] += cnt[i-1];
	}
	ll ret = 0;
	for (int i = 1; i <= n; i++) {
		if (visited[A[i]]) continue;
		visited[A[i]] = true;
	 	int d = A[i];
	 	ll sum = 0;
	 	for (int j = d; j <= 2e5; j+=d) {
	 	 	if (j+d-1 <= 2e5) {
	 	 	 	sum += 1ll * (cnt[j+d-1] - cnt[j-1]) * j;
	 	 	} else {
	 	 	 	sum += 1ll * (cnt[200000] - cnt[j-1]) * j;
	 	 	}
	 	}
	 	ret = max(ret, sum);
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

