#include <bits/stdc++.h>
#define ll long long

using namespace std;
  
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
#ifdef HOANG_DEBUG
    freopen("input.txt", "r", stdin);
#endif // HOANG_DEBUG

    int ret = 0;
    int N, M;
    vector<ll> A, B;
    cin >> N;
    A.resize(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }
    cin >> M;
    B.resize(M);
    for(int i = 0; i < M; i++) {
        cin >> B[i];
    }

    int i = 0, j = 0;
    ll sum1 = A[i++], sum2 = B[j++];
    
    while(i < N || j < M) {
        if(j >= M || (i < N && sum1 < sum2)) {
            sum1 += A[i++];
        } else {
            if(sum1 == sum2) {
                ret++;
                sum1 += A[i++];
            }
            sum2 += B[j++];
        }
    }

    if(sum1 == sum2) {
        cout << ret+1 << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}
