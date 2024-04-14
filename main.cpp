#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct Node {
    int des;
    int path;
    pair<int,int> pos;
    Node(int _des = 0, int _path = 0, pair<int,int> _pos = {0,0}) : 
    des(_des), path(_path), pos(_pos) {}
};

int N, M;
vector<Node> start;
vector<vector<char>> matrix;
vector<int> moves = {1,0,-1,0,1};

bool isDes(char des) {
    return des >= '1' && des <= '9';
}

int solve(void) {
    int res = 0;
    map<int,vector<Node>> ret;
    queue<Node> q;
    Node temp;

    for(auto s : start) {
        vector<vector<bool>> isVisited(N, vector<bool>(M, false));

        q.push(s);
        isVisited[s.pos.first][s.pos.second] = true;

        while(!q.empty()) {
            temp = q.front();
            q.pop();

            for(int i = 0; i < 4; i++) {
                int ver = temp.pos.first + moves[i];
                int hor = temp.pos.second + moves[i+1];

                if(ver >= 0 && ver < N && hor >= 0 && hor < M) {
                    if(!isVisited[ver][hor] && matrix[ver][hor] != '+') {
                        Node next(matrix[ver][hor]-'0', temp.path+1, {ver,hor});
                        if(isDes(matrix[ver][hor])) {
                            ret[s.des].push_back(next);
                        } 
                        q.push(next);
                        isVisited[ver][hor] = true;
                    }
                }
            }
        }
    }

    int temp_val = INT32_MIN;
    for(auto r : ret) {
        for(auto _r : r.second) {
            if(_r.des > temp_val) {
                res += _r.path;
            }
        }
        temp_val = r.first;
    }

    return res;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    matrix.assign(N, vector<char>(M, 0));

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> matrix[i][j];
            if(matrix[i][j] >= '1' && matrix[i][j] <= '9') {
                start.push_back(Node(matrix[i][j]-'0', 1, {i,j}));
            }
        }
    }

    cout << solve() << endl;

    return 0;
}
