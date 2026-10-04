/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-10-06 13:49:46
**************************************************************************
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5+10;
const int M = 1e6+10;
int n;
vector<int> card_arr[N][5];
/*
    call F[i][j] is the maximum damage we could make after first i'th turn and j is the remain of
    the total number of cards modulo for 10 that we played during i'th first turns
*/
int F[N][12];
void solve(void) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int m;
        cin >> m;
        priority_queue<int, vector<int>, less<int>> pq;
        for (int j = 1; j <= m; j++) {
            int c, d;
            cin >> c >> d;
            if (c == 1) {
                pq.push(d);
            } else {
                if (card_arr[i][c].empty()) {
                    card_arr[i][c].push_back(d);
                } else {
                    card_arr[i][c][0] = max(card_arr[i][c][0], d);
                }
            }
        }
        int cnt = 0;
        while (!pq.empty() && cnt++ < 3) {
            card_arr[i][1].push_back(pq.top());
            pq.pop();
        }
    }
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= 9; j++) {
            F[i][j] = LLONG_MIN;
        }
    }
    F[0][0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= 9; j++) {
            if (F[i][j] == LLONG_MIN) continue;
            // if we decide not to play any card in (i+1)'th turn
            F[i+1][j] = max(F[i+1][j], F[i][j]);
            /*
                case we play only 1 card in turn (i+1)'th
            */
            if (card_arr[i+1][1].size() >= 1) {
                int n_rem = (j+1) % 10;
                int n_damage = card_arr[i+1][1][0];
                if (n_rem == 0) n_damage *= 2;
                F[i+1][n_rem] = max(F[i+1][n_rem], F[i][j] + n_damage);
            }
            if (card_arr[i+1][2].size() >= 1) {
                int n_rem = (j+1) % 10;
                int n_damage = card_arr[i+1][2][0];
                if (n_rem == 0) n_damage *= 2;
                F[i+1][n_rem] = max(F[i+1][n_rem], F[i][j] + n_damage);
            }
            if (card_arr[i+1][3].size() >= 1) {
                int n_rem = (j+1) % 10;
                int n_damage = card_arr[i+1][3][0];
                if (n_rem == 0) n_damage *= 2;
                F[i+1][n_rem] = max(F[i+1][n_rem], F[i][j] + n_damage);
            }
            /*
                case we play 2 cards in turn (i+1)'th
            */
            if (card_arr[i+1][1].size() >= 2) {
                int n_first_rem = (j+1) % 10;
                int n_first_damage = card_arr[i+1][1][0];
                int n_second_rem = (n_first_rem + 1) % 10;
                int n_second_damage = card_arr[i+1][1][1];
                if (n_first_rem == 0 || n_second_rem == 0) n_first_damage *= 2;
                int n_total_damage = n_first_damage + n_second_damage;
                F[i+1][n_second_rem] = max(F[i+1][n_second_rem], F[i][j] + n_total_damage);
            }
            if (card_arr[i+1][1].size() >= 1 && card_arr[i+1][2].size() >= 1) {
                int n_first_damage = card_arr[i+1][1][0];
                int n_second_damage = card_arr[i+1][2][0];
                if (n_first_damage < n_second_damage) swap(n_first_damage, n_second_damage);
                int n_first_rem = (j+1) % 10;
                int n_second_rem = (n_first_rem+1) % 10;
                if (n_first_rem == 0 || n_second_rem == 0) n_first_damage *= 2;
                int n_total_damage = n_first_damage + n_second_damage;
                F[i+1][n_second_rem] = max(F[i+1][n_second_rem], F[i][j] + n_total_damage);
            }
            /*
                case we play 3 cards in turn (i+1)'th
            */
            if (card_arr[i+1][1].size() >= 3) {
                int n_first_rem = (j+1) % 10;
                int n_second_rem = (n_first_rem+1) % 10;
                int n_third_rem = (n_second_rem+1) % 10;
                int n_first_damage = card_arr[i+1][1][0];
                int n_second_damage = card_arr[i+1][1][1];
                int n_third_damage = card_arr[i+1][1][2];
                if (n_first_rem == 0 || n_second_rem == 0 || n_third_rem == 0) n_first_damage *= 2;
                int n_total_damage = n_first_damage + n_second_damage + n_third_damage;
                F[i+1][n_third_rem] = max(F[i+1][n_third_rem], F[i][j] + n_total_damage);
            }
        }
    }
    int ret = LLONG_MIN;
    for (int j = 0; j <= 9; j++) {
        ret = max(ret, F[n][j]);
    }
    cout << ret << '\n';
}
signed main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}






