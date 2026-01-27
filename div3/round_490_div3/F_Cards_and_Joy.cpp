/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-01-28 20:07:57
**************************************************************************
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 520;
const int M = 12;
const int LEN = 1e6+10;
int n, m;
int C[LEN];
int A[LEN];
int H[M];
int F[N][N*M]; // F[i][j] is the total happiness when loop through i player, and distributed j cards
void solve(void) {
    cin >> n >> m;
    int len = n*m;
    for (int i = 1; i <= len; i++) {
        int val;
        cin >> val;
        C[val]++; // the number occurance value of the card
    }
    for (int i = 1; i <= n; i++) {
        int val;
        cin >> val;
        A[val]++; // the number of player whose favourite is val
    }
    for (int i = 1; i <= m; i++) cin >> H[i];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= len; j++) {
            for (int k = 0; k <= m; k++) {
                // the current state is: we already have i person, and j was distributed
                // the next state is : we define the next person will receive exact k card of his favourite
                // so the number of card distributed will be raise to j+k
                F[i+1][j+k] = max(F[i+1][j+k], F[i][j] + H[k]);
            }
        }
    }
    int ret = 0;
    for (int i = 0; i <= LEN; i++) {
        // we will loop through every favourite value of each person, due to that value
        // -> the number of cards included in C is C[i]
        if (A[i] != 0) { // case we have player's favourite number exist
            ret += F[A[i]][C[i]];
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





