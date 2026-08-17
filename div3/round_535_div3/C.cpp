/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-08-20 22:56:14
**************************************************************************
*/
#include <bits/stdc++.h>
#define int long long
#define pi acos(-1.0)
using namespace std;

int n;
string str;
vector<char> A = {'R', 'G', 'B'};
void solve(void) {
    cin >> n >> str;
    vector<string> save;
    sort(A.begin(), A.end());
    do {
        string temp = "";
        for (int i = 0; i < 3; i++) temp += A[i];
        save.push_back(temp);
    } while (next_permutation(A.begin(), A.end()));
    int ret = INT32_MAX;
    string ret_str = "";
    for (int i = 0; i < save.size(); i++) {
        string temp = "";
        int diff = 0;
        for (int j = 0; j < n; j++) {
            temp += save[i][j%3];
            if (save[i][j%3] != str[j]) diff++;
        }
        if (diff < ret) {
            ret_str = temp;
            ret = diff;
        }
    }
    cout << ret << '\n';
    cout << ret_str << '\n';
}
signed main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}





