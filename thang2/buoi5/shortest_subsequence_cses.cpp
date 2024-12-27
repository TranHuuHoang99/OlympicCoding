/*
 ******************************************************************************************
 *      * AUTHOR : hoangprodn
 *      * CREATED: 27.12.2024 19:18:06
 ******************************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

bool v[4];
string str;

void solve(void) {
	cin >> str;
	string temp = "";
	string ret = "";
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == 'A') {
		 	temp += '0';
		} else if (str[i] == 'C') {
		 	temp += '1';
		} else if (str[i] == 'G') {
		 	temp += '2';
		} else {
		 	temp += '3';
		}
  	}
  	int cnt = 0;
  	for (int i = 0; i < temp.size(); i++) {
  	 	int idx = int(temp[i]-'0');
  	 	if (!v[idx]) {
  	 	 	cnt++;
  	 	 	v[idx] = true;
  	 	}
  	 	if (cnt == 4) {
  	 	 	fill(v,v+4,false);
  	 	 	ret += str[i];
  	 	 	cnt = 0;
  	 	}
  	}
  	if (cnt == 0) {
		ret += 'A';
  	} else {
  	 	for (int i = 0; i < 4; i++) {
  	 	 	if (!v[i]) {
  	 	 	 	if (i == 0) {
  	 	 	 	 	ret += 'A';	
  	 	 	 	} else if (i == 1) {
					ret += 'C';
  	 	 	 	} else if (i == 2) {
					ret += 'G';
  	 	 	 	} else {
					ret += 'T';
  	 	 	 	}
  	 	 	 	break;
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
