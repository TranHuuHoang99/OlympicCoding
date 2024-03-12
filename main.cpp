#include <bits/stdc++.h>

using namespace std;

struct Node {
    pair<int,int> pos;
    int value;
    Node(pair<int,int> _pos, int _value) : pos(_pos), value(_value) {}
};

int n = 0;
vector<vector<int>> lands;
set<int> walls;
vector<int> moves = {-1,0,1,0,-1};
vector<Node> nodes;

bool compare(pair<int,int> a, pair<int,int> b) {
    if(a.first > b.first) {
        return true;
    } else if(a == b) {
        return a.second < b.second;
    } else {
        return false;
    }

    return false;
}

int solve(void) {
    vector<pair<int,int>> ret;
    queue<pair<int,int>> q;
    vector<vector<bool>> temp_visited(n, vector<bool>(n, false));
    vector<vector<bool>> isVisited;

    for(auto w : walls) {
        int count = 0;
        isVisited = temp_visited;
        pair<int,int> temp;

        for(auto node : nodes) {
            if(!isVisited[node.pos.first][node.pos.second] && node.value > w) {
                count++;
                q.push({node.pos.first, node.pos.second});
                isVisited[node.pos.first][node.pos.second] = true;
            }

            while(!q.empty()) {
                temp = q.front();
                q.pop();

                for(int i = 0; i < 4; i++) {
                    int ver = temp.first + moves[i];
                    int hor = temp.second + moves[i+1];

                    if(ver < 0 || ver >= n || hor < 0 || hor >= n) continue;

                    if(!isVisited[ver][hor] && lands[ver][hor] > w) {
                        q.push({ver, hor});
                        isVisited[ver][hor] = true;
                    }
                }
            }   
        }

        ret.push_back({count, w});
    }

    sort(ret.begin(), ret.end(), compare);

    return ret[0].second;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    lands.assign(n, vector<int>(n, 0)); 

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> lands[i][j];
            walls.insert(lands[i][j]);
            nodes.push_back(Node({i,j}, lands[i][j]));
        }
    }

    cout << solve() << endl;

    return 0;
}
