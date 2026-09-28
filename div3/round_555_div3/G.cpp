/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-09-30 22:14:32
**************************************************************************
*/
#include <bits/stdc++.h>
#define int long long
#define pi acos(-1.0)
using namespace std;

int n, m;
int getRowType(const vector<int>& row) {
    for (int j = 1; j < m; j++) {
        if (row[j] < row[j-1]) return -1;
    }
    int cnt1 = 0;
    for (int r : row) {
        if (r == 1) cnt1++;
    }
    if (cnt1 == 0) return 0;
    if (cnt1 == m) return 1;
    return 2;
}
void solve(void) {
    cin >> n >> m;
    vector<vector<int>> A(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> A[i][j];
        }
    }
    vector<vector<int>> configs;
    for (int i = 0; i <= m; i++) {
        vector<int> config(m);
        for (int j = 0; j < m; j++) {
            config[j] = j >= i ? 1 : 0;
        }
        // none flipped horizontal for the first row
        vector<int> getFlippedMask(m);
        vector<int> notFlippedMask(m);
        for (int j = 0; j < m; j++) {
            getFlippedMask[j] = A[0][j] ^ config[j];
            notFlippedMask[j] = !A[0][j] ^ config[j];
        }
        configs.push_back(getFlippedMask);
        configs.push_back(notFlippedMask);
    }
    for (vector<int> c : configs) {
        bool isValid = true;
        int expectedType = 0;
        string row_str = "";
        for (int i = 0; i < n; i++) {
            vector<int> notFlippedRow(m);
            vector<int> getFlippedRow(m);
            for (int j = 0; j < m; j++) {
                notFlippedRow[j] = A[i][j] ^ c[j];
                getFlippedRow[j] = !A[i][j] ^ c[j];
            }
            int notFlippedType = getRowType(notFlippedRow);
            int flippedType = getRowType(getFlippedRow);
            if (notFlippedType == -1 && flippedType == -1) {
                isValid = false;
                break;
            }
            if (expectedType == 0) {
                if (notFlippedType == 0) {
                    expectedType = 0;
                    row_str += '0';
                } else if (flippedType == 0) {
                    expectedType = 0;
                    row_str += '1';
                } else if (notFlippedType == 1 || notFlippedType == 2) {
                    expectedType = 1;
                    row_str += '0';
                } else if (flippedType == 1 || notFlippedType == 2) {
                    expectedType = 1;
                    row_str += '1';
                } else {
                    isValid = false;
                    break;
                }
            } else {
                if (notFlippedType == 1) {
                    expectedType = 1;
                    row_str += '0';
                } else if (flippedType == 1) {
                    expectedType = 1;
                    row_str += '1';
                } else {
                    isValid = false;
                    break;
                }
            }
        }
        if (isValid) {
            string col_str = "";
            for (int j = 0; j < m; j++) {
                col_str += c[j] == 1 ? '1' : '0';
            }
            cout << "YES\n";
            cout << row_str << '\n';
            cout << col_str << '\n';
            return;
        }
    }
    cout << "NO\n";
}
signed main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}





