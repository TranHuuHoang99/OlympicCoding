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

int n = 0;

int64_t runCase(vector<int64_t> arr) {
    int64_t ret = 0;
    list<int64_t> l;
    int64_t max = INT64_MIN;
    int index_max = 0;
    arr.push_back(INT64_MAX);
    l.push_back(0);

    for(int i = 1; i <= n; i++) {
        if(arr[i] >= arr[l.front()]) {
            max = INT64_MIN;
            index_max = 0;
            while(!l.empty()) {
                if(arr[l.back()] > max) {
                    ret += (i-l.back()-1);
                    cout << " l.back() : " << l.back() << ",  : " << (i-l.back()-1) << endl;
                } else {
                    ret += (index_max-l.back()-1);
                    cout << "index_max : " << index_max << ", l.back() : " << l.back() << ", " <<(index_max-l.back()-1) << endl;
                }

                if(arr[l.back()] >= max) {
                    max = arr[l.back()];
                    index_max = l.back();
                }

                l.pop_back();
            }
        }

        l.push_back(i);
    }

    return ret;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  
    cout.tie(NULL);

    scan_char(n);
    vector<int64_t> arr(n, 0);
    for(int i = 0; i < n; i++) cin >> arr[i];

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
