/*
 ******************************************************************************************
 *      * AUTHOR : hoangprodn
 *      * CREATED: 01.01.2025 14:11:50
 ******************************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve(void) {
	int n;
	string str;
	cin >> str >> n;
	string h = str.substr(0,2);
	string m = str.substr(3,2);
	string t_h = h;
	string t_m = m;
	int hour = 0;
	int minute = 0;
	if (n <= 59) {
	 	minute = n;
	} else {
	 	hour = n / 60;
	 	minute = n - hour * 60;
	}
	int ret = 0;
	do {
		if (t_h[0] == t_m[1] && t_h[1] == t_m[0]) ret++;
		int temp1 = stoi(t_m);
		int temp2 = stoi(t_h);
		temp1 += minute;
		temp2 += hour;
		temp2 += temp1 / 60;
		temp1 %= 60;
		temp2 %= 24;
		if (temp2 >= 10) {
		 	t_h = to_string(temp2);
		} else {
		 	t_h[0] = '0';
		 	t_h[1] = char(temp2+'0');
		}
		if (temp1 >= 10) {
		 	t_m = to_string(temp1);
		} else {
		 	t_m[0] = '0';
		 	t_m[1] = char(temp1+'0');
		}
 	} while (t_h != h || t_m != m);
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
	while (t--) {
	 	solve();
	}

	return 0;
}
