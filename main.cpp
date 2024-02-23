#include <bits/stdc++.h>

using namespace std;

class Solution {
    struct Node {
        char name;
        pair<int,int> pos;
        Node(char _name, pair<int,int> _pos) : name(_name), pos(_pos) {}
    };

    public:
        bool containsCycle(vector<vector<char>> &grid) {
            vector<pair<int,int>> moves = {{0,1}, {0,-1}, {1,0}, {-1,0}};
            map<char, Node*> _map;
            queue<Node*> q;
            Node *temp = nullptr;
            pair<int,int> steady_pos(0,0);
            int n = grid.size();
            int m = grid[0].size();
            vector<vector<bool>> isVisited(n, vector<bool>(m, false));

            for(int i = 0; i < grid.size(); i++) {
                for(int j = 0; j < grid[i].size(); j++) {
                    if(_map.find(grid[i][j]) == _map.end()) {
                        _map[grid[i][j]] = new Node(grid[i][j], {i,j});
                    }
                }
            }

            for(auto sub_m : _map) {
                q.push(sub_m.second);
                steady_pos = sub_m.second->pos;
                int count = 0;

                while(!q.empty()) {
                    temp = q.front();
                    count++;
                    isVisited[temp->pos.first][temp->pos.second] = true;
                    q.pop();

                    for(int i = 0; i < 4; i++) {
                        int ver = temp->pos.first + moves[i].first;
                        int hor = temp->pos.second + moves[i].second;

                        if(ver < 0 || ver >= n || hor < 0 || hor >= m) continue;

                        if(grid[ver][hor] == temp->name && ver == steady_pos.first && hor == steady_pos.second && count >= 4) {
                            return true;
                        }

                        if(!isVisited[ver][hor] && grid[ver][hor] == temp->name) {
                            q.push(new Node(temp->name, {ver, hor}));
                            isVisited[ver][hor] = true;
                            break;
                        }
                    }
                }
            }

            return false;
        }
};

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<vector<vector<char>>> data = {
        {{'a','a','a','a'}, {'a','b','b','a'}, {'a','b','b','a'}, {'a','a','a','a'}},
        {{'c','c','c','a'},{'c','d','c','c'},{'c','c','e','c'},{'f','c','c','c'}},
        {{'a','b','b'},{'b','z','b'},{'b','b','a'}},
        {{'c','a','d'},{'a','a','a'},{'a','a','d'},{'a','c','d'},{'a','b','c'}}
    };

    Solution solve;

    for(auto d : data) {
        cout << solve.containsCycle(d) << endl;
    }


    return 0;
}
