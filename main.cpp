#include <bits/stdc++.h>
#include <memory>
#define int long long

using namespace std;

int n = 0;

vector<int> ver = {0,0,-1,1};
vector<int> hor = {-1,1,0,0};

struct pos {
    int x;
    int y;
    pos(int x_, int y_) : x(x_), y(y_) {}
};

struct cell {
    int value;
    vector<shared_ptr<pos>> possible;
    cell(int value_) : value(value_) {};
};

int solve(vector<vector<int>> lands, vector<shared_ptr<cell>> cells, vector<bool> isExisted) {
    int ret = INT32_MIN;
    vector<vector<bool>> temp_visited(n, vector<bool>(n,false));
    vector<vector<bool>> isVisited = temp_visited;
    int total = 0;
    queue<shared_ptr<pos>> q;
    shared_ptr<pos> temp = nullptr;
    queue<int> ret_q;

    for(int i = 0; i < isExisted.size(); i++) {
        if(!isExisted[i]) continue;
        total = 0;
        isVisited = temp_visited;
        temp = nullptr;

        for(auto &_pos : cells[i]->possible) {
            if(!isVisited[_pos->x][_pos->y]) {
                total++;
                q.push(_pos);
                isVisited[_pos->x][_pos->y] = true;
            }

            while(!q.empty()) {
                temp = q.front();
                q.pop();

                for(int j = 0; j < 4; j++) {
                    if(temp->x+ver[j] >= n || temp->x+ver[j] < 0) continue;
                    if(temp->y+hor[j] >= n || temp->y+hor[j] < 0) continue;
                    
                    if(lands[temp->x+ver[j]][temp->y+hor[j]] - i <= 0) {
                        isVisited[temp->x+ver[j]][temp->y+hor[j]] = true;
                    }

                    if(!isVisited[temp->x+ver[j]][temp->y+hor[j]]) {
                        q.push(make_shared<pos>(temp->x+ver[j], temp->y+hor[j]));
                        isVisited[temp->x+ver[j]][temp->y+hor[j]] = true;
                    }
                }
            }
        }

        if(total > ret) {
            if(!ret_q.empty()) ret_q.pop();
            ret = total;
            ret_q.push(i);
        } else if(total == ret) {
            ret_q.push(i);
        } else {
            //DO NOTHING
        }
    }

    int res = INT32_MAX;

    while(!ret_q.empty()) { 
        res = min(res, ret_q.front());
        ret_q.pop();
    }

    return res;
}

int32_t main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    vector<bool> isExisted(11, false);
    vector<shared_ptr<cell>> cells;
    vector<vector<int>> lands(n, vector<int>(n, 0));

    for(int i = 0; i <= 10; i++) {
        cells.push_back(make_shared<cell>(i));
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> lands[i][j];
            isExisted[lands[i][j]] = true;
            for(auto &_cell : cells) {
                if(lands[i][j] - _cell->value > 0) {
                    _cell->possible.push_back(make_shared<pos>(i,j));
                } 
            }
        }
    }

    cout << solve(lands, cells, isExisted) << endl;

    return 0;
}

