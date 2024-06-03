#include <bits/stdc++.h>
#define ll long long

using namespace std;

int N, M;
vector<int> A;
vector<pair<int,int>> P(3*1e5);
int ret = INT32_MIN;

void solve(void) {
    for(int i = 1; i <= N; i++) {
        for(int j = i+1; j <= N; j++) {
            P[A[i]+A[j]] = {i,j};
        }
    }

    for(int i = 1; i <= N; i++) {
        for(int j = M-A[i]; j >= 0; j--) {
            if(P[j] != pair<int,int>(0,0) && P[j].first != i && P[j].second != i) {
                ret = max(ret, j+A[i]);
                break;
            }
        }
    }

    cout << ret << endl;
}
  
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
#ifdef HOANG_DEBUG
    freopen("input.txt", "r", stdin);
#endif // HOANG_DEBUG

    cin >> N >> M;
    A.resize(N+1);

    for(int i = 1; i <= N; i++) {
        cin >> A[i];
    }

    solve();

    return 0;
}
