/*
**************************************************************************
  	author     : hoangprodn
  	email  	   : thhoang08091999@gmail.com
  	local time : 2026-04-04 12:42:37 
************************************************************************** 
*/
#include<bits/stdc++.h>
#define int long long
using namespace std;

struct Node {
  	int x, y, sz;
};
const int N = 120;
int n, m;
char A[N][N];
int status[N][N];
void solve(void) {
	cin >> n >> m;
	int valid = 0;
	for (int i = 1; i <= n; i++) {
	 	for (int j = 1; j <= m; j++) {
		 	cin >> A[i][j];
			if (A[i][j] == '*') valid++;
		}
	}
	if (valid == 0) {
	 	cout << 0 << endl;
		return;
	}
	vector<Node> ret;
	for (int x = 1; x <= n; x++) {
	 	for (int y = 1; y <= m; y++) {
		 	if (A[x][y] != '*') continue;
			pair<int,int> left = {x, y-1};
			pair<int,int> right = {x,y+1};
			pair<int,int> top = {x-1, y};
			pair<int,int> bot = {x+1, y};
			int cnt = 0;
			while (left.second >= 1 && right.second <= m && top.first >= 1 && bot.first <= n) {
			 	if (A[left.first][left.second] != '*') break;
				if (A[right.first][right.second] != '*') break;
				if (A[top.first][top.second] != '*') break;
				if (A[bot.first][bot.second] != '*') break;
				cnt++;
				int sum = status[left.first][left.second] + status[right.first][right.second] +
						  status[top.first][top.second] + status[bot.first][bot.second];
				if (sum != 4) {
					ret.push_back((Node){x, y, cnt});
				}	
				status[x][y] = 1;
				status[left.first][left.second] = 1;
				status[right.first][right.second] = 1;
				status[top.first][top.second] = 1;
				status[bot.first][bot.second] = 1;
				left.second -= 1;
				right.second += 1;
				top.first -= 1;
				bot.first += 1;
			}
		}
	}
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
	 	for (int j = 1; j <= m; j++) {
		 	if (status[i][j] == 1) cnt++;
		}
	}
	if (cnt != valid || ret.empty()) {
	 	cout << -1 << endl;
		return;
	}
	cout << ret.size() << endl;
	for (Node r : ret) cout << r.x << ' ' << r.y << ' ' << r.sz << endl; 
}
signed main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;                          
}

















































 