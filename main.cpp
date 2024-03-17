#include <bits/stdc++.h>

using namespace std;

struct Node {
    int x;
    int y;
    char name;
    int value;
    Node(int _x = 0, int _y = 0, int _value = 0, char _name = 0) : x(_x), y(_y), value(_value), name(_name) {}
};

int r = 0, c = 0, n = 0;
vector<int> moves = {1,0,-1,0,1};
vector<vector<char>> matrix;
vector<Node> starts;
vector<vector<int>> dp;

bool isShrine(const char &a) {
    return a >= '0' && a <= '9';
} 

int solve(void) {
    if(n <= 1) return 0;
    int ret = INT_MAX;
    queue<Node> q;
    dp.assign(10, vector<int>(10, 0));

    for(auto s : starts) {
        vector<vector<bool>> isVisited(r, vector<bool>(c, false));
        isVisited[s.x][s.y] = true;
        q.push(s);
        Node temp;
        
        while(!q.empty()) {
            temp = q.front();
            q.pop();
            
            for(int i = 0; i < 4; i++) {
                int ver = temp.x + moves[i];
                int hor = temp.y + moves[i+1];
                
                if(ver >= 0 && ver < r && hor >= 0 && hor < c && matrix[ver][hor] != '#') {
                    if(!isVisited[ver][hor]) {
                        Node next(ver,hor,temp.value+1,matrix[ver][hor]);
                        isVisited[next.x][next.y] = true;
                        q.push(next);

                        if(isShrine(next.name)) {
                            dp[s.name-'0'][next.name-'0'] = next.value;
                        }
                    }
                }
            }
        }
    }

    vector<int> order(n, 0);
    iota(order.begin(), order.end(), 1);
    
    do {    
        int dis = 0;
        for(int i = 0; i < order.size()-1; i++) {
            if(dp[order[i]][order[i+1]] != 0) {
                dis += dp[order[i]][order[i+1]];
            } else {
                return -1;
            }
        }

        ret = min(ret, dis);

    } while(next_permutation(order.begin(), order.end()));

    return ret == 0 ? -1 : ret;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> r >> c >> n;
    matrix.assign(r, vector<char>(c, 0));
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            cin >> matrix[i][j];
            if(isShrine(matrix[i][j])) {
                starts.push_back(Node(i,j,0,matrix[i][j]));
            }
        }
    }

    cout << solve() << endl;

    return 0;
}
