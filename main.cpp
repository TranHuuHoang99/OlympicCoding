#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 1e3+1;
int n, m;
char matrix[N][N];
bool v[N][N];
int moves[5] = {1,0,-1,0,1};

void solve(void) {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> matrix[i][j];
		}
	}

	int ret = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (matrix[i][j] == '.' && !v[i][j]) {
				v[i][j] = true;
				queue<pair<int,int>> q;
				q.push({i,j});
				
				while (!q.empty()) {
					auto [x,y] = q.front();
					q.pop();

					for (int i = 0; i < 4; i++) {
						int ver = x + moves[i];
						int hor = y + moves[i+1];

						if (ver < 0 || ver >= n || hor < 0 || hor >= m) continue;
						if (!v[ver][hor] && matrix[ver][hor] == '.') {
							v[ver][hor] = true;
							q.push({ver, hor});
						}
					}
				}

				ret++;
			}
		}
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
