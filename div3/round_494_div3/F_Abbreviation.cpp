/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-02-02 21:15:14
**************************************************************************
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 310;
int n;
string str[N];
bool isEqual[N][N];
int F[N][N];
void solve(void) {
    cin >> n;
    memset(isEqual, 0, sizeof(isEqual));
    memset(F, 0, sizeof(F));
    int sum = n-1;
    for (int i = 0; i < n; i++) {
        cin >> str[i];
        sum += str[i].size();
    }
    for (int i = 0; i < n; i++) {
        isEqual[i][i] = true;
        for (int j = 0; j < i; j++) {
            isEqual[i][j] = isEqual[j][i] = bool(str[i] == str[j]);
        }
    }
    for (int i = n-1; i >= 0; i--) {
        for (int j = n-1; j >= 0; j--) {
            if (!isEqual[i][j]) continue;
            if (i+1 < n && j+1 < n) {
                F[i][j] = F[i+1][j+1] + 1;
            } else {
                F[i][j] = 1;
            }
        }
    }
    int ret = sum;
    for (int i = 0; i < n; i++) {
        int sum_len_word = 0;
        for (int len = 0; len+i < n; len++) {
            sum_len_word += str[i+len].size();
            int cnt = 1;
            for (int j = i+len+1; j < n; j++) {
                if (F[i][j] > len) {
                    cnt++;
                    j += len;
                }
            }
            // sum - time_repeat * total len of each word + time_repeat * (total_number_of_word) - time_repeat * space
            int min_val = sum - cnt * sum_len_word + (len+1) * cnt - len * cnt;
            if (cnt > 1) ret = min(ret, min_val);
        }
    }
    cout << ret << endl;
}

signed main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}





