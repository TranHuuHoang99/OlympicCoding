#include <bits/stdc++.h>

using namespace std;

struct Node {
    int x;
    int y;
    int high;
    Node(int _x = 0, int _y = 0, int _high = 0) : x(_x), y(_y), high(_high) {}
};

int n = 0, m = 0;
vector<int> moves = {1,0,-1,0,1};
vector<vector<int>> matrix;
set<int> sea_levels;
vector<Node> sea;

bool isValid(const int &level) {
    vector<vector<int>> temp_matrix = matrix;
    vector<vector<bool>> isVisited(n, vector<bool>(m, false));
    queue<Node> q;
    for(auto s : sea) {
        if(s.high > level) continue;
        if(!isVisited[s.x][s.y]) {
            q.push(s);
            isVisited[s.x][s.y] = true;
            temp_matrix[s.x][s.y] = -1;
        }

        Node temp;
        while(!q.empty()) {
            temp = q.front();
            q.pop(); 

            for(int i = 0; i < 4; i++) {
                int ver = temp.x + moves[i];
                int hor = temp.y + moves[i+1];

                if(ver < 0 || ver >= n || hor < 0 || hor >= m) continue;
                if(!isVisited[ver][hor] && temp_matrix[ver][hor] <= level) {
                    temp_matrix[ver][hor] = -1;
                    isVisited[ver][hor] = true;
                    q.push(Node(ver,hor, temp_matrix[ver][hor]));
                }
            }
        }
    }

    int count = 0;
    isVisited.assign(n, vector<bool>(m, false));
    queue<pair<int,int>> q_pos;
    pair<int,int> temp_pos;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(temp_matrix[i][j] <= -1) continue;
            if(!isVisited[i][j]) {
                isVisited[i][j] = true;
                q_pos.push({i,j});
                count++;
            }

            while(!q_pos.empty()) {
                temp_pos = q_pos.front();
                q_pos.pop();

                for(int i = 0; i < 4; i++) {
                    int ver = temp_pos.first + moves[i];
                    int hor = temp_pos.second + moves[i+1];
                    
                    if(ver < 0 || ver >= n || hor < 0 || hor >= m) continue;
                    if(!isVisited[ver][hor] && temp_matrix[ver][hor] > -1) {
                        isVisited[ver][hor] = true;
                        q_pos.push({ver, hor});
                    }
                }
            }
        }
    }

    return count > 1;
}

int solve(void) {
    int ret = INT_MAX   ;

    for(auto sl : sea_levels) {
        if(isValid(sl)) {
            ret = min(ret, sl);
        }
    }

    return ret == INT_MAX ? -1 : ret;
}


int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    matrix.assign(n, vector<int>(m, 0));
    sea_levels.insert(0);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> matrix[i][j];
            sea_levels.insert(matrix[i][j]);
            if(i == 0 || i == n-1 || j == 0 || j == m-1) {
                sea.push_back(Node(i,j,matrix[i][j]));
            }
        }
    }

    cout << solve() << endl;

    return 0;
}
