#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 5000+1;
int n,m,a,b;
ll c;
tuple<int,int,ll> tp[N];

void solve(void) {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		--a; --b;
		tp[i] = {a,b,c};
	}

	vector<ll> update(n, 1e18);
	update[0] = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			tie(a,b,c) = tp[j];
			update[b] = min(update[b], update[a] + c);
		}
	}

	bool isValid = false;
	for (int i = 0; i < m; i++) {
		tie(a,b,c) = tp[i];
		if (update[b] > update[a] + c) {
			isValid = true;
			break;
		}
	}

	if (!isValid) {
		cout << "NO" << endl;
		return;
	}

	cout << "YES" << endl;
	int start = -1;
	vector<int> change(n, -1);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			tie(a,b,c) = tp[j];
			if (update[b] > update[a] + c) {
				update[b] = update[a] + c;
				change[b] = a;
				start = b;
			}
		}
	}

	for (int i = 0; i < change.size(); i++) start = change[start];
	int cur = start;
	stack<int> st;
	do {
		st.push(cur);
		cur = change[cur];
	} while (cur != start);

	st.push(cur);
	while (!st.empty()) {
		cout << st.top() + 1 << ' ';
		st.pop();
	}
	cout << endl;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();	

	return 0;
}
