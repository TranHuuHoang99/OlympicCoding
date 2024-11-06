#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 1024;
char lines[N];

void solve(void) {
	string str;
	cin >> str;
	if (str.substr(str.length()-2, str.length()) == "35") {
		cout << "-" << endl;
	} else if (str[0] == '9' && str[str.size()-1] == '4') {
		cout << "*" << endl;
	} else if (str.substr(0, 3) == "190") {
		cout << "?" << endl;
	} else {
		cout << "+" << endl;
	}	
}
  
int32_t main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	int t;
	cin >> t;
	while (t--) {
		solve();
	}	
	
    return 0;
}



