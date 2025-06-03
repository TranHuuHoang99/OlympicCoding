#include <bits/stdc++.h>
#define ll long long

using namespace std;

int n, m, d;

void solve(void) {
	cin >> n >> m >> d;
	set<vector<int>> s;
	for (int i = 0; i < n; i++) {
	    vector<int> temp;
	    for (int j = 0; j <= d; j++) {
	     	int a;
	     	cin >> a;
	     	temp.push_back(a);
	    }
	    s.insert(temp);
	}
	int ret = 0;
	for (int i = 0; i < m; i++) {
	 	vector<int> temp;
	 	for (int j = 0; j <= d; j++) {
	 	 	int a;
			cin >> a;
			temp.push_back(a);
	 	}
		if (s.find(temp) != s.end()) {
		 	cout << "BAD" << endl;
		} else {
		 	cout << "GOOD" << endl;
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

