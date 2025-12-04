#include <iostream>
#include <vector>
#include <math.h> 
#include <utility> 
const long long inf = 1000000000000000007LL; 
int n; 
long long f_out[200005], f_in[200005]; 
std::vector <std::pair <int, int>> adj[200005];
std::vector <long long> prefix[200005], suffix[200005]; 
long long x[200005], y[200005], z[200005];
long long c[200005];
std::vector <std::pair <int, int>> child[200005]; 
long long ans = -inf; 
void dfs_out(int u, int father) {
  for (int i = 0; i < (int) adj[u].size(); i++) {
    std::pair <int, int> neighbor = adj[u][i];
    if (neighbor.first == father) {
      continue;
    }
    child[u].push_back(neighbor); 
    dfs_out(neighbor.first, u); 
    f_out[u] = std::max(f_out[u], f_out[neighbor.first] + neighbor.second);       
  }
  f_out[u] = std::max(f_out[u], c[u]);
  int sz = (int) child[u].size(); 
  prefix[u].resize(sz + 2, -inf); 
  suffix[u].resize(sz + 2, -inf); 
  for (int i = 1; i <= sz; i++) {
    int v = child[u][i - 1].first; 
    prefix[u][i] = std::max(prefix[u][i - 1], f_out[v] + child[u][i - 1].second);   
  }  
  for (int i = sz; i >= 1; i--) {
    int v = child[u][i - 1].first; 
    suffix[u][i] = std::max(suffix[u][i + 1], f_out[v] + child[u][i - 1].second); 
  }
}
void dfs_in(int u, int father) {
  f_in[u] = std::max(f_in[u], c[u]); 
  for (int i = 0; i < (int) child[u].size(); i++) {
    std::pair <int, int> pr = child[u][i];
    int v = pr.first;
    int weight = pr.second;
    int id = i + 1;
    f_in[v] = std::max(f_in[u], std::max(prefix[u][id - 1], suffix[u][id + 1])) + pr.second;
    ans = std::max(ans, std::max(f_out[v], f_in[v]) - c[v]); 
    dfs_in(v, u);  
  }  
}
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin >> n;
  for (int i = 1; i < n; i++) {
    int u, v, weight;
    std::cin >> u >> v >> weight; 
    adj[u].push_back(std::make_pair(v, weight));
    adj[v].push_back(std::make_pair(u, weight));
  }
  for (int i = 1; i <= n; i++) {
    std::cin >> x[i] >> y[i] >> z[i]; 
  }
  for (int mask = 0; mask < 8; mask++) {
    for (int u = 1; u <= n; u++) {
      f_out[u] = -inf;
      f_in[u] = -inf; 
      prefix[u].clear(); 
      suffix[u].clear(); 
      child[u].clear(); 
      c[u] = 0LL;
      for (int i = 0; i < 3; i++) {
        int bit = ((mask & (1 << i)) > 0);
        long long v = x[u];
        if (i == 1) {
          v = y[u];
        }
        else if (i == 2) {
          v = z[u];
        }
        c[u] += (long long) (bit == 0 ? -1 : 1) * v; 
      }
    }
    dfs_out(1, -1);
    ans = std::max(ans, f_out[1] - c[1]);
    dfs_in(1, -1);  
  }
  std::cout << ans;
  return 0; 
}