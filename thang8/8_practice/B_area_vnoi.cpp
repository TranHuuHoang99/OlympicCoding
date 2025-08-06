/*
**************************************************************************
  	author     : hoangprodn
  	email  	   : thhoang08091999@gmail.com
  	local time : 2025-08-06 20:11:41 
************************************************************************** 
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll N = 3e4+10;
int n;
vector<pair<pair<int,int>, pair<int,int>>> A;
pair<int,int> it[8*N]; // first value is flag turn on turn when x is out of rectangle, second value is distance from left -> right

void update_range(int idx, int left, int right) {
 	if (it[idx].first > 0) {
 	 	it[idx].second = right - left + 1;
 	} else {
 	 	it[idx].second = it[idx*2].second + it[idx*2+1].second;
 	}
}

void update(int idx, int left, int right, int u, int v, int val) {
 	if (u > right || v < left) return;
 	if (u <= left && right <= v) {
 	 	it[idx].first += val;
 	 	update_range(idx, left, right);
 	 	return;
 	}
 	int mid = (left+right)>>1;
 	update(idx*2, left, mid, u, v, val);
 	update(idx*2+1, mid+1, right, u, v, val);
 	update_range(idx, left, right);
}

void solve(void) {
 	cin >> n;
	for (int i = 1; i <= n; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		A.push_back({{y1, 1}, {x1, x2}});
		A.push_back({{y2, -1}, {x1, x2}});
	}
	sort(A.begin(), A.end());
	int ret = 0;
	for (int i = 0; i < A.size()-1; i++) {
	 	pair<pair<int,int>, pair<int,int>> temp = A[i];
	 	int x1 = temp.second.first;
	 	int x2 = temp.second.second;
	 	int y1 = temp.first.first;
	 	int type = temp.first.second;
	 	update(1, 0, 3e4, x1, x2-1, type);
	 	int y2 = A[i+1].first.first;
	 	int height = y2 - y1;
	 	int width = it[1].second;
	 	ret += height * width;
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

