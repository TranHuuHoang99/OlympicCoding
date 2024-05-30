#include <bits/stdc++.h>
#define ll long long

using namespace std;

bool cmp(ll a, ll b) {
    return a > b;
}

void solve(const int N, vector<ll> B, vector<ll> C) {
    sort(B.begin(), B.end());
    sort(C.begin(), C.end(), cmp);

    ll ret = abs(B[0]+C[0]);
    int i = 0, j = 0;
    while(i < N-1 || j < N-1) {
        if(j >= N-1 || (i < N-1 && (B[i]+C[j] < 0))) {
            i++;
        } else {
            j++;
        }

        ret = min(ret, abs(B[i]+C[j]));
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

    int N;
    cin >> N;
    vector<ll> B(N);
    vector<ll> C(N);

    for(int i = 0; i < N; i++) cin >> B[i];

    for(int i = 0; i < N; i++) cin >> C[i];

    solve(N, B, C);

    return 0;
}
