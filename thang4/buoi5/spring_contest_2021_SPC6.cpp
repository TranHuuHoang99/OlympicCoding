/*
 ******************************************************************************************
 *      * AUTHOR : hoangprodn
 *      * CREATED: 25.03.2025 20:46:56
 ******************************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int n, m;
char matrix[50][50];
int moves[5] = {1,0,-1,0,1};
pair<int,int> A,a,B,b;
int dis[50][50][50][50];

void solve(void) {
	memset(dis,-1,sizeof(dis));
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
	 	for (int j = 1; j <= m; j++) {
	 	 	cin >> matrix[i][j];
	 	 	if (matrix[i][j] == 'A') A = {i,j};
	 	 	if (matrix[i][j] == 'B') B = {i,j};
	 	 	if (matrix[i][j] == 'a') a = {i,j};
	 	 	if (matrix[i][j] == 'b') b = {i,j};
	 	}
	}
	queue<pair<pair<int,int>, pair<int,int>>> q;
	q.push({A,B});
	dis[A.first][A.second][B.first][B.second] = 0;
	while (!q.empty()) {
	 	auto [xA,yA] = q.front().first;
	 	auto [xB,yB] = q.front().second;
	 	q.pop();
	 	for (int i = 0; i < 4; i++) {
	 	 	int verA = xA + moves[i];
	 	 	int horA = yA + moves[i+1];
	 	 	if (verA < 1 || verA > n || horA < 1 || horA > m || matrix[verA][horA] == '#') continue;
	 	 	for (int j = 0; j < 4; j++) {
	 	 	 	int verB = xB + moves[j];
	 	 	 	int horB = yB + moves[j+1];
	 	 	 	if (verB < 1 || verB > n || horB < 1 || horB > m || matrix[verB][horB] == '#') continue;
	 	 	 	if (verA == verB && horA == horB) continue;
	 	 	 	if (verA == verB && horB == yA && horA == yB) continue;
	 	 	 	if (horA == horB && verB == xA && verA == xB) continue;
	 	 	 	if (dis[verA][horA][verB][horB] == -1) {
	 	 	 	 	dis[verA][horA][verB][horB] = dis[xA][yA][xB][yB] + 1;
	 	 	 	 	q.push({{verA,horA},{verB,horB}});
	 	 	 	}
	 	 	}
	 	}
	}
	int temp = dis[a.first][a.second][b.first][b.second];
	if (temp == -1) {
	 	cout << "NO SOLUTION" << endl;
	} else {
	 	cout << temp << endl;
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

#ifdef HOANGPRODN_DEBUG
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
#endif // HOANGPRODN_DEBUG

	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
	 	solve();
	}

	return 0;
}
