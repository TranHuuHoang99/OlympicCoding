#include <bits/stdc++.h>
#define ll long long

using namespace std;

set<ll> check;

void solve(void) {
	int n;
	cin >> n;
	priority_queue<ll,vector<ll>,greater<ll>> q;
	vector<ll> ret;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		if (a == 1) {
			ll b;
			cin >> b;
			q.push(b);
		} else if (a == 2) {
			ll b;
			cin >> b;
			check.insert(b);
		} else {
			while (!q.empty()) {
				if (!check.count(q.top())) {
					cout << q.top() << endl;
					break;
				} else {
					q.pop();
				}
			}
		}
	}
}
  
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
	solve();	
	
    return 0;
}


