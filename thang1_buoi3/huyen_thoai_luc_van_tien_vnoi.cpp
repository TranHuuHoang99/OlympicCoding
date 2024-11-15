#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 17010;
int A[N];

void solve(void) {
	int n, k;
	cin >> n >> k;
	memset(A,0,sizeof(A));
	for (int i = 0; i < n; i++) cin >> A[i];
	if (k == 1) {
		for (int i = 0; i < n; i++) cout << A[i] << ' ';
		cout << endl;
		return;
	} 
	deque<int> dq;
	for (int i = 0; i < k; i++) {
		while (!dq.empty() && A[dq.back()] >= A[i]) dq.pop_back();
		dq.push_back(i);
	}
	cout << A[dq.front()] << ' ';
	for (int i = k; i < n; i++) {
		if (dq.front() <= i-k) dq.pop_front();
		while (!dq.empty() && A[dq.back()] >= A[i]) dq.pop_back();
		dq.push_back(i);
		cout << A[dq.front()] << ' ';
	}
	cout << endl;
}
  
int main(void) {
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





