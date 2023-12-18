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

uint128_type runCase(vector<int> arr) {
    uint128_type ret = 0;
    int min = INT32_MAX;
    int max = INT32_MIN;
    bool isUp = true;
    vector<int> path;

    for(int i = 0; i < n; i++) {
        if(isUp) {
            if(arr[i] > max) {
                max = arr[i];
            } else {
                path.push_back(i-1);
                isUp = false;
                min = arr[i];
            }
        } else {
            if(arr[i] < min) {
                min = arr[i];
            } else {
                path.push_back(i-1);
                isUp = true;
                max = arr[i];
            }
        }
    }

    if(path.back() != n-1 && arr[path.back()] > arr[n-1]) path.push_back(n-1);

    for(int i = 1; i < path.size(); i++) {
        ret += (path[i] - path[i-1]);
    }

    return ret;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  
    cout.tie(NULL);

    scan_char(n);
    vector<int> arr(n, 0);
    scan_arr(n, arr);

#ifdef HOANG_DEBUG
    auto start_pro = std::chrono::high_resolution_clock::now();
#endif

    cout << runCase(arr) << endl;

#ifdef HOANG_DEBUG
    auto stop_pro = std::chrono::high_resolution_clock::now();
    std::cout << "finished in : " << 
    std::chrono::duration_cast<std::chrono::milliseconds>(stop_pro-start_pro).count()
    << " ms \n";
#endif

    return 0;
}
