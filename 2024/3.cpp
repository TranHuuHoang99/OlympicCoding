#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 101;
char matrix[N][N];
int memo[12][12];
int n, m;
int moves[5] = {1,0,-1,0,1};

void solve(void) {
	vector<pair<int,int>> loc;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> matrix[i][j];
			if (matrix[i][j] != '.' && matrix[i][j] != '*') {
				loc.push_back({i,j});
			}
		}
	}
	for (int i = 0; i < loc.size(); i++) {
		vector<vector<int>> update(n, vector<int>(m,0));
		vector<vector<bool>> v(n, vector<bool>(m, false));
		queue<pair<int,int>> q;
		q.push(loc[i]);
		v[loc[i].first][loc[i].second] = true;
		int start = matrix[loc[i].first][loc[i].second] == 'S' ? 0 : matrix[loc[i].first][loc[i].second] - '0';
		while (!q.empty()) {
			auto [x,y] = q.front();
			q.pop();
			for (int j = 0; j < 4; j++) {
				int ver = x + moves[j];
				int hor = y + moves[j+1];
				if (ver < 0 || ver >= n || hor < 0 || hor >= m || v[ver][hor] || matrix[ver][hor] == '*') continue;
				update[ver][hor] = update[x][y] + 1;
				if (matrix[ver][hor] != '.' && matrix[ver][hor] != '*') {
					char c = matrix[ver][hor];
					int end = c == 'S' ? 0 : c-'0';
					memo[start][end] = update[ver][hor];
				}
				q.push({ver,hor});
				v[ver][hor] = true;
			}
		}
	}
	vector<int> temp(loc.size()-1, 0);
	iota(temp.begin(), temp.end(), 1);
	int ret = INT32_MAX;
	do {
		int sum = 0;
		sum += memo[0][temp[0]];
		for (int i = 1; i < temp.size(); i++) sum += memo[temp[i-1]][temp[i]];
		sum += memo[temp[temp.size()-1]][0];
		ret = min(ret, sum);
	} while (next_permutation(temp.begin(), temp.end()));
	cout << ret << endl;
}
  
int32_t main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
	solve();
	
    return 0;
}


