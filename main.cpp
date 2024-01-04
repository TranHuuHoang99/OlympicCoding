#include <bits/stdc++.h>

using namespace std;

void _scan(string &value) {cin >> value;}
void _scan(int &value) {cin >> value;}
void _scan(char &value) {cin >> value;}
void _scan(char *value) {cin >> value;}


#define GET_MAX(a, b) (a > b ? a : b)
#define GET_MIN(a ,b) (a < b ? a : b)
#define scan_char(value) _scan(value)
#define scan_arr(N, _array_type) {for(int i = 0; i < N; i++) {scan_char(_array_type[i]);};}
#define loop(i, N) for(i; i < N; i++)

struct Node {
    int x = 0;
    int y = 0;
    Node *next = nullptr;

    Node() : x(0), y(0), next(nullptr) {};
};

int ver[4] = {1,0,-1,0};
int hor[4] = {0,1,0,-1};

int n = 0;
int m = 0;
vector<vector<int>> arr;

int solve(queue<Node*> q_, vector<vector<bool>> visited) {
    int ret = INT32_MAX;
    Node *temp = nullptr;
    int x_ = 0;
    int y_ = 0;

    while(!q_.empty()) {
        temp = q_.front();
        q_.pop();
        for(int i = 0; i < 4; i++) {
            x_ = temp->x + ver[i];
            y_ = temp->y + hor[i];
            if(x_ < 0 || x_ >= n) continue;
            if(y_ < 0 || y_ >= m) continue;
            if(!visited[x_][y_]) {
                arr[x_][y_] = arr[temp->x][temp->y] + 1;
                visited[x_][y_] = true;
                Node *cur = new Node();
                cur->x = x_;
                cur->y = y_;
                q_.push(cur);
            }

            if(arr[x_][y_] == 1 && ret > arr[temp->x][temp->y]) {
                ret = arr[temp->x][temp->y];
            }
        }
    }   

    return ret - 2;
}

int runCase(vector<int> start_point, vector<vector<bool>> visited) {
    int ret = 0;
    queue<Node*> q;
    queue<Node*> q_;
    Node *root = new Node();

    root->x = start_point[0];
    root->y = start_point[1];
    arr[root->x][root->y] = 2;
    q.push(root);

    Node *temp = nullptr;
    int x_ = 0;
    int y_ = 0;

    while(!q.empty()) {
        temp = q.front();
        q.pop();
        for(int i = 0; i < 4; i++) {
            x_ = temp->x + ver[i];
            y_ = temp->y + hor[i];

            if(x_ < 0 || x_ >= n) continue;
            if(y_ < 0 || y_ >= m) continue;
            if(arr[x_][y_] == 1) {
                arr[x_][y_] = 2;
                Node *cur = new Node();
                cur->x = x_;
                cur->y = y_;
                q.push(cur);
            } 

            if(!visited[x_][y_]) {
                arr[x_][y_] = arr[temp->x][temp->y] + 1;
                if(arr[x_][y_] == 2) {
                    cout << x_ << ", " << y_ << "\n";
                }
                visited[x_][y_] = true;
                Node *cur = new Node();
                cur->x = x_;
                cur->y = y_;
                q_.push(cur);
            }
        }
    }

    delete temp;

    ret = solve(q_, visited);

    return ret;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  
    cout.tie(NULL);

    scan_char(n);
    scan_char(m);

    vector<int> temp(m,0);
    vector<int> start_point(2,0);
    vector<vector<bool>> visited;
    vector<bool> t_visited(m, false);

    for(int i = 0; i < n; i++) {
        arr.push_back(temp);
        visited.push_back(t_visited);
        for(int j = 0; j < m; j++) {
            cin >> arr[i][j];
            if(arr[i][j] == 1) {
                start_point[0] = i;
                start_point[1] = j;
                visited[i][j] = true;
            }
        } 
    }
    

#ifdef HOANG_DEBUG
    auto start_pro = std::chrono::high_resolution_clock::now();
#endif

    cout << runCase(start_point, visited) << endl;

#ifdef HOANG_DEBUG
    auto stop_pro = std::chrono::high_resolution_clock::now();
    std::cout << "finished in : " << 
    std::chrono::duration_cast<std::chrono::milliseconds>(stop_pro-start_pro).count()
    << " ms \n";
#endif

    return 0;
}
