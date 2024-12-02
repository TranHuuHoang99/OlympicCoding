/*
 ******************************************************************************************
 *      * AUTHOR : hoangprodn
 *      * CREATED: 02.12.2024 14:04:03
 ******************************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 1e6+1;
char str[N];

void solve(void) {
	priority_queue<int> pq;
	while (cin >> str) {
	 	if (str[0] == '-') {
	 	 	if (!pq.empty()) {
	 	 	 	int temp = pq.top();
	 	 	 	while (!pq.empty() && temp == pq.top()) pq.pop();
	 	 	}
	 	} else if ((int)pq.size() < 15000) {
			pq.push(atoi(str+1));
	 	}
	}
	vector<int> ret;
	while (!pq.empty()) {
	 	ret.push_back(pq.top());
	 	pq.pop();
	}
	auto it = unique(ret.begin(), ret.end());
	ret.resize(distance(ret.begin(),it));
	cout << ret.size() << endl;
	for (int r : ret) cout << r << endl;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

#ifdef HOANGPRODN_DEBUG
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
#endif // HOANGPRODN_DEBUG

	solve();

	return 0;
}
