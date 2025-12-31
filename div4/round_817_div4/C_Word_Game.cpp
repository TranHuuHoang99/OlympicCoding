/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2025-11-04 22:49:15
**************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll N = 1e3+10;
int n;
map<string,int> save;
string A[N], B[N], C[N];
void solve(void) {
    cin >> n;    
    save.clear();
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
        save[A[i]]++;
    }
    for (int i = 1; i <= n; i++) {
        cin >> B[i];
        save[B[i]]++;
    } 
    for (int i = 1; i <= n; i++) {
        cin >> C[i];
        save[C[i]]++;
    }
    int val1 = 0, val2 = 0, val3 = 0;  
    for (int i = 1; i <= n; i++) {
        if (save[A[i]] == 1) {
            val1 += 3;
        } else if (save[A[i]] == 2) {
            val1 += 1;
        }
        if (save[B[i]] == 1) {
            val2 += 3;
        } else if (save[B[i]] == 2) {
            val2 += 1;
        }
        if (save[C[i]] == 1) {
            val3 += 3;
        } else if (save[C[i]] == 2) {
            val3 += 1;
        }
    }
    cout << val1 << ' ' << val2 << ' ' << val3 << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) solve();
    return 0;
}





