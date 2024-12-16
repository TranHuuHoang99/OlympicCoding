/*
 ******************************************************************************************
 *      * AUTHOR : hoangprodn
 *      * CREATED: 15.12.2024 22:09:02
 ******************************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 2e5+1;
int A[N];
int update[N];
int n;

void solve(void) {
	cin >> n;
	set<int> s;
	for (int i = 1; i <= n; i++) s.insert(i);
	for (int i = 0; i < n; i++) cin >> A[i];
	vector<bool> v(n+1, false);
	for (int i = 0; i < n; i++) {
	 	if (!v[A[i]]) {
	 	 	update[i] = A[i];
	 	 	v[A[i]] = true;
	 	 	auto it = s.find(A[i]);
	 	 	s.erase(it);
	 	} else {
	 	 	int temp = *s.begin();
	 	 	update[i] = temp;
	 	 	v[temp] = true;
	 	 	auto it = s.find(temp);
	 	 	s.erase(it);
        }         
	}
	for (int i = 0; i < n; i++) cout << update[i] << ' ';
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
