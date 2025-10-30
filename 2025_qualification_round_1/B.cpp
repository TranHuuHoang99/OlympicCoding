/*
**************************************************************************
  	author     : hoangprodn
  	email  	   : thhoang08091999@gmail.com
  	local time : 2025-10-18 10:35:31 
************************************************************************** 
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct Node {
  	ll day;
  	int status;
  	int id;
};
const int N = 2e5+10;
ll S[N], E[N], P[N], D[N];
int n, k;
vector<Node> event;

bool cmp(Node a, Node b) {
 	if (a.day == b.day) return a.status > b.status;
 	return a.day < b.day;
}

void solve(void) {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
	 	cin >> S[i] >> E[i] >> P[i] >> D[i];
	}
	for (int i = 1; i <= n; i++) {
	 	event.push_back((Node){S[i], 1, i});
	 	event.push_back((Node){E[i]+1, -1, i});
	}
	sort(event.begin(), event.end(), cmp);
	ll ret = LLONG_MAX;
	ll fuel = 0;
	ll consume = 0;
	int cnt = 0;
	int len = event.size();
	for (int i = 0; i < len; i++) {
	 	int today = event[i].day;
	 	ll preFuel = fuel;
	 	ll preConsume = consume;
	 	int preCnt = cnt;
	 	if (cnt >= k) {
	 	 	ret = min(ret, fuel - 1ll * (today-1) * consume);
	 	}
	 	bool isChecked = false;
	 	while (i < len && event[i].day == today) {
	 	 	int id = event[i].id;
	 	 	int status = event[i].status;
	 	 	if (status == 1) {
	 	 	 	fuel += (P[id] + S[id] * D[id]);
	 	 	 	consume += D[id];
	 	 	 	cnt++;
	 	 	} else {
	 	 	 	fuel -= (P[id] + S[id] * D[id]);
	 	 	 	consume -= D[id];
	 	 	 	cnt--;
	 	 	}
	 	 	i++;
	 	 	isChecked = true;
	 	}
	 	if (isChecked) i--;
	 	if (preCnt >= k) {
	 	 	ret = min(ret, preFuel - 1ll * (today-1) * preConsume);
	 	}
	 	if (cnt >= k) {
	 	 	ret = min(ret, fuel - 1ll * (today) * consume);
	 	}
	}
	if (ret == LLONG_MAX) {
	 	cout << -1 << endl;
	} else {
	 	cout << ret << endl;
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}















