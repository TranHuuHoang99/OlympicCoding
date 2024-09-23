#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 1e3+1;
char matrix[N][N];
char track[N][N];
int you[N][N];
bool v[N][N];
vector<vector<int>> monster;
int n, m;
pair<int,int> A;

bool isEdge(int x, int y) {
	return x == n-1 || x == 0 || y == m-1 || y == 0;
}

bool isValid(int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < m;
}

vector<pair<int,int>> moves = {
	{0,-1}, {0,1}, {-1,0}, {1,0}
};
char moves_str[4] = {'L', 'R', 'U', 'D'};
map<char,pair<int,int>> mp = {
	{'L', {0,1}},
	{'R', {0,-1}},
	{'U', {1,0}},
	{'D', {-1,0}}
};

pair<int,int> ret(void) {
	queue<pair<int,int>> q;
	q.push(A);
	v[A.first][A.second] = true;

	while (!q.empty()) {
		auto [x,y] = q.front();
		q.pop();
		
		if (isEdge(x,y)) return {x,y};

		for (int i = 0; i < 4; i++) {
			int ver = x + moves[i].first;
			int hor = y + moves[i].second;

			if (isValid(ver,hor) && matrix[ver][hor] != '#') {
				int temp = you[x][y] + 1;
				if (temp < monster[ver][hor] && !v[ver][hor]) {
					track[ver][hor] = moves_str[i];
					you[ver][hor] = temp;
					v[ver][hor] = true;
					q.push({ver,hor});
				}
			}
		}
	}	

	return {-1,-1};
}

void solve(void) {
	queue<pair<int,int>> monster_q;
	cin >> n >> m;
	
	vector<vector<bool>> monster_v(n, vector<bool>(m, false));
	monster.assign(n, vector<int>(m, INT32_MAX));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> matrix[i][j];
			if (matrix[i][j] == 'A') A = {i,j};
			if (matrix[i][j] == 'M') {
				monster_q.push({i,j});
				monster[i][j] = 0;
				monster_v[i][j] = true;
			}
		}
	}

	// monster movements;
	while (!monster_q.empty()) {
		auto [x,y] = monster_q.front();
		monster_q.pop();

		for (int i = 0; i < 4; i++) {
			int ver = x + moves[i].first;
			int hor = y + moves[i].second;
				
			if (isValid(ver, hor) && matrix[ver][hor] != '#') {
				monster[ver][hor] = min(monster[ver][hor], monster[x][y] + 1);
				if (!monster_v[ver][hor]) {
					monster_v[ver][hor] = true;
					monster_q.push({ver, hor});
				}
			}
		}
	}

	pair<int,int> temp = ret();
	if (temp.first == -1) {
		cout << "NO" << endl;
		return;
	}

	cout << "YES" << endl;
	
	stack<char> st;
	track[A.first][A.second] = 'X';
	char temp_c = track[temp.first][temp.second];
	while (temp_c != 'X') {
		st.push(temp_c);
		pair<int,int> next = mp[temp_c];
		temp.first += next.first;
		temp.second += next.second;
		temp_c = track[temp.first][temp.second];
	}
	
	cout << st.size() << endl;
	while (!st.empty()) {
		cout << st.top();
		st.pop();
	}
	cout << '\n';
}
  
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();	

	return 0;
}
