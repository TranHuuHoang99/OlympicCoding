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

int solve(char *arr, const int len, char color) {
    int begin = INT32_MIN;
    int end = INT32_MIN;
    int ver = INT32_MIN;
    int hor = 0;
    int min_hor = INT32_MAX;
    int min_len = 0;
    int max_len = 0;
    bool isOnly_zero = true;

    for(int i = 0; i < len; i++) {
        if(arr[i] != '0') isOnly_zero = false;
        if(begin == INT32_MIN && arr[i] == color) begin = i;
        if(arr[i] == color && i > end) end = i;
        if(arr[i] == color && i/n + 1 > ver) ver = i/n +1;
        if(arr[i] == color && (i/n + 1) * n - i < min_hor) {
            min_hor = (i/n + 1) * n - i;
            max_len = i;
        }
        if(arr[i] == color && (i/n + 1) * n - i > hor) {
            hor = (i/n + 1) * n - i; 
            min_len = i;
        }
    }

    if(color == '0' && !isOnly_zero) return 0;

    hor -= (min_hor-1);
    ver -= begin / n;   

    int temp_end = end - (end/n - max_len/n) * n;
    int temp_begin = min_len - (min_len/n - begin/n) * n;

    while(begin > temp_begin) {
        begin--;
    }

    while(temp_end < max_len) {
        end++;
        temp_end++;
    }

    for(int i = 0; begin + i*n <= begin + ((ver-1)*n); i++) {
        for(int j = begin + i*n; j < begin + i*n + hor; j++) {
            if(arr[j] != color) {
                return 0;
            }
        }   
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
            if(arr[i] == colors[j]) {
                temp += 1;
                break;
            }
        }
        if(temp != i) continue;
        if(static_cast<int>(arr[i]-'0') >= 0) colors.push_back(arr[i]);
    }
    
    for(int i = 0; i < colors.size(); i++) ret += solve(arr, len, colors[i]);

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
