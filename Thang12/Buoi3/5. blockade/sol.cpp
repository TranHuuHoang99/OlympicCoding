#include <bits/stdc++.h>
using namespace std;

struct Dinic {
  struct Edge {
    int to, rev, cap;
  };
  int n, s, t;
  vector<vector<Edge>> g;
  vector<int> level, it, q;
  Dinic(int n, int s, int t) : n(n), s(s), t(t) {
    g.assign(n, {});
    level.resize(n);
    it.resize(n);
    q.resize(n);
  }
  void reserve_by_degree(const vector<int>& deg) {
    for (int i = 0; i < n; i++) {
      g[i].reserve(deg[i]);
    }
  }
  void add_edge(int u, int v, int c) {
    Edge a{v, (int)g[v].size(), c};
    Edge b{u, (int)g[u].size(), 0};
    g[u].push_back(a);
    g[v].push_back(b);
  }
  bool bfs() {
    fill(level.begin(), level.end(), -1);
    int head = 0, tail = 0;
    level[s] = 0;
    q[tail++] = s;
    while (head < tail) {
      int u = q[head++];
      for (auto &e : g[u]) {
        if (e.cap == 0) continue;
        if (level[e.to] != -1) continue;
        level[e.to] = level[u] + 1;
        q[tail++] = e.to;
      }
    }
    return level[t] != -1;
  }
  int dfs(int u, int pushed) {
    if (pushed == 0) return 0;
    if (u == t) return pushed;
    for (int &i = it[u]; i < (int)g[u].size(); i++) {
      Edge &e = g[u][i];
      if (e.cap == 0) continue;
      if (level[e.to] != level[u] + 1) continue;
      int tr = dfs(e.to, min(pushed, e.cap));
      if (tr == 0) continue;
      e.cap -= tr;
      g[e.to][e.rev].cap += tr;
      return tr;
    }
    return 0;
  }
  long long flow() {
    long long f = 0;
    while (bfs()) {
      fill(it.begin(), it.end(), 0);
      while (true) {
        int pushed = dfs(s, INT_MAX);
        if (pushed == 0) break;
        f += pushed;
      }
    }
    return f;
  }
};

int n, m, k;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int numTest;
  if (!(cin >> numTest)) return 0;
  while (numTest--) {
    cin >> n >> m >> k;
    vector<int> U(m), V(m);
    for (int i = 0; i < m; i++) {
      cin >> U[i] >> V[i];
    }
    vector<char> choose(m, 0);
    vector<int> cnt(n + 1, 0);
    cnt[1]++;
    cnt[n]++;
    for (int i = 0; i < k; i++) {
      int id;
      cin >> id;
      id--;
      choose[id] = 1;
      cnt[U[id]]++;
      cnt[V[id]]++;
    }
    int maxCnt = -1;
    for (int i = 1; i <= n; i++) {
      if (cnt[i] > maxCnt) maxCnt = cnt[i];
    }
    if (maxCnt > 2) {
      cout << -1 << '\n';
      continue;
    }
    int source = 0, sink = n + 1;
    Dinic D(n + 2, source, sink);
    vector<int> deg(n + 2, 0);
    for (int i = 0; i < m; i++) {
      if (choose[i]) continue;
      int u = U[i];
      int v = V[i];
      if (cnt[u] == 2) u = source;
      if (cnt[v] == 2) v = sink;
      deg[u]++;
      deg[v]++;
    }
    D.reserve_by_degree(deg);
    for (int i = 0; i < m; i++) {
      if (choose[i]) continue;
      int u = U[i];
      int v = V[i];
      if (cnt[u] == 2) u = source;
      if (cnt[v] == 2) v = sink;
      D.add_edge(u, v, 1);
    }
    cout << D.flow() << '\n';
  }
  return 0;
}