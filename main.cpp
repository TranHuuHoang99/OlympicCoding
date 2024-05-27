#include <bits/stdc++.h>

#define ll long long
using namespace std;

int N, M, X;
vector<vector<int>> matrix;
int ans = INT32_MAX;

bool isValid(vector<int> temp) {    
    for(int i = 1; i <= M; i++) {
        if(temp[i] < X) return false; 
    }
    return true;
}

void solve(vector<int> temp, int count, int index) {
    if(isValid(temp)) ans = min(ans, count);
    if(index >= N) return;

    solve(temp, count, index+1);
    for(int i = 1; i <= M; i++) temp[i] += matrix[index][i];
    solve(temp, count+matrix[index][0], index+1);
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

#ifdef HOANG_DEBUG
    freopen("input.txt", "r", stdin);
#endif //HOANG_DEBUG

    cin >> N >> M >> X;
    matrix.assign(N, vector<int>(M+1, 0));

    for(int i = 0; i < N; i++) {
        for(int j = 0; j <= M; j++) {
            cin >> matrix[i][j];
        }
    }

    vector<int> temp(M+1, 0);

    solve(temp, 0, 0);
    if(ans == INT32_MAX) {
        cout << -1 << endl;
        return 0;
    }

    cout << ans << endl;

    return 0;
}