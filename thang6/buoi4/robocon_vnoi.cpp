#include <bits/stdc++.h>
#define ll long long

using namespace std;

struct Node {
 	int steps, x, y;
};

const ll N = 5e2+10;
bool visited1[N][N], visited2[N][N];
bool block[N][N];
int n, k;
bool found = false;
pair<int,int> move1[3] = {
  	{0,1},
  	{1,0},
  	{1,1}
};
pair<int,int> move2[3] = {
  	{0,-1},
  	{1,0},
  	{1,-1}
};
queue<Node> q1, q2;

void bfs1(int steps) {
 	while (!q1.empty()) {
 	 	Node temp = q1.front();
 	 	if (temp.steps != steps-1) break;
 	 	q1.pop();
 	 	int x = temp.x;
 	 	int y = temp.y;
 	 	for (int i = 0; i < 3; i++) {
 	 	 	pair<int,int> p = move1[i];
 	 	 	int ver = x + p.first;
 	 	 	int hor = y + p.second;
 	 	 	if (ver < 1 || ver > n || hor < 1 || hor > n || block[ver][hor] == true || visited1[ver][hor] == true) continue;
 	 	 	visited1[ver][hor] = true;
 	 	 	q1.push((Node){temp.steps+1, ver, hor});
 	 	}
 	}
}

void bfs2(int steps) {
 	while (!q2.empty()) {
 	 	Node temp = q2.front();
 	 	if (temp.steps != steps-1) break;
		q2.pop();
		int x = temp.x;
		int y = temp.y;
		for (int i = 0; i < 3; i++) {
		 	pair<int,int> p = move2[i];
		 	int ver = x + p.first;
		 	int hor = y + p.second;
		 	if (ver < 1 || ver > n || hor < 1 || hor > n || block[ver][hor] == true) continue;
 			if (visited1[ver][hor] == true) {
 			 	found = true;
 			 	return;
 			}
 			if (visited2[ver][hor] == true) continue;
		 	visited2[ver][hor] = true;
		 	q2.push((Node){temp.steps+1, ver, hor});
		}
 	}
}

void solve(void) {
	cin >> n >> k;
	for (int i = 1; i <= k; i++) {
	 	int a, b;
	 	cin >> a >> b;
	 	block[a][b] = true;
	}
	q1.push((Node){0,1,1});
	q2.push((Node){0,1,n});
	visited1[1][1] = true;
	visited2[1][n] = true;
	for (int steps = 1; steps <= 2*n; steps++) {
	 	bfs1(steps);
	 	found = false;
	 	bfs2(steps);
	 	if (found == true) {
	 	 	cout << steps << endl;
	 	 	return;
	 	}
	 	queue<Node> temp = q1;
	 	while (!temp.empty()) {
	 	 	Node node = temp.front();
	 	 	temp.pop();
	 	 	visited1[node.x][node.y] = false;
	 	}
	 	temp = q2;
	 	while (!temp.empty()) {
	 		Node node = temp.front();
	 		temp.pop();
	 		visited2[node.x][node.y] = false;	
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
#ifdef HOANGPRODN_DEBUG
	freopen("output.out", "w", stdout);
#endif // HOANGPRODN_DEBUG
	solve();
	return 0;
}







































