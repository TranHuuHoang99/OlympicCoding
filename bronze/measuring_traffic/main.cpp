#include <bits/stdc++.h>
#define ll long long

using namespace std;

struct Node {
	string str;
	int a, b;	
};

void solve(void) {
	int n;
	cin >> n;
	vector<Node> A;
	for (int i = 0; i < n; i++) {
		string str;
		int a, b;
		cin >> str >> a >> b;
		A.push_back({str,a,b});
	}

	pair<int,int> ret = {-1e4, 1e4};
	for (int i = A.size()-1; i >= 0; i--) {
		if (A[i].str == "none") {
			ret.first = max(ret.first, A[i].a);
			ret.second = min(ret.second, A[i].b);
		} else if (A[i].str == "on") {
			ret.first -= A[i].b;
			ret.second -= A[i].a;
		} else if (A[i].str == "off") {
			ret.first += A[i].a;
			ret.second += A[i].b;
		}
	}

	cout << max(0, ret.first) << ' ' << max(0, ret.second) << endl;
	ret = {-1e4, 1e4};

	for (int i = 0; i < A.size(); i++) {
		if (A[i].str == "none") {
			ret.first = max(ret.first, A[i].a);
			ret.second = min(ret.second, A[i].b);
		} else if (A[i].str == "on") {
			ret.first += A[i].a;
			ret.second += A[i].b;
		} else if (A[i].str == "off") {
			ret.first -= A[i].b;
			ret.second -= A[i].a;
		}
	}

	cout << max(0, ret.first) << ' ' << max(0, ret.second) << endl;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen("traffic.in", "r", stdin);
	freopen("traffic.out", "w", stdout);

	solve();

	return 0;
}	



