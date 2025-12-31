/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2025-11-04 22:35:01
**************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

string sample_str = "miurT";
int n;
string str;
void solve(void) {
    cin >> n >> str;
    sort(sample_str.begin(), sample_str.end());
    sort(str.begin(), str.end());
    if (sample_str == str) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) solve();
    return 0;
}





