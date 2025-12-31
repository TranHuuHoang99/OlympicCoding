/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2025-10-31 21:44:14
**************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct Node {
    int left, right;
    Node(int _left = 0, int _right = 0) : left(_left), right(_right) {}
    int sum(void) {
        return right - left + 1;
    }
};
const ll N = 2e3+10;
const int INF = 1e8;
int n, m;
int A[N];
int F[N][N][2];
bool cmp(Node a, Node b) {
    if (a.left == b.left) return a.right > b.right;
    return a.left < b.left;
}
void solve(void) {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> A[i];
    vector<Node> save;
    for (int i = 1; i <= m; i++) {
        int left, right;
        cin >> left >> right;
        save.push_back((Node){left, right});
    }
    sort(save.begin(), save.end(), cmp);
    vector<Node> interval;
    interval.push_back((Node){0,0});
    int max_val = 0;
    for (Node s : save) {
        if (s.right > max_val) {
            max_val = s.right;
            interval.push_back(s);
        }
    }
    int len = interval.size()-1;
    for (int i = 0; i <= len+10; i++) {
        for (int j = 0; j <= n; j++) {
            for (int status = 0; status <= 1; status++) {
                F[i][j][status] = -INF;
            }
        }
    }
    F[0][0][0] = F[0][0][1] = 0;
    for (int i = 0; i < len; i++) {
        int cur_right = interval[i].right;
        int left = interval[i+1].left;
        int ins = 0;
        if (cur_right >= left) {
            ins = cur_right - left + 1;
        }
        int seg = interval[i+1].sum();
        for (int j = 0; j <= n; j++) {
            for (int status = 0; status <= 1; status++) {
                if (F[i][j][status] == -INF) continue;
                if (status == 0) {
                    if (j+seg-ins <= n && j+seg-ins >= 0) {
                        // interval hien tai la smaller than x, interval tiep theo la smaller than x
                        F[i+1][j+seg-ins][0] = max(F[i+1][j+seg-ins][0], F[i][j][status]);
                    }
                    if (j-ins >= 0) {
                        // interval hien tai la smaller than x, interval tiep theo la bigger than x
                        F[i+1][j-ins][1] = max(F[i+1][j-ins][1], F[i][j][status] + seg - ins);
                    }
                } else {
                    // interval hien tai la bigger than x, interval tiep theo la bigger than x
                    F[i+1][j][1] = max(F[i+1][j][1], F[i][j][status] + seg - ins);
                    if (j+seg-ins <= n && j+seg-ins >= 0) {
                        // interval hien tai la bigger than x, interval tiep theo la smaller than x
                        F[i+1][j+seg-ins][0] = max(F[i+1][j+seg-ins][0], F[i][j][status] - ins);
                    }
                }
            }
        }
    }
    vector<bool> isInInteval(n+10, false);
    for (Node inter : interval) {
        for (int i = inter.left; i <= inter.right; i++) {
            isInInteval[i] = true;
        }
    }
    int numbFree = 0;
    for (int i = 1; i <= n; i++) {
        if (!isInInteval[i]) numbFree++;
    }
    for (int x = 1; x <= n; x++) {
        int smaller = 0;
        int bigger = 0;
        for (int i = 1; i <= n; i++) {
            if (x > A[i]) {
                smaller++;
            } else if (x < A[i]) {
                bigger++;
            }
        }
        int ans = 0;
        for (int j = 0; j <= n; j++) {
            int smallFree = max(0, smaller-j);
            int bigFree = max(0, bigger - max(F[len][j][0], F[len][j][1]));
            ans |= (numbFree >= smallFree+bigFree);
        }
        cout << ans;
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}








