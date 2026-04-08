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

const int N = 1e3+2;
int n, m;
char A[N][N];
char checker[N][N];
int ver[N][N];
int hor[N][N];
int l[N][N];
int r[N][N];
int u[N][N];
int d[N][N];
vector<pair<pair<int,int>, int>> save;
void solve(void) {
 	cin >> n >> m;
    for (int i = 1; i <= n; i++) {
     	for (int j = 1; j <= m; j++) {
         	cin >> A[i][j];
            checker[i][j] = '.';
        }
    }
    for (int i = 1; i <= n; i++) {
     	for (int j = 1; j <= m; j++) {
         	if (A[i][j] == '*') {
				u[i][j] = u[i-1][j] + 1;
            }
            if (A[i][j] == '*') {
             	l[i][j] = l[i][j-1] + 1;
            }
        }
    }
    for (int i = n; i >= 1; i--) {
     	for (int j = m; j >= 1; j--) {
         	if (A[i][j] == '*') {
             	d[i][j] = d[i+1][j] + 1;
            }
            if (A[i][j] == '*') {
             	r[i][j] = r[i][j+1] + 1;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
     	for (int j = 1; j <= m; j++) {
         	if (A[i][j] == '*') {
            	int min_val = min({u[i][j], d[i][j], l[i][j], r[i][j]}) - 1;
                if (min_val > 0) {
                 	save.push_back(make_pair(make_pair(i, j), min_val));
                }
            }
        }
    }
    // re-draw by using ret list
    for (pair<pair<int,int>, int> s : save) {
     	int x = s.first.first;
        int y = s.first.second;
        int sz = s.second;
        ver[x-sz][y]++;
        ver[x+sz+1][y]--;
        hor[x][y-sz]++;
        hor[x][y+sz+1]--;
    }
    for (int i = 1; i <= n; i++) {
     	for (int j = 1; j <= m; j++) {
         	ver[i][j] += ver[i-1][j];
            hor[i][j] += hor[i][j-1];
            if (ver[i][j] > 0 || hor[i][j] > 0) {
             	checker[i][j] = '*';
            }
        }
    }
    for (int i = 1; i <= n; i++) {
     	for (int j = 1; j <= m; j++) {
         	if (checker[i][j] != A[i][j]) {
             	cout << -1 << endl;
                return;
            }
        }
    }
    cout << save.size() << endl;
    for (pair<pair<int,int>, int> s : save) {
    	cout << s.first.first << ' ' << s.first.second << ' ' << s.second << endl;
    }
}
signed main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;                          
}















