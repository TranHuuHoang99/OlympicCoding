#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve(void) {
	int n;
	while (cin >> n && n != 0) {
		priority_queue<int,vector<int>, greater<int>> q;
		for (int i = 0; i < n; i++) {
			int temp;
			cin >> temp;
			q.push(temp);
		}
		int ret = 0;
		while (!q.empty()) {
			int temp = q.top();
			q.pop();
			if (!q.empty()) {
				temp += q.top();
				q.pop();
				q.push(temp);
				ret += temp;
			}
		}
		cout << ret << endl;
	}
}
  
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
	solve();	
	
    return 0;
}

