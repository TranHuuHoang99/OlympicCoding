#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve(void) {
	int n, k;
	cin >> n >> k;
	vector<pair<int,int>> arr;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		arr.push_back({a,b});
	}
	sort(arr.begin(), arr.end());
	priority_queue<int,vector<int>,greater<int>> q;
	for (int i = 0; i < k; i++) {
		q.push(arr[i].second);
	}
	int ret = 0;
	if (q.top() >= arr[k-1].first) {
		ret = q.top() - arr[k-1].first + 1;
	}
	for (int i = k; i < n; i++) {
		q.pop();
		q.push(arr[i].second);
		if (q.top() >= arr[i].first) {
			ret = max(ret, q.top() - arr[i].first + 1);
		}
	}
	cout << ret << endl;
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




