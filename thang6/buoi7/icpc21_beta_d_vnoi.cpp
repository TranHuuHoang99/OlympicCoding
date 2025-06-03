#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 1e4+10;
int n, m, k;
int s, e;
vector<pair<int,int>> villages;
vector<pair<int,int>> roads;
map<string,int> mp;
int dist[N], totalCost[N];

void bfs(void) {
	queue<pair<int,int>> q;
 	for (int i = 1; i <= n; i++) {
 	 	memset(dist,-1,sizeof(dist));
 	 	q.push({i,villages[i].second});
 	 	dist[i] = 0;
 	 	while (!q.empty()) {
 	 	 	pair<int,int> p = q.front();
			q.pop();
			int u = p.first;
			int cost = p.second;
			for (pair<int,int> next : roads[u]) {
			 	if (dist[next.first] == -1) {
					dist[next.first] = dist[i] + 1;
					
			 	}
			}
 	 	}
 	}
}

void solve(void) {
 	cin >> n >> m >> k;
 	string st, ed;
 	cin >> st >> ed;
 	for (int i = 1; i <= n; i++) {
 	 	string str;
 	 	int moonStones, influence;
 	 	cin >> str >> moonStones >> influence;
 	 	villages[i].push_back({moonStones,influence});
 	 	if (str == st) {
 	 	 	s = i;
 	 	}
 	 	if (str == ed) {
 	 	 	e = i;
 	 	}
 	 	mp[str] = i;
 	}
 	for (int i = 1; i <= m; i++) {
 	 	string vil1, vil2;
 	 	int val;
 	 	cin >> vil1 >> vil2 >> val;
 	 	int u = mp[vil1];
 	 	int v = mp[bil2];
 	 	roads[u].push_back({v,val});
 	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	solve();

	return 0;
}

