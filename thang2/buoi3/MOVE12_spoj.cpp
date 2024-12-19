/*
 ******************************************************************************************
 *      * AUTHOR : hoangprodn
 *      * CREATED: 18.12.2024 21:59:32
 ******************************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 1e4+1;
pair<int,int> A[N];
pair<int,int> update[N];
int n;

bool valid(int mid) {
	for (int i = 1; i <= n; i++) {
	 	int left_pos = max(1,A[i].first-mid/A[i].second);
	 	int right_pos = min(n,A[i].first+mid/A[i].second);
	 	update[i] = {left_pos, right_pos};
	}
	sort(update+1,update+1+n);
	priority_queue<int,vector<int>,greater<int>> q;
	for (int i = 1, j = 1; i <= n; i++) {
		 while (j <= n && update[j].first <= i) {
		  	q.push(update[j++].second);
		 }
		 if (q.empty()) return false;
		 int temp = q.top();
		 q.pop();
		 if (temp < i) return false;
	}
	return true;
}

void solve(void) {
	cin >> n;
	int max_val = INT32_MIN;
	for (int i = 1; i <= n; i++) {
	 	cin >> A[i].first >> A[i].second;
	 	max_val = max(max_val, A[i].second);
	}   
	int left = 0;
	int right = max_val * n;
	int ret = 0;
	while (left <= right) {
	 	int mid = (left + right) / 2;
	 	if (valid(mid)) {
	 	 	ret = mid;
	 	 	right = mid - 1;
	 	} else {
	 	 	left = mid + 1;
	 	}
	}
	cout << ret << endl;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
#ifdef HOANGPRODN_DEBUG
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
#endif // HOANGPRODN_DEBUG

	solve();

	return 0;
}


















