/*
 ******************************************************************************************
 *      * AUTHOR : hoangprodn
 *      * CREATED: 18.02.2025 10:45:34
 ******************************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

string str;

void solve(void) {
 	cin >> str;
 	bool ret1 = false, ret2 = false;
 	for (int i = 0; i < str.size()-1; i++) {
 	 	if (str[i] == 'A' && str[i+1] == 'B' && !ret1) {
 	 	 	ret1 = true;
 	 	 	i++;
 	 	 	continue;
 	 	}
 	 	if (str[i] == 'B' && str[i+1] == 'A' && !ret2 && ret1) {
 	 	 	ret2 = true;
 	 	 	i++;
 	 	 	continue;
 	 	}
 	 	if (ret1 && ret2) {
 	 	 	cout << "yes" << endl;
 	 	 	return;
 	 	}
 	}
 	if (ret1 && ret2) {
 	 	cout << "yes" << endl;
 	 	return;
 	}
 	ret1 = false;
 	ret2 = false;
 	for (int i = 0; i < str.size() - 1; i++) {
 	 	if (str[i] == 'B' && str[i+1] == 'A' && !ret1) {
 	 	 	ret1 = true;
 	 	 	i++;
 	 	 	continue;
 	 	}
 	 	if (str[i] == 'A' && str[i+1] == 'B' && !ret2 && ret1) {
 	 	 	ret2 = true;
 	 	 	i++;
 	 	 	continue;
 	 	}
 	 	if (ret1 && ret2) {
 	 	 	cout << "yes" << endl;
 	 	 	return;
 	 	}
 	}
 	if (ret1 && ret2) {
 	 	cout << "yes" << endl;
 	 	return;
 	}
 	cout << "no" << endl;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	solve();

	return 0;
}
