#include <iostream> 
#include <vector>
#include <math.h>
#include <algorithm>  
#include <utility> 
const long long mod = 10009LL; 
int n, numQueries; 
std::vector <int> adj[100005];
int sz[100005];
int parent[100005];
int f[100005][20];
int height[100005];
int position[100005];
int chainStart[100005];
int chainIndex[100005];
int chain = 1;
std::vector <int> listVertex;    
struct itNode {
  long long sum = 0LL; 
  long long lazy = 0LL; 
  long long sumOfSubtree = 0LL; 
  long long lazyOfSubtree = 0LL; 
  itNode() {
    sum = 0LL; 
    lazy = 0LL; 
    sumOfSubtree = 0LL; 
  }
};
itNode it[4 * 100005]; 
int farthest[100005]; 
long long prefixSum[100005]; 

void init() {
  for (int i = 1; i <= n; i++) {
    chainStart[i] = -1; 
    for (int j = 0; j <= 17; j++) {
      f[i][j] = -1; 
    }
  }
}

void dfs(int u, int father) {
  sz[u] = 1; 
  f[u][0] = father; 
  parent[u] = father; 
  for (int i = 0; i < (int) adj[u].size(); i++) {
    int v = adj[u][i];
    if (v == father) {
      continue; 
    }
    height[v] = height[u] + 1; 
    dfs(v, u); 
    sz[u] += sz[v]; 
  }
}

void initLCA() {
  for (int j = 1; j <= 17; j++) {
    for (int u = 1; u <= n; u++) {
      if (f[u][j - 1] == -1) {
        continue; 
      }
      f[u][j] = f[f[u][j - 1]][j - 1]; 
    }
  }
}

int lca(int u, int v) {
  if (height[u] < height[v]) {
    std::swap(u, v); 
  }
  for (int k = 17; k >= 0; k--) {
    if (height[u] - (1 << k) >= height[v]) {
      u = f[u][k]; 
    }
  }
  if (u == v) {
    return u; 
  }
  for (int k = 17; k >= 0; k--) {
    if (f[u][k] != -1 && f[u][k] != f[v][k]) {
      u = f[u][k];
      v = f[v][k]; 
    }
  }
  return f[u][0]; 
}

void heavyLightDecomposition(int u, int father) {
  if (chainStart[chain] == -1) {
    chainStart[chain] = u; 
  }
  chainIndex[u] = chain; 
  listVertex.push_back(u);
  position[u] = (int) listVertex.size(); 
  int specialVertex = -1; 
  for (int i = 0; i < (int) adj[u].size(); i++) {
    int v = adj[u][i];
    if (v == father) {
      continue; 
    }
    if (specialVertex == -1 || sz[specialVertex] < sz[v]) {
      specialVertex = v; 
    }
  }
  if (specialVertex != -1) {
    heavyLightDecomposition(specialVertex, u); 
  }
  for (int i = 0; i < (int) adj[u].size(); i++) {
    int v = adj[u][i];
    if (v == father) {
      continue; 
    }
    if (v != specialVertex) {
      chain++; 
      heavyLightDecomposition(v, u); 
    }
  }
}

void createFarthest(int u, int father) {
  farthest[u] = position[u]; 
  for (int i = 0; i < (int) adj[u].size(); i++) {
    int v = adj[u][i];
    if (v == father) {
      continue; 
    }
    createFarthest(v, u); 
    farthest[u] = std::max(farthest[u], farthest[v]); 
  }
}

void lazyUpdate(int index, int L, int R) {
  if (it[index].lazy > 0 && L < R) {
    int mid = (L + R) / 2; 
    (it[2 * index].lazy += it[index].lazy) %= mod; 
    (it[2 * index].sum += (1LL * (mid - L + 1) * it[index].lazy) % mod) %= mod; 
    (it[2 * index].sumOfSubtree += (1LL * ((prefixSum[mid] - prefixSum[L - 1] + mod) % mod) * it[index].lazy) % mod) %= mod; 
    (it[2 * index + 1].lazy += it[index].lazy) %= mod; 
    (it[2 * index + 1].sum += (1LL * (R - mid) * it[index].lazy) % mod) %= mod;
    (it[2 * index + 1].sumOfSubtree += (1LL * ((prefixSum[R] - prefixSum[mid] + mod) % mod) * it[index].lazy) % mod) %= mod; 
  }
  it[index].lazy = 0LL; 
}

