/*
**************************************************************************
  	author     : hoangprodn
  	email  	   : thhoang08091999@gmail.com
  	local time : 2025-07-30 18:50:13 
************************************************************************** 
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int lim = 1e6+1;
const ll N = 1e6+10;
int n;
vector<int> line;
vector<int> start_point[N*2+10];
vector<int> end_point[N*2+10];
vector<pair<int,int>> segment[N*2+10];
int BIT[N*2+10];

void update(int idx, int val) {
 	for (int i = idx; i <= 2e6; i += i&-i) {
 	 	BIT[i] += val;
 	}
}

int get_val(int idx) {
 	int ret = 0;
 	for (int i = idx; i > 0; i -= i&-i) {
 	 	ret += BIT[i];
 	}
 	return ret;
}

void solve(void) {
 	cin >> n;
 	for (int i = 1; i <= n; i++) {
 		int x1, y1, x2, y2;
 		cin >> x1 >> y1 >> x2 >> y2;
 		x1 += lim;
 		y1 += lim;
 		x2 += lim;
 		y2 += lim;
 		if (x1 == x2) {
			line.push_back(y1);
			line.push_back(y2);
			start_point[y1].push_back(x1);
			end_point[y2].push_back(x1);
 		} else {
 		 	line.push_back(y1);
 		 	segment[y1].push_back({x1,x2});
 		}
 	}
 	sort(line.begin(), line.end());
 	ll ret = 0ll;
 	for (int i = 0; i < (int)line.size(); i++) {
 		int y = line[i];
 		if (i > 0 && line[i] == line[i-1]) continue;
 		for (int j = 0; j < (int)start_point[y].size(); j++) {
 		 	update(start_point[y][j], 1);
	 	}
	 	for (int j = 0; j < (int)segment[y].size(); j++) {
	 		pair<int,int> temp = segment[y][j];
	 		int right_val = get_val(temp.second);
	 		int left_val = get_val(temp.first-1);
	 		ret += 1ll * (right_val - left_val);
	   	}
	   	for (int j = 0; j < (int)end_point[y].size(); j++) {
	   	 	update(end_point[y][j], -1);
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


