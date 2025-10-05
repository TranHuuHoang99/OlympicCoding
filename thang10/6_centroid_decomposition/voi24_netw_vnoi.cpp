#include <iostream> 
#include <vector> 
#include <algorithm>
#include <utility>
#include <math.h>
#include <tuple>
const long long mod = 998244353LL;
const int inf = 1000000007; 
int n;
std::vector <std::pair <int, int>> adj[100005]; 
int dist[100005];
int minWeight[100005];
long long ans[100005]; 
bool visited[100005]; 
int size[100005]; 
void dfs_size(int u, int father) {
  size[u] = 1; 
  for (int i = 0; i < (int) adj[u].size(); i++) {
    std::pair <int, int> neighbor = adj[u][i];
    if (neighbor.first == father || visited[neighbor.first] == true) {
      continue; 
    } 
    dfs_size(neighbor.first, u); 
    size[u] += size[neighbor.first]; 
  }
}
int find_centroid(int u, int father, int numbChildren) {
  for (int i = 0; i < (int) adj[u].size(); i++) {
    std::pair <int, int> neighbor = adj[u][i]; 
    if (neighbor.first == father || visited[neighbor.first] == true) {
      continue; 
    }
    if (2 * size[neighbor.first] > numbChildren) {
      return find_centroid(neighbor.first, u, numbChildren); 
    }
  }
  return u; 
}
void dfs_info(int u, int father, std::vector <int> &save) {
  save.push_back(u); 
  for (int i = 0; i < (int) adj[u].size(); i++) {
    std::pair <int, int> neighbor = adj[u][i]; 
    if (neighbor.first == father || visited[neighbor.first] == true) {
      continue; 
    }
    dist[neighbor.first] = dist[u] + 1; 
    minWeight[neighbor.first] = std::min(minWeight[u], neighbor.second); 
    dfs_info(neighbor.first, u, save);
  }
}
long long getRange(int l, int r, const std::vector <long long> &sum) {
  if (l > r) {
    return 0LL; 
  }
  long long ret = sum[r]; 
  ret -= (l == 0 ? 0 : sum[l - 1]); 
  (ret += mod) %= mod; 
  return ret; 
}
void add(long long &a, long long b) {
  (a += b) %= mod; 
}
void subtract(long long &a, long long b) {
  a -= b; 
  (a += mod) %= mod; 
}
void dfs(int u, int father) {
  dist[u] = 0;
  minWeight[u] = inf;
  std::vector <std::vector <int>> listVerticles; 
  for (int i = 0; i < (int) adj[u].size(); i++) {
    std::pair <int, int> neighbor = adj[u][i]; 
    if (neighbor.first == father || visited[neighbor.first] == true) {
      continue; 
    }
    std::vector <int> save;                  
    dist[neighbor.first] = 1;
    minWeight[neighbor.first] = neighbor.second;  
    dfs_info(neighbor.first, u, save);
    listVerticles.push_back(save);
  } 
  std::vector <std::tuple <int, int, int>> info; 
  info.push_back(std::make_tuple(minWeight[u], 0, u)); 
  for (int i = 0; i < (int) listVerticles.size(); i++) {
    std::vector <int> &save = listVerticles[i]; 
    for (int j = 0; j < (int) save.size(); j++) {
      info.push_back(std::make_tuple(minWeight[save[j]], dist[save[j]], save[j])); 
    }
  }
  std::sort(info.begin(), info.end()); 
  int sz = (int) info.size(); 
  std::vector <long long> sumd(sz, 0LL), sumdd(sz, 0LL), summw(sz, 0LL), sumdmw(sz, 0LL), sumddmw(sz, 0LL); 
  for (int i = 0; i < sz; i++) {
    int d = std::get <1>(info[i]); 
    int mw = std::get <0>(info[i]); 
    sumd[i] = ((i == 0 ? 0 : sumd[i - 1]) + d) % mod;
    summw[i] = ((i == 0 ? 0 : summw[i - 1]) + mw) % mod;
    sumdd[i] = ((i == 0 ? 0 : sumdd[i - 1]) + (long long) d * d % mod) % mod;  
    sumdmw[i] = ((i == 0 ? 0 : sumdmw[i - 1]) + (long long) d * mw % mod) % mod; 
    sumddmw[i] = ((i == 0 ? 0 : sumddmw[i - 1]) + ((long long) d * d % mod * mw) % mod) % mod; 
  }
  for (int i = 0; i < sz; i++) {
    int d = std::get <1>(info[i]); 
    int mw = std::get <0>(info[i]); 
    int u = std::get <2>(info[i]); 
    add(ans[u], (long long) (d * d) % mod * getRange(0, i - 1, summw) % mod); 
    add(ans[u], (2LL * d * getRange(0, i - 1, sumdmw)) % mod); 
    add(ans[u], getRange(0, i - 1, sumddmw)); 
    add(ans[u], (long long) (d * d) % mod * mw % mod * (sz - 1 - i) % mod); 
    add(ans[u], (2LL * d * mw) % mod * getRange(i + 1, sz - 1, sumd) % mod); 
    add(ans[u], (long long) mw * getRange(i + 1, sz - 1, sumdd) % mod); 
  }
  for (int i = 0; i < (int) listVerticles.size(); i++) {
    std::vector <int> &save = listVerticles[i]; 
    info.clear(); 
    for (int j = 0; j < (int) save.size(); j++) {
      info.push_back(std::make_tuple(minWeight[save[j]], dist[save[j]], save[j])); 
    }
    std::sort(info.begin(), info.end()); 
    int sz = (int) info.size(); 
    sumd.clear();
    sumdd.clear(); 
    summw.clear(); 
    sumdmw.clear(); 
    sumddmw.clear();
    sumd.resize(sz, 0LL);
    sumdd.resize(sz, 0LL);
    summw.resize(sz, 0LL);
    sumdmw.resize(sz, 0LL);
    sumddmw.resize(sz, 0LL);
    for (int i = 0; i < sz; i++) {
      int d = std::get <1>(info[i]); 
      int mw = std::get <0>(info[i]); 
      sumd[i] = ((i == 0 ? 0 : sumd[i - 1]) + d) % mod;
      summw[i] = ((i == 0 ? 0 : summw[i - 1]) + mw) % mod;
      sumdd[i] = ((i == 0 ? 0 : sumdd[i - 1]) + (long long) d * d % mod) % mod;  
      sumdmw[i] = ((i == 0 ? 0 : sumdmw[i - 1]) + (long long) d * mw % mod) % mod; 
      sumddmw[i] = ((i == 0 ? 0 : sumddmw[i - 1]) + ((long long) d * d % mod * mw) % mod) % mod; 
    }
    for (int i = 0; i < sz; i++) {
      int d = std::get <1>(info[i]); 
      int mw = std::get <0>(info[i]); 
      int u = std::get <2>(info[i]); 
      subtract(ans[u], (long long) (d * d) % mod * getRange(0, i - 1, summw) % mod); 
      subtract(ans[u], (2LL * d * getRange(0, i - 1, sumdmw)) % mod); 
      subtract(ans[u], getRange(0, i - 1, sumddmw)); 
      subtract(ans[u], (long long) (d * d) % mod * mw % mod * (sz - 1 - i) % mod); 
      subtract(ans[u], (2LL * d * mw) % mod * getRange(i + 1, sz - 1, sumd) % mod); 
      subtract(ans[u], (long long) mw * getRange(i + 1, sz - 1, sumdd) % mod); 
    }                                                        
  }
  visited[u] = true; 
  for (int i = 0; i < (int) adj[u].size(); i++) {
    std::pair <int, int> neighbor = adj[u][i]; 
    if (neighbor.first == father || visited[neighbor.first] == true) {
      continue; 
    }
    dfs_size(neighbor.first, -1); 
    int next_centroid = find_centroid(neighbor.first, -1, size[neighbor.first]); 
    dfs(next_centroid, -1); 
  }
}
int main() {
  freopen("netw.inp", "r", stdin);
  freopen("netw.out", "w", stdout); 
  std::cin >> n;
  for (int i = 1; i < n; i++) {
    int u, v, weight;
    std::cin >> u >> v >> weight; 
    adj[u].push_back(std::make_pair(v, weight)); 
    adj[v].push_back(std::make_pair(u, weight));
  }
  dfs_size(1, -1); 
  int centroid = find_centroid(1, -1, n);
  dfs(centroid, -1);  
  for (int i = 1; i <= n; i++) {
    std::cout << ans[i] << std::endl; 
  }
  return 0; 
}