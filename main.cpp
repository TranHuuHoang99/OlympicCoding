#include <bits/stdc++.h>
#include <memory>

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

int n = 0;
int m = 0;

struct Node {
    int start;
    vector<int> des;
    vector<int> dis;

    Node(int start_) : start(start_) {}
    Node() : start(0) {}
};

vector<shared_ptr<Node>> path;

int runCase() {
    int ret = INT32_MAX;    
    vector<bool> visited(n,false);  
    vector<int> arr(n, INT32_MAX);
    queue<shared_ptr<Node>> q;
    
    shared_ptr<Node> temp = nullptr;
    vector<shared_ptr<Node>> get_min;
    int min = INT32_MAX;
    int max = INT32_MIN;
    int index_min = 0;
    
    for(int k = 0; k < n; k++) {
        visited = vector<bool>(n, false);
        arr = vector<int>(n,INT32_MAX);
        max = INT32_MIN;
        q.push(path[k]);
        arr[q.front()->start] = 0;
        visited[q.front()->start] = true;

        while(!q.empty()) {
            min = INT32_MAX;
            temp = q.front();
            q.pop();

            for(int i = 0; i < temp->des.size(); i++) {
                if(arr[temp->des[i]] > arr[temp->start] + temp->dis[i]) {
                    arr[temp->des[i]] = arr[temp->start] + temp->dis[i];
                }

                if(!visited[temp->des[i]]) {
                    get_min.push_back(path[temp->des[i]]);
                    visited[temp->des[i]] = true;
                }
            }

            for(int i = 0; i < get_min.size(); i++) {
                if(min > arr[get_min[i]->start]) {
                    min = arr[get_min[i]->start];
                    index_min = i;
                }
            }

            if(!get_min.empty()) {
                q.push(get_min[index_min]);
                get_min.erase(get_min.begin()+index_min);
            }
        }

        for(int i = 0; i < arr.size(); i++) {
            if(max < arr[i]) max = arr[i];
        }

        if(ret > max) ret = max;
    }

    return ret;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  
    cout.tie(NULL);

    scan_char(n);
    scan_char(m);
    
    vector<int> temp(3,0);

    for(int i = 0; i < n; i++) {
        path.push_back(make_shared<Node>());
        path[i]->start = i;
        path[i]->des.push_back(i);
        path[i]->dis.push_back(0);
    }

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < 3; j++) {
            cin >> temp[j];
        }

        path[temp[0]-1]->des.push_back(temp[1]-1);
        path[temp[0]-1]->dis.push_back(temp[2]);

        path[temp[1]-1]->des.push_back(temp[0]-1);
        path[temp[1]-1]->dis.push_back(temp[2]);
    }

#ifdef HOANG_DEBUG
    auto start_pro = std::chrono::high_resolution_clock::now();
#endif

    cout << runCase() << endl;

#ifdef HOANG_DEBUG
    auto stop_pro = std::chrono::high_resolution_clock::now();
    std::cout << "finished in : " << 
    std::chrono::duration_cast<std::chrono::milliseconds>(stop_pro-start_pro).count()
    << " ms \n";
#endif

    return 0;
}
