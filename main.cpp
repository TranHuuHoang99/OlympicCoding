#include <bits/stdc++.h>

using namespace std;

class Solution {
    private:
        vector<int> moves = {0,1,0,-1,0};

    public:
        bool isValid(vector<vector<char>> &grid, vector<vector<bool>> &isVisited, int i, int j, int x, int y) {
            isVisited[i][j] = true;

            for(int index = 0; index < 4; index++) {
                int ver = i + moves[index];
                int hor = j + moves[index+1];
                if(
                    ver >= 0 &&
                    ver < grid.size() && 
                    hor >= 0 &&
                    hor < grid[0].size() && 
                    grid[ver][hor] == grid[i][j] &&
                    !(ver == x && hor == y)
                ) {
                    
                    if(isVisited[ver][hor] || isValid(grid, isVisited, ver, hor, i, j)) {
                        return true;
                    }
                }
            }

            return false;
        }

        bool containsCycle(vector<vector<char>>& grid) {
            vector<vector<bool>> isVisited(grid.size(), vector<bool>(grid[0].size(), false));

            for(int i = 0; i < grid.size(); i++) {
                for(int j = 0; j < grid[i].size(); j++) {
                    if(!isVisited[i][j] && isValid(grid, isVisited, i, j, -1, -1)) {
                        return true;
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
        // {{'a','a','a','a'}, {'a','b','b','a'}, {'a','b','b','a'}, {'a','a','a','a'}},
        // {{'c','c','c','a'},{'c','d','c','c'},{'c','c','e','c'},{'f','c','c','c'}},
        // {{'a','b','b'},{'b','z','b'},{'b','b','a'}},
        // {{'c','a','d'},{'a','a','a'},{'a','a','d'},{'a','c','d'},{'a','b','c'}},
        {{'b','a','c'},{'c','a','c'},{'d','d','c'},{'b','c','c'}}
    };

    // b a c
    // c a c 
    // d d c
    // b c c

    Solution solve;

    for(auto d : data) {
        cout << solve.containsCycle(d) << endl;
    }

    return 0;
}
