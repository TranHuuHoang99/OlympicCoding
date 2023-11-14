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
