/*
 ******************************************************************************************
 *      * AUTHOR : hoangprodn
 *      * CREATED: 30.11.2024 19:32:37
 ******************************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

multiset<int> smaller;
multiset<int> bigger;
int n;

void update(void) {
 	while ((int)bigger.size() > (int)smaller.size()) {
 	 	auto it = bigger.begin();
 	 	int val = *it;
 	 	bigger.erase(it);
 	 	smaller.insert(val);
 	}
 	while ((int)(smaller.size()-1) > (int)bigger.size()) {
 	 	auto it = smaller.end();
 	 	--it;
 	 	int val = *it;
 	 	smaller.erase(it);
 	 	bigger.insert(val);
 	}
}

void solve(void) {
	cin >> n;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		if (str == "IN") {
			int a;
			cin >> a;
			if (smaller.empty()) {
			 	smaller.insert(a);
			 	continue;
			}
			auto it = smaller.end();
			--it;
			int temp = *it;
			if (a < temp) {
				smaller.insert(a);
			} else {
				bigger.insert(a);
			}
			update();
		} else if (str == "OUT") {
			int a;
			cin >> a;
			auto it = smaller.find(a);
			if (it != smaller.end()) {
			 	smaller.erase(it);
			} else {
				it = bigger.find(a);
				bigger.erase(it);
            }      
            update();
		} else {
			if (smaller.empty()) {
			 	cout << 0 << endl;
			 	continue;
			}
			if ((int)smaller.size() > (int)bigger.size()) {
			 	auto it = smaller.end();
			 	--it;
			 	cout << *it << endl;
			} else {
			 	auto it1 = smaller.end();
			 	--it1;
			 	auto it2 = bigger.begin();
			 	int val1 = *it1;
			 	int val2 = *it2;
			 	cout << fixed << setprecision(1) << 1.0 * (val1 + val2) / 2.0 << endl;
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

















