#include <bits/stdc++.h>

using namespace std;

int n = 0, m = 0;
vector<pair<int,int>> lands;
vector<vector<int>> matrix;
set<int> sea_level;
vector<int> moves = {1,0,-1,0,1};

int solve(void) {
    priority_queue<int,vector<int>, greater<int>> ret;

    for(auto sl : sea_level) {  
        vector<vector<bool>> isVisited(n, vector<bool>(m, false));
        queue<pair<int,int>> q;
        pair<int,int> temp;
        int count = 0;

        for(auto l : lands) {
            if(matrix[l.first][l.second] <= sl || isVisited[l.first][l.second]) continue;
            q.push({l.first, l.second});
            count++;
            isVisited[l.first][l.second] = true;

            while(!q.empty()) {
                temp = q.front();
                q.pop();

                for(int i = 0; i < 4; i++) {
                    int ver = temp.first + moves[i];
                    int hor = temp.second + moves[i+1];

                    if(ver >= 0 && ver < n && hor >= 0 && hor < m) {
                        if(!isVisited[ver][hor] && matrix[ver][hor] > sl) {
                            isVisited[ver][hor] = true;
                            q.push({ver,hor});
                        }
                    }
                }
            }

            if(count > 1) ret.push(sl);
        }
    }

    return ret.empty() ? -1 : ret.top();
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    matrix.assign(n, vector<int>(m, 0));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> matrix[i][j];
            lands.push_back({i,j});
            sea_level.insert(matrix[i][j]);
        }
    }

    cout << solve() << endl;

    return 0;
}
