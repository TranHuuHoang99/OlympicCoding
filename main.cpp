#include <bits/stdc++.h>

using namespace std;

struct Node {
    int x,y,value;
    bool operator < (const Node &a) const {
        return a.value < value;
    }
};

int M,N;
vector<vector<int>> A;
vector<vector<int>> B;
vector<vector<int>> ret;
vector<pair<int,int>> moves = {{1,0}, {-1,0}, {0,1}, {0,-1}};

int solve(void) {
    int res = INT32_MAX;
    priority_queue<Node> q;
    ret[M][N-1] = 0;
    q.push({M,N-1, ret[M][N-1]});

    while(!q.empty()) {
        auto [x,y,value] = q.top();
        q.pop();

        if(x == 0) res = min(res, value);

        for(int i = 0; i < moves.size(); i++) {
            int ver = x + moves[i].first;
            int hor = y + moves[i].second;

            if(ver >= 0 && ver <= M && hor >= 0 && hor < N) {
                if(i == 0) {
                    if(ret[ver][hor] > value + A[ver][hor]) {
                        ret[ver][hor] = value + A[ver][hor];
                        q.push({ver,hor, ret[ver][hor]});
                    }
                } else if(i ==1) {
                    if(ret[ver][hor] > value + A[ver+1][hor]) {
                        ret[ver][hor] = value + A[ver+1][hor];
                        q.push({ver,hor,ret[ver][hor]});
                    }
                } else if(i == 2) {
                    if(ret[ver][hor] > value + B[ver][hor-1]) {
                        ret[ver][hor] = value + B[ver][hor-1];
                        q.push({ver,hor,ret[ver][hor]});
                    }
                } else {
                    if(ret[ver][hor] > value + B[ver][hor]) {
                        ret[ver][hor] = value + B[ver][hor];
                        q.push({ver,hor,ret[ver][hor]});
                    }
                }
            }
        }
    }

    return res;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> M >> N;
    A.assign(M+1, vector<int>(N, 0));
    B.assign(M+1, vector<int>(N-1,0));
    ret.assign(M+1, vector<int>(N, INT32_MAX));

    for(int i = 1; i <= M*2; i++) {
        if(i%2 == 0) {
            for(int j = 0; j < N-1; j++) {
                cin >> B[i/2][j];
            }
        } else {
            for(int j = 0; j < N; j++) {
                cin >> A[(i+1)/2][j];
            }
        }
    }

    cout << solve() << endl;

    return 0;
}
