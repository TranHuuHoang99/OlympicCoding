#include <bits/stdc++.h>

using namespace std;

vector<int> moves = {1,0,-1,0,1};

void solve(int n, int m) {
    int slicks = 0;
    vector<vector<int>> matrix(n, vector<int>(m,0));
    vector<vector<bool>> isVisited(n, vector<bool>(m, false));
    vector<pair<int,int>> sea;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> matrix[i][j];
            sea.push_back({i,j});
        }
    }

    queue<pair<int,int>> q;
    pair<int,int> temp;
    map<int,int> ret;

    for(auto s : sea) {
        if(isVisited[s.first][s.second] || matrix[s.first][s.second] == 0) continue;
        q.push({s.first, s.second});
        isVisited[s.first][s.second] = true;
        int count = 0;

        while(!q.empty()) {
            temp = q.front();
            q.pop();
            count++;

            for(int i = 0; i < 4; i++) {
                int ver = temp.first + moves[i];
                int hor = temp.second + moves[i+1];
                
                if(ver >= 0 && ver < n && hor >= 0 && hor < m && !isVisited[ver][hor]) {
                    isVisited[ver][hor] = true;
                    if(matrix[ver][hor] == 1) {
                        q.push({ver, hor});
                    }
                }
            }
        }

        ret[count] += 1;
        slicks++;
    }

    cout << slicks << endl;
    for(auto r : ret) {
        cout << r.first << " " << r.second << endl;
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n = 0, m = 0;

    while(cin >> n >> m && n && m) {
        solve(n, m);
    }

    return 0;
}