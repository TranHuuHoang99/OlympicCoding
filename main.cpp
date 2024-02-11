#include <bits/stdc++.h>
#include <memory>
#define int long long

using namespace std;

int n = 0;

struct Node {
    int x;
    int y;

    Node(int _x, int _y) : x(_x), y(_y) {}
    Node() : x(0), y(0) {}
};

int solve(vector<shared_ptr<Node>> points, vector<shared_ptr<Node>> starts, vector<int> pos) {
    int ret = INT32_MAX;
    const shared_ptr<Node> A = make_shared<Node>(starts[0]->x, starts[0]->y);
    const shared_ptr<Node> B = make_shared<Node>(starts[1]->x, starts[1]->y);
    const vector<int> temp_pos = pos;

    for(int index = 0; index <= n; index++) {
        do { 
            int sum = 0, temp = 0, pow = 0;
            starts[0] = A;
            for(int i = 0; i < index; i++) {
                temp = abs(starts[0]->x - points[pos[i]]->x) + abs(starts[0]->y - points[pos[i]]->y); 
                sum += (temp * pow);
                starts[0] = points[pos[i]];
                pow++;
            }
            temp = abs(starts[0]->x - A->x) + abs(starts[0]->y - A->y); 
            sum += (temp * pow);

            pow = 0;
            starts[1] = B;
            for(int i = index; i < n; i++) {
                temp = abs(starts[1]->x - points[pos[i]]->x) + abs(starts[1]->y - points[pos[i]]->y);
                sum += (temp * pow);
                starts[1] = points[pos[i]];
                pow++;
            }   
            temp = abs(starts[1]->x - B->x) + abs(starts[1]->y - B->y);
            sum += (temp * pow);
            
            if(sum < ret) ret = sum;
            
        } while(next_permutation(pos.begin(), pos.end()));
        pos = temp_pos;
    }


    return ret;
}

int32_t main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    vector<shared_ptr<Node>> points;
    vector<shared_ptr<Node>> starts;
    vector<int> pos(n, 0);
    int temp_x = 0;
    int temp_y = 0;

    for(int i = 0; i < n; i++) {
        cin >> temp_x >> temp_y;
        points.push_back(make_shared<Node>(temp_x, temp_y));
        pos[i] = i;
    }

    for(int i = 0; i < 2; i++) {
        cin >> temp_x >> temp_y;
        starts.push_back(make_shared<Node>(temp_x, temp_y));
    }

    cout << solve(points, starts, pos) << endl;

    return 0;
}

