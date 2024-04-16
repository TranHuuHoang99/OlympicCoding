#include <bits/stdc++.h>
#define ll long long

using namespace std;

int N,M;
vector<vector<char>> matrix;
pair<int,int> ret = {0,0};
vector<pair<int,int>> back_yard;
vector<int> moves = {1,0,-1,0,1};

void solve(void) {
    vector<vector<bool>> isVisited(N, vector<bool>(M, false));
    queue<pair<int,int>> q;
    
    for(auto by : back_yard) {
        if(isVisited[by.first][by.second] || matrix[by.first][by.second] == '#') continue;
        q.push(by);
        isVisited[by.first][by.second] = true;
        int _s = 0;
        int _w = 0;
        bool isBound = true;

        while(!q.empty()) {
            auto [x,y] = q.front();
            q.pop();

            if(matrix[x][y] == 'k') _s++;
            if(matrix[x][y] == 'v') _w++;
            if(x == 0 || x == N-1 || y == 0 || y == M-1) isBound = false;

            for(int i = 0; i < 4; i++) {
                int ver = x + moves[i];
                int hor = y + moves[i+1];

                if(ver < 0 || ver > N-1 || hor < 0 || hor > M-1) continue;
                if(!isVisited[ver][hor] && matrix[ver][hor] != '#') {
                    q.push({ver,hor});
                    isVisited[ver][hor] = true;
                }
            }
        }

        if(_s > _w && isBound) {
            ret.second -= _w;
        } else if(isBound) {
            ret.first -= _s;
        }
    }

    cout << ret.first << " " << ret.second << endl;
    return;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    matrix.assign(N, vector<char>(M, 0));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> matrix[i][j];
            back_yard.push_back({i,j});
            if(matrix[i][j] == 'k') {
                ret.first += 1;
            } else if(matrix[i][j] == 'v') {
                ret.second += 1;
            }
        }
    }

    solve();

    return 0;
}
