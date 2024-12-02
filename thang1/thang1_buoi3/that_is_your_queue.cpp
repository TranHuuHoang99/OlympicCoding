#include <bits/stdc++.h>
#define ll long long

using namespace std;

char str;
ll val;

void solve(void) {
	ll p;
	ll c;
	int cnt = 1;
	while (cin >> p >> c) {
		if (p == 0 && c == 0) break;
		cout << "Case " << cnt << ":" << endl;
		cnt++;
		ll min_val = min(p, c);
		queue<ll> q;
		for (ll i = 1; i <= min_val; i++) q.push(i);
		for (int i = 0; i < c; i++) {
			cin >> str;
			if (str == 'N') {
				ll temp = q.front();
				cout << temp << endl;
				q.pop();
				q.push(temp);
			} else {
				cin >> val;
				queue<ll> temp;
				temp.push(val);
				while (!q.empty()) {
					if (q.front() == val) {
						q.pop();
						continue;
					}
					temp.push(q.front());
					q.pop();
				}
				q = temp;
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




