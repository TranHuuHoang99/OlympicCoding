#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 1e5+1;
const ll M = N * 2;
vector<pair<ll,int>> path1[N];
vector<pair<ll,int>> path2[N];
tuple<int,int,ll> tp[M];
int n,m;

void bfs(vector<ll>& dis, int start, vector<pair<ll, int>> path[]) {
	priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> q;
	dis[start] = 0;
	q.push({0,start});
	while (!q.empty()) {
		auto [x,y] = q.top();
		q.pop();
		
		if (x > dis[y]) continue;
		for (pair<ll,int> p : path[y]) {
			if (dis[p.second] > p.first + dis[y]) {
				dis[p.second] = p.first + dis[y];
				q.push({dis[p.second], p.second});	
			}
		}
	}
}


void solve(void) {
	cin >> n >> m;
	vector<ll> dis1(n, LLONG_MAX);
	vector<ll> dis2(n, LLONG_MAX);	

	for (int i = 0; i < m; i++) {
		int a,b;
		ll c;
		cin >> a >> b >> c;
		--a; --b;
		path1[a].push_back({c,b});
		path2[b].push_back({c,a});
		tp[i] = {a,b,c};
	}
	
	bfs(dis1, 0, path1);
	bfs(dis2, n-1, path2);

	ll ret = LLONG_MAX;
	for (int i = 0; i < m; i++) {
		int a, b;
		ll c;
		tie(a, b, c) = tp[i];
		if (dis1[a] == LLONG_MAX || dis2[b] == LLONG_MAX) continue;
		ret = min(ret, dis1[a] + dis2[b] + c/2);
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




















