#include <bits/stdc++.h>
#define ll long long

using namespace std;

struct Node {
	int zones, grids, types;
};

const ll N = 110;
char matrix[N][N];
bool v[N][N];
char check[3] = {'R', 'G', 'B'};
int moves[5] = {1,0,-1,0,1};
int n;
vector<Node> ret(3);
vector<vector<pair<int,int>>> arr(3);

bool cmp(Node a, Node b) {
	if (a.zones == b.zones) {
		if (a.grids == b.grids) {
			return a.types < b.types;
		}
		return a.grids > b.grids;
	}
	return a.zones > b.zones;
}

void solve(void) {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> matrix[i][j];
			if (matrix[i][j] == 'R') {
				arr[0].push_back({i,j});
			} else if (matrix[i][j] == 'G') {
				arr[1].push_back({i,j});
			} else {
				arr[2].push_back({i,j});
			}
		}
	}
	for (int i = 0; i < 3; i++) ret[i].types = i;
	for (int i = 0; i < 3; i++) {
		int cnt_grid = 0;
		for (int j = 0; j < arr[i].size(); j++) {
			pair<int,int> start = arr[i][j];
			if (v[start.first][start.second]) continue;
			queue<pair<int,int>> q;
			q.push(start);
			v[start.first][start.second] = true;
			cnt_grid++;
			while (!q.empty()) {
				auto [x,y] = q.front();
				q.pop();
				for (int idx = 0; idx < 4; idx++) {
					int ver = x + moves[idx];
					int hor = y + moves[idx+1];
					if (ver < 0 || ver >= n || hor < 0 || hor >= n || v[ver][hor]) continue;
					if (matrix[ver][hor] != check[i]) continue;	
					cnt_grid++;
					q.push({ver,hor});
					v[ver][hor] = true;	
				}
			}
			ret[i].zones++;
		}
		ret[i].grids = cnt_grid;
	}
	sort(ret.begin(), ret.end(), cmp);
	cout << check[ret[0].types] << ' ' << ret[0].zones<< endl;
}
  
int32_t main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
	solve();
	
    return 0;
}

