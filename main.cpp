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

int n = 0;

int runCase(vector<int> arr) {
    int ret = 0;
    int min = INT32_MAX;
    int max = INT32_MIN;
    bool isUp = true;

    for(int i = 0; i < n; i++) {
        if(isUp) {
            if(arr[i] > max) {
                max = arr[i];
                if(i == n-1) ret += max;
            } else {
                ret += arr[i-1];
                isUp = false;
                min = arr[i];
            }
        } else {
            if(arr[i] < min) {
                min = arr[i];
            } else {
                ret -= arr[i-1];
                if(i == n-1) ret += arr[i];
                isUp = true;
                max = arr[i];
            }
        }
    }

    return ret;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    scan_char(n);
    vector<int> arr(n);
    scan_arr(n, arr);

    cout << runCase(arr) << endl;

    return 0;
}
