#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n = 0, x = 0;

struct Node {
    int x;
    int y;
    int visits;
    Node(int _x = 0, int _y = 0, int _visits = 0) : x(_x), y(_y), visits(_visits) {}
};

vector<Node> path;
vector<bool> isVisited;
Node des;
Node start;

bool isValid(Node from, Node to) {
    return abs(from.x - to.x) + abs(from.y - to.y) <= x;
}

int solve(void) {
    queue<Node> q;
    q.push(start);

    Node temp;
    while(!q.empty()) {
        temp = q.front();
        q.pop();

        for(int i = 0; i <= n; i++) {
            if(!isVisited[i] && isValid(temp, path[i])) {
                isVisited[i] = true;
                path[i].visits = temp.visits + 1;
                q.push(path[i]);
                if(path[i].x == des.x && path[i].y == des.y) return path[i].visits - 1;
            }
        }
    }

    return -1;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> x;
    cin >> des.x >> des.y;
    des.visits = 0;

    isVisited.assign(n+1, false);

    int temp_x = 0;
    int temp_y = 0;
    for(int i = 0; i < n; i++) {
        cin >> temp_x >> temp_y;
        path.push_back(Node(temp_x, temp_y, 0));
    }
    path.push_back(des);

    cout << solve() << endl;

    return 0;
}
