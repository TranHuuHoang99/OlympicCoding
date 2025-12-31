/*
 ******************************************************************************************
 *      * AUTHOR : hoangprodn
 *      * CREATED: 27.02.2025 22:26:43
 ******************************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 1e5+10;
string A[N];
int n;

void solve(void) {
	cin >> n;
	vector<set<string>> arr(9);
	for (int i = 0; i < n; i++) {
	 	cin >> A[i];
	 	int idx = A[i].size();
	 	arr[idx].insert(A[i]);
	}
	string ret = "";
	for (int i = 0; i < n; i++) {
	 	int len = A[i].size();
	 	bool flag = false;
	 	for (int j = 1; j <= len-1; j++) {
	 	 	string head = A[i].substr(0,j);
	 	 	string tail = A[i].substr(j,len-j);
	 	 	auto it1 = arr[j].find(head);
	 	 	auto it2 = arr[len-j].find(tail);
	 	 	if (it1 != arr[j].end() && it2 != arr[len-j].end()) {
	 	 	 	flag = true;
	 	 	 	break;
	 	 	}
	 	}
	 	if (flag) {
	 	 	ret += '1';
	 	} else {
	 		ret += '0';	
		}               
	}
	cout << ret << endl;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

#ifdef HOANGPRODN_DEBUG
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
#endif // HOANGPRODN_DEBUG

	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
	 	solve();
	}

	return 0;
}
