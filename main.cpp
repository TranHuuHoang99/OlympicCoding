#include <bits/stdc++.h>
#define ll long long

using namespace std;

int M,N,K;

vector<vector<vector<int>>> matrix;

bool isValid(int xA, int yA, int xB, int yB) {
    int count = 0;
    for(int i = 0; i < 26; i++) {
        count += (matrix[yA][yB][i]+matrix[xA-1][xB-1][i]-matrix[xA-1][yB][i]-matrix[yA][xB-1][i] > 0);
    }
    
    if(count == K) return true;
    return false;
}

void solve(void) {
    int ret = 0;
    for(int i = M; i >= 1; i--) {
        for(int j = 1; j <= M-i+1; j++) {
            for(int k = N; k >= 1; k--) {
                if(i*k < K) break;
                for(int l = 1; l <= N-k+1; l++) {
                    if(isValid(j, i+j-1, l, k+l-1)) {
                        ret++;
                    }
                }
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
    
    cin >> M >> N >> K;
    matrix.assign(M+1, vector<vector<int>>(N+1, vector<int>(26,0)));
    for(int i = 1; i <= M; i++) {
        for(int j = 1; j <= N; j++) {
            char temp;
            cin >> temp;
            temp -= 'A';
            matrix[i][j][(int)temp] = 1;
            for(int k = 0; k < 26; k++) {
                matrix[i][j][k] += (matrix[i-1][j][k]+matrix[i][j-1][k]-matrix[i-1][j-1][k]);
            }
        }
    }

    solve();

    return 0;
}
