#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct Node {
    int x,y;
    ll value;
    bool operator < (const Node &a) const  {
        return a.value < value;
    }
};

int N, M;
vector<vector<ll>> matrix;
vector<vector<ll>> dp;
vector<int> moves = {1,0,-1,0,1};

ll solve(void) {
    dp[0][0] = matrix[0][0];
    priority_queue<Node> q;
    q.push({0,0, dp[0][0]});

    while(!q.empty()) {
        auto [x,y,value] = q.top();
        q.pop();

        for(int i = 0; i < 4; i++) {
            int ver = x + moves[i];
            int hor = y + moves[i+1];

            if(ver >= 0 && ver < N && hor >=0 && hor < M) {
                if(dp[ver][hor] > matrix[ver][hor] + value) {
                    dp[ver][hor] = matrix[ver][hor] + value;
                    q.push({ver,hor, dp[ver][hor]});
                }
            }
        }
    }

    return dp[N-1][M-1];
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    matrix.assign(N, vector<ll>(M, 0));
    dp.assign(N, vector<ll>(M, LLONG_MAX));

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> matrix[i][j];
        }
    }

    cout << solve() << endl;

    return 0;
}