void update(int index, int L, int R, int l, int r, int cost) {
  if (l > R || L > r) {
    return; 
  }  
  if (l <= L && R <= r) {
    (it[index].lazy += cost) %= mod;
    (it[index].sum += (1LL * (R - L + 1) * cost) % mod) %= mod; 
    (it[index].sumOfSubtree += (1LL * ((prefixSum[R] - prefixSum[L - 1] + mod) % mod) * cost) % mod) %= mod;
    lazyUpdate(index, L, R);
    return;    
  }
  lazyUpdate(index, L, R); 
  int mid = (L + R) / 2; 
  update(2 * index, L, mid, l, r, cost);
  update(2 * index + 1, mid + 1, R, l, r, cost);
  it[index].sum = (it[2 * index].sum + it[2 * index + 1].sum) % mod;
  it[index].sumOfSubtree = (it[2 * index].sumOfSubtree + it[2 * index + 1].sumOfSubtree) % mod;
}

std::pair <long long, long long> get(int index, int L, int R, int l, int r) {
  if (l > R || L > r) {
    return std::make_pair(0LL, 0LL); 
  }
  if (l <= L && R <= r) {
    return std::make_pair(it[index].sum, it[index].sumOfSubtree);   
  }
  lazyUpdate(index, L, R); 
  int mid = (L + R) / 2; 
  std::pair <long long, long long> getLeft = get(2 * index, L, mid, l, r);
  std::pair <long long, long long> getRight = get(2 * index + 1, mid + 1, R, l, r);
  std::pair <long long, long long> ret; 
  ret.first = (getLeft.first + getRight.first) % mod; 
  ret.second = (getLeft.second + getRight.second) % mod; 
  return ret; 
}

void updatePath(int u, int ancestor, int cost) {
  while (chainIndex[u] != chainIndex[ancestor]) {
    int startVertex = chainStart[chainIndex[u]]; 
    update(1, 1, n, position[startVertex], position[u], cost);
    u = startVertex; 
    u = parent[u]; 
  }
  if (u != ancestor) {
    update(1, 1, n, position[ancestor] + 1, position[u], cost); 
  }
}

std::pair <long long, long long> queryPath(int u, int ancestor) {
  std::pair <long long, long long> ret = std::make_pair(0LL, 0LL); 
  while (chainIndex[u] != chainIndex[ancestor]) {
    int startVertex = chainStart[chainIndex[u]]; 
    std::pair <long long, long long> twoSums = get(1, 1, n, position[startVertex], position[u]); 
    (ret.first += twoSums.first) %= mod;
    (ret.second += twoSums.second) %= mod; 
    u = startVertex; 
    u = parent[u]; 
  }
  std::pair <long long, long long> twoSums = get(1, 1, n, position[ancestor], position[u]); 
  (ret.first += twoSums.first) %= mod;
  (ret.second += twoSums.second) %= mod; 
  return ret; 
}

int main () {
  std::cin >> n;
  for (int i = 1; i < n; i++) {
    int u, v;
    std::cin >> u >> v;
    adj[u].push_back(v); 
    adj[v].push_back(u); 
  }
  init(); 
  dfs(1, -1); 
  initLCA(); 
  heavyLightDecomposition(1, -1);
  for (int i = 1; i <= n; i++) {
    prefixSum[i] = (prefixSum[i - 1] + sz[listVertex[i - 1]]) % mod; 
  }
  createFarthest(1, -1);
  std::cin >> numQueries;
  for (int query = 1; query <= numQueries; query++) {
    int type;
    std::cin >> type; 
    if (type == 1) {
      int u, v, cost; 
      std::cin >> u >> v >> cost;
      int ancestor = lca(u, v); 
      updatePath(u, ancestor, cost); 
      updatePath(v, ancestor, cost); 
      update(1, 1, n, position[ancestor], position[ancestor], cost); 
    }
    else {
      int u;
      std::cin >> u;
      long long ret = 0LL;
      std::pair <long long, long long> twoSums = queryPath(u, 1);
      (ret += (1LL * twoSums.first * sz[u]) % mod) %= mod;
      int lastPosition = farthest[u];
      twoSums = get(1, 1, n, position[u] + 1, lastPosition);
      (ret += twoSums.second) %= mod;
      std::cout << ret << std::endl;    
    }
  }
  return 0; 
}