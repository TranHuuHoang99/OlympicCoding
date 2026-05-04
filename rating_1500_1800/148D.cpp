/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-05-04 21:05:08
**************************************************************************
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e3+10;
int n, m;
double F[N][N];
void solve(void) {
    cin >> n >> m;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            F[i][j] = 0.0f;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (j == 0) {
                F[i][j] = 1.0f;
                continue;
            }
            // case princess draw a white mouse on her first turn
            F[i][j] = (double)i / (i+j) * 1.0f;
            // case pricess draw a black mouse on her first turn
            // and dragon draw a black mouse on it's turn as well
            if (j >= 2) { // 2 black mouse were drawn
                // prop of princess draw black mouse
                double prop_princess = (double)j/(i+j);
                // prop of dragon draw black mouse
                // because princess took one black mouse so j-1 black mouse left
                double prop_dragon = (double)(j-1)/(i+j-1);
                double prop_both_black = prop_princess * prop_dragon;
                // because princess and dragon drew 2 black mouse so the mouse left is i+j-2
                int remain = i+j-2;
                if (remain > 0) {
                    // after dragon draw mouse, one of the rest of mouses will escape
                    // case escape mouse is white from the rest
                    if (i >= 2) {
                        F[i][j] += prop_both_black * (double)i/remain * F[i-1][j-2];
                    }
                    // case escape mouse is black from the rest
                    if (j >= 3) {
                        F[i][j] += prop_both_black * (double)(j-2)/remain * F[i][j-3];
                    }
                }
            }
        }
    }
    cout << fixed << setprecision(9) << F[n][m] << endl;
}
signed main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}





