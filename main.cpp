#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 1e3+1;
char matrix[N][N];
int val[N][N];
char path[N][N];
bool v[N][N];
int n, m;

pair<int,int> moves[4] = {
	{0, -1}, {0, 1}, {-1, 0}, {1, 0}
};

char str_m[4] = {'L', 'R', 'U', 'D'};

map<char,pair<int,int>> track = {
	{'L', {0, 1}},
	{'R', {0, -1}},
	{'U', {1, 0}},
	{'D', {-1, 0}}	
};

void solve(void) {
	cin >> n >> m;
	pair<int,int> start;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> matrix[i][j];
			if (matrix[i][j] == 'A') start = {i,j};
		}
	}

	queue<pair<int,int>> q;
   	q.push(start);
	v[start.first][start.second] = true;
	path[start.first][start.second] = 'X';
	bool valid = false;
	pair<int,int> end;
	while (!q.empty()) {
		auto [x,y] = q.front();
		q.pop();

		if (matrix[x][y] == 'B') {
			end = {x,y};
			valid = true;
			break;
		}

		for (int i = 0; i < 4; i++) {
			int ver = x + moves[i].first;
			int hor = y + moves[i].second;
			
			if (ver < 0 || ver >= n || hor < 0 || hor >= m) continue;
			if (!v[ver][hor] && matrix[ver][hor] != '#') {
				v[ver][hor] = true;
				val[ver][hor] = val[x][y] + 1;
				path[ver][hor] = str_m[i];
				q.push({ver, hor});	
			}
		}
	}	
	
	if (valid) {
		queue<pair<int,int>> n_q;
		stack<char> str_path;
		n_q.push(end);

		cout << "YES" << endl;
		cout << val[end.first][end.second] << endl;
		while (!n_q.empty()) {
			auto [x,y] = n_q.front();
			n_q.pop();

			if (path[x][y] != 'X') {
				str_path.push(path[x][y]);
				n_q.push({x + track[path[x][y]].first, y + track[path[x][y]].second});
			}
		}

		while (!str_path.empty()) {
			cout << str_path.top();
			str_path.pop();
		}

		cout << '\n';

	} else {
		cout << "NO" << endl;
	}

	return;
}
  
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();	

	return 0;
}
