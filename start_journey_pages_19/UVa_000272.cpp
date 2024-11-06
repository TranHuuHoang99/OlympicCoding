#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 1024;
char lines[N];

void solve(void) {
	bool isOpen = true;
	string str;
	while (getline(cin, str)) {
		for (int i = 0; i < str.size(); i++) {
			if (str[i] == '"') {
				if (isOpen) {
					cout << "``";
				} else {
					cout << "''";
				}
				isOpen = !isOpen;
			} else {
				cout << str[i];
			}
		}
		cout << endl;
	}
}
  
int32_t main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
	solve();
	
    return 0;
}

