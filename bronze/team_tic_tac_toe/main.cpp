#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 3;
set<set<char>> ret[4];
string matrix[N];

void update(string str) {
	set<char> s;
	for (char c : str) s.insert(c);
	ret[s.size()].insert(s);
}

void solve(void) {
	for (int i = 0; i < 3; i++) cin >> matrix[i];
	string str1, str2, str3, str4, str5, str6, str7, str8;
	for (int i = 0; i < 3; i++) {
		str1 += matrix[0][i];
		str2 += matrix[1][i];
		str3 += matrix[2][i];
		str4 += matrix[i][0];
		str5 += matrix[i][1];
		str6 += matrix[i][2];
		str7 += matrix[i][i];
		str8 += matrix[i][2-i];
	}

	update(str1);	
	update(str2);	
	update(str3);	
	update(str4);	
	update(str5);	
	update(str6);	
	update(str7);	
	update(str8);	

	cout << ret[1].size() << endl;
	cout << ret[2].size() << endl;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen("tttt.in", "r", stdin);
	freopen("tttt.out", "w", stdout);

	solve();

	return 0;
}	





