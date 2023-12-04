#include <bits/stdc++.h>

using int64_type = long;
using int128_type = long long;
using uint64_type = unsigned long;
using sint64_type = signed long;
using uint128_type = unsigned long long;
using sint128_type = signed long long;

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

int runCase(vector<vector<int> > arr, vector<vector<bool> > visited, vector<vector<int> > ret_arr) {
    int ret = 0;
    int hor = 0;
    int ver = 0;

    queue<vector<int> > path;
    vector<int> temp(2,0);
    vector<int> second_fac;

    path.push({0,0});
    visited[0][0] = true;

    while(!path.empty()) {
        temp = path.front();
        path.pop();

        if(temp[0]-1 >= 0 && temp[1]-1 >= 0) {
            if(arr[temp[0]][temp[1]] + ret_arr[temp[0]-1][temp[1]] < ret_arr[temp[0]][temp[1]]) {
                ret_arr[temp[0]][temp[1]] = arr[temp[0]][temp[1]] + ret_arr[temp[0]-1][temp[1]];
            }

            if(arr[temp[0]][temp[1]] + ret_arr[temp[0]][temp[1]-1] < ret_arr[temp[0]][temp[1]]) {
                ret_arr[temp[0]][temp[1]] = arr[temp[0]][temp[1]] + ret_arr[temp[0]][temp[1]-1];
            }

        } else if(temp[0]-1 >= 0) {
            ret_arr[temp[0]][temp[1]] = arr[temp[0]][temp[1]] + ret_arr[temp[0]-1][temp[1]];
        } else if(temp[1]-1 >= 0) {
            ret_arr[temp[0]][temp[1]] = arr[temp[0]][temp[1]] + ret_arr[temp[0]][temp[1]-1];
        } else {
            ret_arr[temp[0]][temp[1]] = arr[temp[0]][temp[1]];
        }
        
        if(temp[1] < n-1 && !visited[temp[0]][temp[1]+1]) {
            path.push({temp[0], temp[1]+1});
            visited[temp[0]][temp[1]+1] = true;
        }

        if(temp[0] < n-1 && !visited[temp[0]+1][temp[1]]) {
            path.push({temp[0]+1, temp[1]});
            visited[temp[0]+1][temp[1]] = true;
        }
    }

    return ret_arr[n-1][n-1];
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  
    cout.tie(NULL);

    scan_char(n);
    char temp[n];
    vector<vector<int> > arr(n);
    vector<vector<bool> > visited(n);
    vector<vector<int> > ret_arr(n);
    
    for(int i = 0; i < n; i++) {
        memset(temp, 0, n);
        cin >> temp;

        for(int j = 0; j < n; j++) {
            arr[i].push_back(static_cast<int>(temp[j]-'0'));
            visited[i].push_back(false);
            ret_arr[i].push_back(INT32_MAX);
        }
    }

#ifdef HOANG_DEBUG
    auto start_pro = std::chrono::high_resolution_clock::now();
#endif

    cout << runCase(arr, visited, ret_arr) << endl;

#ifdef HOANG_DEBUG
    auto stop_pro = std::chrono::high_resolution_clock::now();
    std::cout << "finished in : " << 
    std::chrono::duration_cast<std::chrono::milliseconds>(stop_pro-start_pro).count()
    << " ms \n";
#endif

    return 0;
}
