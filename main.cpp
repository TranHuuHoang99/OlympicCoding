#include <bits/stdc++.h>
#define ll long long

using namespace std;

int n;
vector<int> A;
const int alphabet = (1<<26)-1;
int ret = 0;

void dfs(int i, int val) {
    if (val == alphabet) {
        int temp = n-i;
        ret += (1<<temp);
        return;
    }
    if (i >= n) {
        if (val == alphabet) ret++;
        return;
    }

    dfs(i+1, val);
    dfs(i+1, val | A[i]);
}

void solve(void) {
    cin >> n;
    A.assign(n, 0);
    string temp;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        for (auto t : temp) {
            A[i] |= (1<<(t-'a'));
        }
    }

    dfs(0, 0);

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
