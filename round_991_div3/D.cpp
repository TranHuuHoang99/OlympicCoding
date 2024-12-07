/*
 ******************************************************************************************
 *      * AUTHOR : hoangprodn
 *      * CREATED: 06.12.2024 19:24:47
 ******************************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve(void) {
	string str;
	cin >> str;
	vector<int> ret;
	for (int i = 0; i < str.size(); i++) {
	 	int temp = int(str[i]-'0');
	 	ret.push_back(temp);
	}
	for (int i = 1; i < ret.size(); i++) {
	 	int idx = i;
	 	while (idx >= 1 && ret[idx] > 0 && ret[idx] > ret[idx-1]+1) {
	 	 	int temp = ret[idx];
	 	 	ret[idx] = ret[idx-1];
	 	 	ret[idx-1] = temp-1;
	 	 	idx--;
	 	}
	}
	for (int i = 0; i < ret.size(); i++) cout << ret[i];
	cout << endl;
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
	while (t--) {
	 	solve();
	}

	return 0;
}
