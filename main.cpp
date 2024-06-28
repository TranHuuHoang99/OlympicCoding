#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve(void) {
    int N;
    cin >> N;
    vector<int> A(N,0);
    for (int i = 0; i < N; i++) cin >> A[i];
    vector<int> temp(1e5+1, 1);
    int j = 0;
    for (int i = 1; i < N; i++) {
        if (A[i] == A[i-1]) {
            temp[j]++;
        } else {
            j++;
        }
    }
    int ret = 0;
    for (int i = 1; i <= j; i++) {
        if (temp[i] == temp[i-1]) {
            ret = max(ret, temp[i]*2);
        } else if (temp[i] > temp[i-1]) {
            ret = max(ret, temp[i-1]*2);
        } else {
            ret = max(ret, temp[i]*2);
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

    solve();

    return 0;
}
