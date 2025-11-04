/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2025-11-09 22:19:37
**************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n, m;
char A[52][52];
bool visited[52][52];
vector<pair<int,int>> diagonal = {
    {-1,-1},
    {-1, 1},
    {1, 1},
    {1, -1}
};
int steps[5] = {1,0,-1,0,1};
void solve(void) {
    cin >> n >> m;
    memset(visited, 0, sizeof(visited));
    vector<pair<int,int>> save;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> A[i][j];
            if (A[i][j] == '*') {
                save.push_back({i,j});
            }
        }
    }
    queue<pair<int,int>> q;
    for (pair<int,int> pos : save) {
        if (visited[pos.first][pos.second]) continue;
        q.push(pos);
        visited[pos.first][pos.second] = true;
        int numb = 0;
        int diagCnt = 0;
        while (!q.empty()) {
            auto [x,y] = q.front();
            q.pop();
            numb++;
            for (pair<int,int> check : diagonal) {
                int ver = x + check.first;
                int hor = y + check.second;
                if (ver < 1 || ver > n || hor < 1 || hor > m || A[ver][hor] == '.') continue;
                diagCnt++;
            }
            for (int i = 0; i < 4; i++) {
                int ver = x + steps[i];
                int hor = y + steps[i+1];
                if (ver < 1 || ver > n || hor < 1 || hor > m || A[ver][hor] == '.' || visited[ver][hor]) continue;
                visited[ver][hor] = true;
                q.push({ver,hor}); 
            }
        }
        if (numb != 3 || diagCnt != 2) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) solve();
    return 0;
}





