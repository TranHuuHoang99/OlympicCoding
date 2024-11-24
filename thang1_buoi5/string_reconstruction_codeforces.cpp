/*
 ******************************************************************************************
 *      * AUTHOR : hoangprodn
 *      * CREATED: 30.11.2024 14:15:12
 ******************************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 1e5+1;
pair<string,vector<int>> A[N];
int n;
int max_val = INT32_MIN;

void solve(void) {
	cin >> n;
	for (int i = 0; i < n; i++) {
	 	string str;
	 	cin >> str;
	 	int a, b;
	 	cin >> a;
	 	A[i].first = str;
	 	for (int j = 0; j < a; j++) {
	 	 	cin >> b;
	 	 	A[i].second.push_back(b-1);
	 	 	max_val = max(max_val, (int)str.size() + b - 1);
	 	}
	}
	string ret = "";
	set<int> s;
	for (int i = 0; i < max_val; i++) {
	 	ret += 'a';
	 	s.insert(i);
	}
	for (int i = 0; i < n; i++) {
	 	string str = A[i].first;
	 	vector<int> arr = A[i].second;
	 	if (s.empty()) break;
	 	for (int j = 0; j < arr.size(); j++) {
	 	 	int idx = arr[j];
	 	 	while (true) {
	 	 	 	auto it = s.lower_bound(idx);
	 	 	 	if (it != s.end()) {
					int next = *it;
					if (next - idx < (int)str.size()) {
						ret[next] = str[next-idx];
						s.erase(it);
					} else {
					 	break;
					}
	 	 	 	} else {
	 	 	 	 	break;
	 	 	 	}
	 	 	}
	 	}
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

















