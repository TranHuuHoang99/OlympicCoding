#include <bits/stdc++.h>

using namespace std;

int n = 0, m = 0;
vector<vector<int>> matrix;
vector<vector<bool>> isVisited;
vector<pair<int,int>> sea;
vector<int> moves = {1,0,-1,0,1};

void solve(void) {   
    map<int,int> ret;
    queue<pair<int,int>> q;
    pair<int,int> temp;
    int slicks = 0;

    for(auto s : sea) {
        if(isVisited[s.first][s.second] || matrix[s.first][s.second] == 0) continue;
        int count = 0;
        slicks++;
        q.push({s.first, s.second});
        isVisited[s.first][s.second] = true;

        while(!q.empty()) {
            temp = q.front();
            q.pop();
            count++;

            for(int i = 0; i < 4; i++) {
                int ver = temp.first + moves[i];
                int hor = temp.second + moves[i+1];

                if(ver >= 0 && ver < n && hor >= 0 && hor < m) {
                    if(!isVisited[ver][hor] && matrix[ver][hor] != 0) {
                        q.push({ver, hor});
                        isVisited[ver][hor] = true;
                    }
                }
            }
        }
        ret[count] +=1;
    }

    cout << slicks << endl;
    for(auto r : ret) {
        cout << r.first << " " << r.second << endl;
    }

    return;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    matrix.assign(n, vector<int>(m, 0));   
    isVisited.assign(n, vector<bool>(m, false));
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> matrix[i][j];
            sea.push_back({i,j});
        }
    }

    solve();

    return 0;
}
