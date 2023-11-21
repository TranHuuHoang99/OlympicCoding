#include <bits/stdc++.h>

using Int64_type = long;
using Int128_type = long long;
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

int solve(char *arr, const int len, char color, vector<char> &colors, int &index) {
    int begin = INT32_MIN;
    int end = INT32_MIN;

    for(int i = 0; i < len; i++) {
        if(begin == INT32_MIN && arr[i] == color) begin = i;
        if(arr[i] == color && i > end) end = i;
    }

    int row_begin = begin / n;
    int row_end = end / n;
    int sub_len = end - (begin + (row_end - row_begin) * n) + 1; 
    int add = 0;

    for(int i = row_begin; i <= row_end; i++) {
        for(int j = add * n + begin; j < add * n + begin + sub_len; j++) {
            if(arr[j] != color) {   
                for(int k = index+1; k < colors.size(); k++) {
                    if(arr[j] == colors[k]) {
                        index++;
                        swap(colors[index], colors[k]);
                        break;
                    }
                }
            }
        }
        add++;
    }

    return 1;
}

int runCase(char *arr) {
    int ret = 0;
    const int len = n*n;
    vector<char> colors;
    int temp = 0;

    for(int i = 0; i < len; i++) {
        temp = i;
        for(int j = 0; j < colors.size(); j++) {
            if(arr[i] == colors[j] || arr[i] == '0') {
                temp += 1;
                break;
            }
        }
        if(temp != i) continue;
        if(static_cast<int>(arr[i]-'0') > 0) colors.push_back(arr[i]);
    }
    
    for(int i = 0; i < colors.size(); i++) ret += solve(arr, len, colors[i], colors, i);

    return ret;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  

    scan_char(n);

    char temp[n];
    char arr[n*n];

    memset(temp, 0, n);
    memset(arr, 0, n*n);

    int j = 0;
    for(int i = 0; i < n; i++) {
        cin >> temp;
        memcpy(&arr[j], temp, n);
        memset(temp, 0, n);
        j += n;
    }   

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
