/*
**************************************************************************
  	author     : hoangprodn
  	email  	   : thhoang08091999@gmail.com
  	local time : 2025-10-16 22:15:17 
************************************************************************** 
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll N = 220;
const ll M = 60;
char A[N][N];
int B[N][N];
bool visited[N][N];
int dist[N][N];
pair<int,int> pawn[M];
pair<int,int> des;
vector<pair<int,int>> wall;
int R, C, n;
queue<pair<int,int>> q;
int moves[5] = {1,0,-1,0,1};
int distToDes[60];
int distToWall[60][5000];
int distWallToDes[5000];
const int inf = 50000;

void solve(void) {
	wall.clear();
	memset(B, 0, sizeof(B));
	memset(A, 0, sizeof(A));
	memset(distToDes, 0, sizeof(distToDes));
	memset(distToWall, 0, sizeof(distToWall));
	memset(distWallToDes, 0, sizeof(distWallToDes));
 	cin >> R >> C >> n >> des.first >> des.second;
 	for (int i = 1; i <= n; i++) {
 	 	cin >> pawn[i].first >> pawn[i].second;
 	}
 	int temp_id = 1;
 	for (int i = 1; i <= R; i++) {
 	 	for (int j = 1; j <= C; j++) {
 	 		cin >> A[i][j];
			if (A[i][j] == 'W') {
				wall.push_back({i,j});
				B[i][j] = temp_id;
				for (int idx = 1; idx <= n; idx++) distToWall[idx][temp_id] = inf;
				distWallToDes[temp_id] = inf;
				temp_id++;
			}
 	 	}
 	}
 	ll total = 0;
	for (int i = 1; i <= n; i++) {
	 	pair<int,int> start = pawn[i];
	 	memset(visited, 0, sizeof(visited));
	 	memset(dist, 0, sizeof(dist));
	 	q.push(start);
	 	visited[start.first][start.second] = true;
	 	while (!q.empty()) {
			auto [x,y] = q.front();
			q.pop();
			if (x == des.first && y == des.second) {
			 	total += dist[x][y];
			 	distToDes[i] = dist[x][y];
			}
			for (int idx = 0; idx < 4; idx++) {
			 	int ver = x + moves[idx];
			 	int hor = y + moves[idx+1];
			 	if (ver < 1 || ver > R || hor < 1 || hor > C) continue;
			 	if (A[ver][hor] == 'W') {
			 	 	distToWall[i][B[ver][hor]] = min(distToWall[i][B[ver][hor]], dist[x][y] + 1);
			 	 	continue;
			 	}
				if (visited[ver][hor]) continue;
				dist[ver][hor] = dist[x][y] + 1;
				visited[ver][hor] = true;
				q.push({ver,hor});
			}
	 	}
	}
	memset(visited, 0, sizeof(visited));
	memset(dist, 0, sizeof(dist));
	q.push(des);
	visited[des.first][des.second] = true;
	while (!q.empty()) {
	 	auto [x,y] = q.front();
	 	q.pop();
	 	for (int i = 0; i < 4; i++) {
	 	 	int ver = x + moves[i];
	 	 	int hor = y + moves[i+1];
	 	 	if (ver < 1 || ver > R || hor < 1 || hor > C) continue;
			if (A[ver][hor] == 'W') {
			 	int getId = B[ver][hor];
			 	distWallToDes[getId] = min(distWallToDes[getId], dist[x][y]+1);
			 	continue;
			}
			if (visited[ver][hor] == true) continue;
			dist[ver][hor] = dist[x][y] + 1;
			visited[ver][hor] = true;
			q.push({ver,hor});
	 	}
	}
	ll diff = 0;
	for (pair<int,int> w : wall) {
	 	int getid = B[w.first][w.second];
	 	int sum = 0;
	 	for (int i = 1; i <= n; i++) {
	 	 	int min_val = min(distToDes[i], distToWall[i][getid] + distWallToDes[getid]);
	 	 	sum += min_val;
	 	}
	 	diff += total - sum;
	}
	cout << total << ' ' << diff << endl;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
	 	solve();
	}
	return 0;
}































