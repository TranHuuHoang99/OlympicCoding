#include <bits/stdc++.h>

using namespace std;

struct Node {
    int x,y,value;
    Node(int _x = 0, int _y = 0, int _value = 0) : 
    x(_x), y(_y), value(_value) {}
};

int N,M;
vector<int> moves = {1,0,-1,0,1};
vector<vector<char>> matrix;
vector<vector<int>> dp;
pair<int,int> S;
pair<int,int> D;

int solve(void) {
    queue<Node> q;
    Node temp;
    vector<vector<bool>> isVisited(N, vector<bool>(M, false));

    q.push(Node(S.first, S.second, 0));
    isVisited[S.first][S.second] = true;
    dp[D.first][D.second] = INT32_MAX;
    isVisited[D.first][D.second] = true;

    while(!q.empty()) {
        temp = q.front();
        q.pop();

        for(int i = 0; i < 4; i++) {
            int ver = temp.x + moves[i];
            int hor = temp.y + moves[i+1];

            if(ver >= 0 && ver < N && hor >= 0 && hor < M) {
                Node next(ver,hor, temp.value+1);
                if(ver == D.first && hor == D.second) {
                    dp[ver][hor] = min(dp[ver][hor], next.value);
                }

                if(!isVisited[ver][hor] && matrix[ver][hor] != '+') {
                    q.push(next);
                    isVisited[ver][hor] = true;
                }
            }
        }
    }

    dp[D.first][D.second] = dp[D.first][D.second] == INT32_MAX ? -1 : dp[D.first][D.second];
    return dp[D.first][D.second];
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    matrix.assign(N, vector<char>(M, 0));
    dp.assign(N, vector<int>(M, 0));

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> matrix[i][j];
            if(matrix[i][j] == 'S') S = {i,j};
            if(matrix[i][j] == 'D') D = {i,j};
        }
    }

    cout << solve() << endl;

    return 0;
}
