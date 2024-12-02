/*
 ******************************************************************************************
 *      * AUTHOR : hoangprodn
 *      * CREATED: 30.11.2024 20:43:17
 ******************************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int n;
map<string,int> mm;

void solve(void) {
	cin >> n;
	for (int i = 0; i < n; i++) {
	 	string str;
	 	cin >> str;
	 	if (mm.find(str) == mm.end()) {
	 	 	cout << "OK" << endl;
	 	 	mm[str]++;
	 	} else {
	 	 	int temp = mm[str];
	 	 	cout << str << temp << endl;
	 	 	mm[str]++;
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
