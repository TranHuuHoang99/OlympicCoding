#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve(void) {
    int N;
    cin >> N;
    vector<pair<int,int>> lands(N, {0,0});

    for(int i = 0; i < N; i++) {
        cin >> lands[i].first >> lands[i].second;
    }

    sort(lands.begin(), lands.end(), [&](pair<int,int> A, pair<int,int> B) -> bool {
        if(A.first > B.first) {
            return true;
        } else if(A.first == B.first) {
            return A.second >= B.second;
        }

        return false;
    });

    auto it = unique(lands.begin(), lands.end(), [](pair<int,int> A, pair<int,int> B) -> bool {
        return A.first == B.first;
    });

    lands.erase(it, lands.end());   

    vector<pair<int,int>> temp;
    for(int i = 0; i < lands.size(); i++) {
        if(i-1 >= 0) {
            if(lands[i].second <= lands[i-1].second) continue;
        }
        temp.push_back(lands[i]);
    }
    
    int len = temp.size();
    vector<int> dp(len+1, INT32_MAX);
    dp[0] = 0;

    for(int i = 1; i <= len; i++) {
        for(int j = 0; j <= i-1; j++) {
            dp[i] = min(dp[i], dp[j] + temp[j].first * temp[i-1].second);
        }
    }

    cout << dp[len] << endl;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

#ifdef HOANG_DEBUG
    freopen("input.txt", "r", stdin);
#endif // HOANG_DEBUG   

    solve();

    return 0;
}
