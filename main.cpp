#include <bits/stdc++.h>

using namespace std;

vector<int> res;

void solve(vector<int> code, int len) {
    vector<int> dp(len+1, 0);
    dp[0] = 1;

    for(int i = 1; i <= len; i++) {
        if(i - 2 >= 0 ) {
            if(code[i-2] == 1 || (code[i-2] == 2 && code[i-1] <= 6)) {
                dp[i] += dp[i-2];
            }
        }

        if(code[i-1] != 0) dp[i] += dp[i-1];
    }

    res.push_back(dp[len]);
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

#ifdef HOANG_DEBUG
    freopen("input.txt", "r", stdin);
#endif // HOANG_DEBUG

    string T;
    while(cin >> T) {
        if(T[0] == '0') break;
        vector<int> code(T.size(), 0);
        for(int i = 0; i < T.size(); i++) {
            code[i] = static_cast<int>(T[i]-'0');
        }

        solve(code, T.size());
    }

    for(auto r : res) {
        cout << r << "\n";
    }

    return 0;
}
