/*
 ******************************************************************************************
 *      * AUTHOR : hoangprodn
 *      * CREATED: 03.12.2024 22:16:14
 ******************************************************************************************
*/
#pragma GCC target("popcnt")
#include <bits/stdc++.h>
#define ll long long

using namespace std;

bitset<3000> bs[3000];
int n;

void solve(void) {
	cin >> n;
	for (int i = 0; i < n; i++) {
	 	string str;
	 	cin >> str;
	 	for (int j = 0; j < n; j++) {
	 	 	if (str[j] == '1') {
	 	 	 	bs[i].set(j,1);
	 	 	}
    	}
	}
	ll ret = 0LL;
	for (int i = 0; i < n; i++) {
	 	for (int j = i+1; j < n; j++) {
	 	 	int temp = (bs[i] & bs[j]).count();
	 	 	ret += temp * (temp-1) / 2;
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
