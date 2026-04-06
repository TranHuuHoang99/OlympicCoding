/*
**************************************************************************
  	author     : hoangprodn
  	email  	   : thhoang08091999@gmail.com
  	local time : 2026-04-04 22:16:28 
************************************************************************** 
*/
#include<bits/stdc++.h>
#define int long long
using namespace std;

vector<int> prime;
bool isPrime(int a) {
	for (int i = 2; i * i <= a; i++) {
	 	if (a % i == 0) return false;
	}
	return true;
}	
void init(void) {
 	for (int i = 2; i <= 2e5+10; i++) {
		if (isPrime(i)) prime.push_back(i);
    }	
}
void solve(void) {
	int n;
	cin >> n;
	vector<int> ret;
	for (int i = 0; i < n; i++) {
	 	int val = prime[i] * prime[i+1];
		cout << val << ' ';
	}
	cout << endl;
}
signed main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    init();
    for (int i = 1; i <= t; i++) {
		solve();
    }
    return 0;
}
