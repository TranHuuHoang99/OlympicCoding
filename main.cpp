#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<vector<int>> matrix;
vector<pair<int,int>> moves = {
    {1,0},{-1,0},{0,1},{0,-1},{-1,1},{1,1},{1,-1},{-1,-1}
};

vector<pair<int,int>> edges;

int solve(void) {
    int ret = 0;
    queue<pair<int,int>> q;
    vector<vector<bool>> isVisited(N, vector<bool>(M, false));

    for(auto e : edges) {
        if(isVisited[e.first][e.second]) continue;
        q.push({e.first, e.second});
        isVisited[e.first][e.second] = true;
        bool isValid = true;

        while(!q.empty()) {
            auto [x,y] = q.front();
            q.pop();

            for(int i = 0; i < 8; i++) {
                int ver = x + moves[i].first;
                int hor = y + moves[i].second;

                if(ver < 0 || ver > N-1 || hor < 0 || hor > M-1) continue;
                if(matrix[ver][hor] > matrix[x][y]) isValid = false;
                if(matrix[x][y] == matrix[ver][hor] && !isVisited[ver][hor]) {
                    q.push({ver,hor});
                    isVisited[ver][hor] = true;
                }
            }
        }

        if(isValid) ret++;
    }

    return ret;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    matrix.assign(N, vector<int>(M, 0));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> matrix[i][j];
            edges.push_back({i,j});
        }
    }

    cout << solve() << endl;

    return 0;
}
