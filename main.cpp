#include <bits/stdc++.h>

using namespace std;

int N;
vector<vector<int>> matrix;
vector<pair<int,int>> isLand;
vector<int> moves = {1,0,-1,0,1};
vector<int> sl;

int solve(void) {
    pair<int,int> ret = {0,INT32_MIN};
    queue<pair<int,int>> q;
    pair<int,int> temp;

    for(auto _sl : sl) {
        vector<vector<bool>> isVisited(N, vector<bool>(N, false));
        int count = 0;
        for(auto il : isLand) {
            if(matrix[il.first][il.second] <= _sl || isVisited[il.first][il.second]) continue;
            q.push({il.first, il.second});
            isVisited[il.first][il.second] = true;
            count++;

            while(!q.empty()) {
                temp = q.front();
                q.pop();

                for(int i = 0; i < 4; i++) {
                    int ver = temp.first + moves[i];
                    int hor = temp.second + moves[i+1];

                    if(ver >= 0 && ver < N && hor >= 0 && hor < N) {
                        if(!isVisited[ver][hor] && matrix[ver][hor] > _sl) {
                            q.push({ver,hor});
                            isVisited[ver][hor] = true;
                        }
                    }
                }
            }
        }

        if(count > ret.second) {
            ret = {_sl, count};
        }
    }

    return ret.first;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    matrix.assign(N, vector<int>(N, 0));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> matrix[i][j];
            sl.push_back(matrix[i][j]);
            isLand.push_back({i,j});
        }
    }

    sort(sl.begin(), sl.end());
    auto it = unique(sl.begin(), sl.end());
    sl.erase(it, sl.end());

    cout << solve() << endl;

    return 0;
}
