/*
 ******************************************************************************************
 *      * AUTHOR : hoangprodn
 *      * CREATED: 10.12.2024 22:55:13
 ******************************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

void func(string str, int a, int b, int c, vector<string>& ret) {
 	if (ret.size() > 0) return;
 	if (a == 0 && b == 0 && c == 0) {
 	 	ret.push_back(str);
 	 	return;
 	}
 	if (a > 0 && str.back() == '0') {
 	 	func(str+'0', a-1, b, c, ret);
 	}
 	if (b > 0 && str.back() == '0') {
 	 	func(str+'1', a, b-1, c, ret);
 	}
 	if (b > 0 && str.back() == '1') {
 	 	func(str+'0', a, b-1, c, ret);
 	}
 	if (c > 0 && str.back() == '1') {
 	 	func(str+'1', a, b, c-1, ret);
 	}
}

void solve(void) {
	int a, b, c;
	cin >> a >> b >> c;
	vector<string> ret;
	vector<string> A = {"00","01","10","11"};
	for (int i = 0; i < A.size(); i++) {
		if (ret.size() > 0) break;
	 	if (A[i] == "00") {
			if (a <= 0) continue;
			func("00", a-1,b,c,ret);	 	 	            	
	 	} else if (A[i] == "11") {
	 	 	if (c <= 0) continue;
	 	 	func("11",a,b,c-1,ret);
	 	} else {
	 	 	if (b <= 0) continue;
	 	 	func(A[i],a,b-1,c,ret);	
        }                
	}
	cout << ret[0] << endl;
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
