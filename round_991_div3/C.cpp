/*
 ******************************************************************************************
 *      * AUTHOR : hoangprodn
 *      * CREATED: 05.12.2024 23:28:39
 ******************************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve(void) {
	string str;
	cin >> str;
	int ret = 0;
	int n = 0;
	int m = 0;
	for (int i = 0; i < str.size(); i++) {
	 	int temp = int(str[i]-'0');
	 	ret += temp;
	 	if (temp == 2) n++;
	 	if (temp == 3) m++;
	}
	for(int i = 0; i <= n; i++) {
	 	for (int j = 0; j <= m; j++) {
	 	 	int temp = i*2 + j *6;
	 	 	if ((ret+temp) % 9 == 0) {
	 	 	 	cout << "yes" << endl;
	 	 	 	return;
	 	 	}
		}
	}
	cout << "no" << endl;
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
