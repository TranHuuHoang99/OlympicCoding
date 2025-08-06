/*
**************************************************************************
  	author     : hoangprodn
  	email  	   : thhoang08091999@gmail.com
  	local time : 2025-08-05 20:00:10 
************************************************************************** 
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int A[35];
map<int,int> save1, save2;
map<int,int> ans;
int n;

void init(void) {
 	A[0] = 2;
 	A[1] = 3;
 	A[2] = 5;
 	for (int i = 3; i < 34; i++) {
 	 	A[i] = A[i-1] + A[i-2] + A[i-3];
 	}
 	for (int mask = 0; mask < (1 << 17); mask++) {
 	    int temp = 0;
 	    int cnt = 0;
 	    for (int i = 0; i < 17; i++) {
 	     	if (mask & (1 << i)) {
 	     	    cnt++;
 	     	    temp += A[i];
 	     	}	
 	    }
 	    save1[temp] = max(save1[temp], cnt);
 	}	
 	for (int mask = 0; mask < (1 << 17); mask++) {
 	 	int temp = 0;
 	 	int cnt = 0;
 	 	for (int i = 17; i < 34; i++) {
 	 	 	if (mask & (1 << (i-17))) {
 	 	 	 	temp += A[i];
 	 	 	 	cnt++;
 	 	 	}
 	 	}
 	 	save2[temp] = max(save2[temp], cnt);
 	}
}

void solve(void) {
    cin >> n;
    int ret = -1;
    for (pair<int,int> temp : save1) {
     	if (temp.first <= n) {
			int remain = n - temp.first;
			if (save2.find(remain) != save2.end()) {
			 	ret = max(ret, temp.second + save2[remain]);
			}
     	} else {
     	 	break;
     	}
    }
    cout << ret << endl;
}	

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	init();
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
	 	cout << "Case #" << i << ": ";
	 	solve();
	}
	return 0;
}




