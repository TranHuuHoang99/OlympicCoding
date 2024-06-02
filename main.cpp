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

    int N;
    ll X;
    cin >> N >> X;
    vector<ll> A(N);

    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    int i = 0, j = N-1;

    while(i < j) {
        ll sum = A[i] + A[j];
        if(sum > X) {
            j--;
        } else if(sum < X) {
            i++;
        } else {
            cout << i+1 << " " << j+1 << endl;
            return 0;
        }
    }

    cout << "No solution" << endl;

    return 0;
}
