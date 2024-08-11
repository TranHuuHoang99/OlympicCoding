#include <bits/stdc++.h>
#define ll long long

#ifdef HOANG_DEBUG
#include <time.h>
#include <stdio.h>
 
double time1, timedif;
#endif // HOANG_DEBUG

using namespace std;

const int N = 8;
int n;
int D[N][N][N];
int memo_min[N][1<<N][N][1<<N];
int memo_max[N][1<<N][N][1<<N];

int recur_min(int mask, int mask_t, int u, int t) {
    if (mask == ((1<<n)-1)) {
        return D[t][u][0];
    }

    if (memo_min[u][mask][t][mask_t] != -1) {
        return memo_min[u][mask][t][mask_t];
    }

    int ret = INT_MAX;
    for (int v = 0; v < n; v++) {
        if (!(mask & (1 << v)) && D[t][u][v] > 0) {
            for (int k = 0; k < n; k++) {
                if (!(mask_t & (1 << k)) && D[k][u][v] > 0) {
                    int cur = D[t][u][v];
                    int next = recur_min(mask | (1 << v), mask_t | (1 << k), v, k);
                    if (next > 0) {
                        ret = min(ret, cur+next);
                    }
                }
            }
        }
    }

    if (ret != INT_MAX) {
        memo_min[u][mask][t][mask_t] = ret;
    }

    return memo_min[u][mask][t][mask_t];
}

int recur_max(int mask, int mask_t, int u, int t) {
    if (mask == ((1<<n)-1)) {
        return D[t][u][0];
    }

    if (memo_max[u][mask][t][mask_t] != -1) {
        return memo_max[u][mask][t][mask_t];
    }

    int ret = INT_MIN;
    for (int v = 0; v < n; v++) {
        if (!(mask & (1 << v)) && D[t][u][v] > 0) {
            for (int k = 0; k < n; k++) {
                if (!(mask_t & (1 << k)) && D[k][u][v] > 0) {
                    int cur = D[t][u][v];
                    int next = recur_max(mask | (1 << v), mask_t | (1 << k), v, k);
                    if (next > 0) {
                        ret = max(ret, cur+next);
                    }
                }
            }
        }
    }
    
    if (ret != INT_MIN) {
        memo_max[u][mask][t][mask_t] = ret;
    }

    return memo_max[u][mask][t][mask_t];
}

void solve(void) {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                cin >> D[i][j][k];
            }
        }
    }

    memset(memo_min, -1, sizeof(memo_min));
    memset(memo_max, -1, sizeof(memo_max));
    
    int ret_min = INT_MAX, ret_max = INT_MIN;
    for (int i = 0; i < n; i++) {
        int mask_t = (1 << i);
        ret_min = min(ret_min, recur_min(1, mask_t, 0, i));
        ret_max = max(ret_max, recur_max(1, mask_t, 0, i));
    }

    if (ret_min == -1 || ret_max == -1) {
        cout << 0 << ' ' << 0 << endl;
        return;
    }
    
    cout << ret_min << ' ' << ret_max << endl;
}


int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

#ifdef HOANG_DEBUG
	freopen("input.txt", "r", stdin);
    time1 = (double)clock();
    time1 = time1 / CLOCKS_PER_SEC; 
#endif //HOANG_DEBUG

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

#ifdef HOANG_DEBUG
    timedif = ( ((double) clock()) / CLOCKS_PER_SEC) - time1;
    printf("The elapsed time is %lf seconds\n", timedif);
#endif //HOANG_DEBUG


    return 0;
}
