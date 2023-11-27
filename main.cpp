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
map<int, int> ret;

void _insert(map<int, int> &ret_map, int i, int j) {
    ret_map.clear();
    ret_map.insert(std::pair<int, int>(i,j));
}

void runCase(vector<int128_type> arr) {
    int128_type min = LLONG_MAX; // positive
    int128_type max = LLONG_MIN; // negative
    map<int, int> ret_pos;
    map<int, int> ret_neg;

    const int len = n / 2;

    int i = 0;
    int j = n-1;
    int128_type temp = 0;

    while(i < j) {
        temp = arr[i] + arr[j];
        if(temp == 0) {
            _insert(ret, i, j);
            return;
        }

        if(temp < 0) {
            if(temp > max) {
                max = temp;
                _insert(ret_neg, i, j);
            }
            i++;
        } else {
            if(temp < min) {
                min = temp;
                _insert(ret_pos, i, j);
            }
            j--;
        }
    }

    int128_type sum_pos = 0;
    int128_type sum_neg = 0;

    if(ret_pos.size() > 0 && ret_neg.size() > 0) {
        sum_pos = arr[ret_pos.begin()->first] + arr[ret_pos.begin()->second];
        sum_neg = (arr[ret_neg.begin()->first] + arr[ret_neg.begin()->second]) * (-1);

        if(sum_neg == sum_pos) {
            ret = ret_neg.begin()->first < ret_pos.begin()->first ? ret_neg : ret_pos;
        } else if(sum_neg < sum_pos) {
            ret = ret_neg;
        } else {
            ret = ret_pos;
        }
    }

    if(ret_pos.size() > 0 && ret_neg.size() <= 0) {
        ret = ret_pos;
    } 

    if(ret_pos.size() <= 0 && ret_neg.size() > 0) {
        ret = ret_neg;
    }

    return;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  
    cout.tie(NULL);

    scan_char(n);
    vector<int128_type> arr(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

#ifdef HOANG_DEBUG
    auto start_pro = std::chrono::high_resolution_clock::now();
#endif

    runCase(arr);   
    cout << ret.begin()->first << " " << ret.begin()->second << endl;

#ifdef HOANG_DEBUG
    auto stop_pro = std::chrono::high_resolution_clock::now();
    std::cout << "finished in : " << 
    std::chrono::duration_cast<std::chrono::milliseconds>(stop_pro-start_pro).count()
    << " ms \n";
#endif

    return 0;
}
