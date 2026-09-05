/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-09-07 07:45:33
**************************************************************************
*/
#include <bits/stdc++.h>
#define int long long
#define pi acos(-1.0)
using namespace std;

const int MOD = 998244353;
const int N = 3e5+10;
int n, k;
int A[N];
vector<int> adj[N];
int dist[N];
int lca[N][25];
map<int,vector<int>> save;
map<int,int> color_lca;
// F[i][j] is the total ways of cutting tree to each subtree
// has it's own color when we have subtree with root node ith,
// and current state 0 if this tree does not have any color
// otherwise this tree will have only one color
int F[N][2];
void dfs_dist(int u, int parent) {
    lca[u][0] = parent;
    for (int v : adj[u]) {
        if (v == parent) continue;
        dist[v] = dist[u] + 1;
        dfs_dist(v, u);
    }
}
int findLca(int u, int v) {
    if (dist[u] < dist[v]) swap(u, v);
    for (int i = 19; i >= 0; i--) {
        if (dist[u] - (1 << i) >= dist[v]) {
            u = lca[u][i];
        }
    }
    if (u == v) return u;
    for (int i = 19; i >= 0; i--) {
        if (lca[u][i] != lca[v][i]) {
            u = lca[u][i];
            v = lca[v][i];
        }
    }
    return lca[u][0];
}
void dfs(int u, int parent) {
    vector<int> child_list;
    for (int v : adj[u]) {
        if (v == parent) continue;
        child_list.push_back(v);
        dfs(v, u);
    }
    if (child_list.empty()) {
        if (A[u] <= 0) {
            // current node has no color and leave node
            F[u][0] = 1;
            F[u][1] = 0;
        } else {
            // current node has color and leave node
            F[u][0] = 0;
            F[u][1] = 1;
        }
        return;
    }
    int numb_child = child_list.size();
    vector<int> pref(numb_child);
    vector<int> suff(numb_child);
    int temp = 1;
    for (int i = 0; i < numb_child; i++) {
        int v = child_list[i];
        // sum of ways to create subtree v with no colors
        // and sum of ways to create subtree v with one colors
        int sum_v = (F[v][0] % MOD + F[v][1] % MOD) % MOD;
        temp = (temp % MOD * sum_v % MOD) % MOD;
        pref[i] = temp;
    }
    temp = 1;
    for (int i = numb_child-1; i >= 0; i--) {
        int v = child_list[i];
        // sum of ways to create subtree v with no color
        // and sum of ways to create subtree v with one color
        int sum_v = (F[v][0] % MOD + F[v][1] % MOD) % MOD;
        temp = (temp % MOD * sum_v % MOD) % MOD;
        suff[i] = temp;
    }
    // if current node already had color
    if (A[u] > 0) {
        F[u][0] = 0;
        // product of (F[v][0] + F[v][1]) (the ways to create subtree v)
        // to make F[u][1] is valid, the subtree v is has no color or has independence color
        // and no pass color up to current node (u)
        F[u][1] = pref[numb_child-1];
    } else {
        // current node has no color
        // case 1 : we calculate F[u][0] (we are going to make this subtree has no color)
        // all child are not allowed to pass color up to this node
        F[u][0] = pref[numb_child-1];
        // case 2 : we calculate F[u][1] (we are going to make this subtree has color)
        // we will receive at lease one color from the child
        F[u][1] = 0;
        for (int i = 0; i < numb_child; i++) {
            int v = child_list[i];
            // get product of other child except v
            int prod_other = 1;
            if (i > 0) {
                prod_other = (prod_other % MOD * pref[i-1] % MOD) % MOD;
            }
            if (i < numb_child-1) {
                prod_other = (prod_other % MOD * suff[i+1] % MOD) % MOD;
            }
            F[u][1] = (F[u][1] % MOD + (F[v][1] % MOD * prod_other % MOD) % MOD) % MOD;
        }
    }
}
void solve(void) {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
        save[A[i]].push_back(i);
    }
    for (int i = 1; i <= n-1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dist[1] = 0;
    dfs_dist(1, 1);
    for (int i = 1; i <= 19; i++) {
        for (int u = 1; u <= n; u++) {
            int middle = lca[u][i-1];
            lca[u][i] = lca[middle][i-1];
        }
    }
    for (pair<int,vector<int>> s : save) {
        if (s.first == 0) continue;
        int common_lca = *s.second.begin();
        for (int i = 1; i < s.second.size(); i++) {
            common_lca = findLca(common_lca, s.second[i]);
        }
        color_lca[s.first] = common_lca;
    }
    for (pair<int,vector<int>> s : save) {
        if (s.first == 0) continue;
        int ancestor = color_lca[s.first];
        for (int u : s.second) {
            int cur = u;
            while (dist[cur] > dist[ancestor]) {
                int next = lca[cur][0];
                if (A[next] == 0) {
                    A[next] = s.first;
                    cur = next;
                } else if (A[next] == s.first) {
                    break;
                } else {
                    cout << 0 << '\n';
                    return;
                }
            }
        }
    }
    for (pair<int,vector<int>> s : save) {
        if (s.first == 0) continue;
        int ancestor = color_lca[s.first];
        if (A[ancestor] != s.first) {
            cout << 0 << '\n';
            return;
        }
    }
    dfs(1, 1);
    cout << F[1][1] % MOD << '\n';
}
signed main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}





