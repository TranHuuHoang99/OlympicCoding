#include <bits/stdc++.h>
#define ll long long

using namespace std;

int n;
vector<int> A;
vector<string> ret_str;
int ret = 0;

void dfs(int i, int curPos) {
    if (i < 0) return;
    if (A[i] == curPos) {
        dfs(i-1, curPos);
    } else {
        dfs(i-1, 3 - curPos - A[i]);
        string from(1, static_cast<char>(A[i]+'A'));
        string to(1, static_cast<char>(curPos+'A'));
        ret_str.push_back(from+to);
        ret++;
        A[i] = curPos;
        dfs(i-1, curPos);
    }
}

void solve(void) {
    cin >> n;
    A.resize(n);
    for (int i = 0; i < n; i++) {
        char temp;
        cin >> temp;
        A[i] = static_cast<int>(temp-'A');
    }

    dfs(n-1, 2);
    cout << ret << endl;
    for (auto str : ret_str) {
        cout << str << endl;
    }
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
