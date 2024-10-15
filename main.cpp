#include <bits/stdc++.h>
#define ll long long

using namespace std;

<<<<<<< Updated upstream
const ll N = 1e5+1;
vector<int> A[N];
int topo[N];
int n, m;

void solve(void) {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		A[a].push_back(b);
		topo[b]++;
	}

	vector<int> track(n+1, -1);
	queue<int> q;
	track[1] = -1;
	for (int i = 2; i <= n; i++) if (topo[i] == 0) q.push(i);

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int next : A[cur]) {
			topo[next]--;
			if (topo[next] == 0) {
				if (next == 1) continue;
				q.push(next);
				track[next] = cur;
			}
		}
	}

	if (track[n] != -1) {
		cout << "IMPOSSIBLE" << endl;
	} else {
		q.push(1);
		while (!q.empty()) {
			int cur = q.front();
			q.pop();
			for (int next : A[cur]) {
				topo[next]--;
				if (topo[next] == 0) {
					q.push(next);
					track[next] = cur;
				}
			}
		}

		if (track[n] == -1) {
			cout << "IMPOSSIBLE" << endl;
			return;
		}

		stack<int> ret;
		int temp = n;
		while (temp != -1) {
			ret.push(temp);
			temp = track[temp];
		}

		cout << ret.size() << endl;
		while (!ret.empty()) {
			cout << ret.top() << ' ';
			ret.pop();
		}
		cout << endl;	
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();	

	return 0;
=======
const ll MOD = 1e9+7;

ll power(ll a, ll b) {
	ll ret = 1;
	while (b) {
		if (b & 1) ret = ret * a % MOD;
		a = a * a % MOD;
		b >>= 1;
	}
	return ret;
}

void solve(void) {
	ll numb = 1, sum = 1, pro = 1, count = 1;
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		ll a, b;
		cin >> a >> b;
		numb = numb * (b+1) % MOD;

		sum = (sum * (power(a, b+1)-1) % MOD * power(a-1, MOD-2) % MOD) % MOD;
		pro = power(pro, b+1) * power(power(a, b*(b+1)/2), count) % MOD;
		count = count * (b+1) % (MOD-1);
	}

	cout << numb << ' ' << sum << ' ' << pro << endl;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //freopen("CAU1.inp", "r", stdin);
    //freopen("CAU1.out", "w", stdout);

    solve();

    return 0;
>>>>>>> Stashed changes
}

